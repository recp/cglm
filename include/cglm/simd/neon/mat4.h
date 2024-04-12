/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat4_neon_h
#define cglm_mat4_neon_h
#if defined(CGLM_NEON_FP)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat4_scale_neon(mat4 m, float s) {
  float32x4_t v0;
  
  v0 = vdupq_n_f32(s);

  vst1q_f32(m[0], vmulq_f32(vld1q_f32(m[0]), v0));
  vst1q_f32(m[1], vmulq_f32(vld1q_f32(m[1]), v0));
  vst1q_f32(m[2], vmulq_f32(vld1q_f32(m[2]), v0));
  vst1q_f32(m[3], vmulq_f32(vld1q_f32(m[3]), v0));
}

CGLM_INLINE
void
glm_mat4_transp_neon(mat4 m, mat4 dest) {
  float32x4x4_t vmat;
  
  vmat = vld4q_f32(m[0]);

  vst1q_f32(dest[0], vmat.val[0]);
  vst1q_f32(dest[1], vmat.val[1]);
  vst1q_f32(dest[2], vmat.val[2]);
  vst1q_f32(dest[3], vmat.val[3]);
}

CGLM_INLINE
void
glm_mat4_mul_neon(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  glmm_128 l, r0, r1, r2, r3, v0, v1, v2, v3;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);
  r3 = glmm_load(m2[3]);

  v0 = vmulq_f32(glmm_splat_x(r0), l);
  v1 = vmulq_f32(glmm_splat_x(r1), l);
  v2 = vmulq_f32(glmm_splat_x(r2), l);
  v3 = vmulq_f32(glmm_splat_x(r3), l);

  l  = glmm_load(m1[1]);
  v0 = glmm_fmadd(glmm_splat_y(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_y(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_y(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_y(r3), l, v3);

  l  = glmm_load(m1[2]);
  v0 = glmm_fmadd(glmm_splat_z(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_z(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_z(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_z(r3), l, v3);

  l  = glmm_load(m1[3]);
  v0 = glmm_fmadd(glmm_splat_w(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_w(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_w(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_w(r3), l, v3);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], v3);
}

CGLM_INLINE
void
glm_mat4_mulv_neon(mat4 m, vec4 v, vec4 dest) {
  float32x4_t l0, l1, l2, l3;
  float32x2_t vlo, vhi;
  
  l0  = vld1q_f32(m[0]);
  l1  = vld1q_f32(m[1]);
  l2  = vld1q_f32(m[2]);
  l3  = vld1q_f32(m[3]);

  vlo = vld1_f32(&v[0]);
  vhi = vld1_f32(&v[2]);

  l0  = vmulq_lane_f32(l0, vlo, 0);
  l0  = vmlaq_lane_f32(l0, l1, vlo, 1);
  l0  = vmlaq_lane_f32(l0, l2, vhi, 0);
  l0  = vmlaq_lane_f32(l0, l3, vhi, 1);

  vst1q_f32(dest, l0);
}

CGLM_INLINE
float
glm_mat4_det_neon(mat4 mat) {
  float32x4_t   r0, r1, r2, r3, x0, x1, x2;
  float32x2_t   ij, op, mn, kl, nn, mm, jj, ii, gh, ef, t12, t34;
  float32x4x2_t a1;
  float32x4_t   x3 = glmm_float32x4_SIGNMASK_PNPN;

  /* 127 <- 0, [square] det(A) = det(At) */
  r0 = glmm_load(mat[0]);              /* d c b a */
  r1 = vrev64q_f32(glmm_load(mat[1])); /* g h e f */
  r2 = vrev64q_f32(glmm_load(mat[2])); /* l k i j */
  r3 = vrev64q_f32(glmm_load(mat[3])); /* o p m n */

  gh = vget_high_f32(r1);
  ef = vget_low_f32(r1);
  kl = vget_high_f32(r2);
  ij = vget_low_f32(r2);
  op = vget_high_f32(r3);
  mn = vget_low_f32(r3);
  mm = vdup_lane_f32(mn, 1);
  nn = vdup_lane_f32(mn, 0);
  ii = vdup_lane_f32(ij, 1);
  jj = vdup_lane_f32(ij, 0);
  
  /*
   t[1] = j * p - n * l;
   t[2] = j * o - n * k;
   t[3] = i * p - m * l;
   t[4] = i * o - m * k;
   */
  x0 = glmm_fnmadd(vcombine_f32(kl, kl), vcombine_f32(nn, mm),
                   vmulq_f32(vcombine_f32(op, op), vcombine_f32(jj, ii)));

  t12 = vget_low_f32(x0);
  t34 = vget_high_f32(x0);
  
  /* 1 3 1 3 2 4 2 4 */
  a1 = vuzpq_f32(x0, x0);
  
  /*
   t[0] = k * p - o * l;
   t[0] = k * p - o * l;
   t[5] = i * n - m * j;
   t[5] = i * n - m * j;
   */
  x1 = glmm_fnmadd(vcombine_f32(vdup_lane_f32(kl, 0), jj),
                   vcombine_f32(vdup_lane_f32(op, 1), mm),
                   vmulq_f32(vcombine_f32(vdup_lane_f32(op, 0), nn),
                             vcombine_f32(vdup_lane_f32(kl, 1), ii)));

  /*
     a * (f * t[0] - g * t[1] + h * t[2])
   - b * (e * t[0] - g * t[3] + h * t[4])
   + c * (e * t[1] - f * t[3] + h * t[5])
   - d * (e * t[2] - f * t[4] + g * t[5])
   */
  x2 = glmm_fnmadd(vcombine_f32(vdup_lane_f32(gh, 1), vdup_lane_f32(ef, 0)),
                   vcombine_f32(vget_low_f32(a1.val[0]), t34),
                   vmulq_f32(vcombine_f32(ef, vdup_lane_f32(ef, 1)),
                             vcombine_f32(vget_low_f32(x1), t12)));

  x2 = glmm_fmadd(vcombine_f32(vdup_lane_f32(gh, 0), gh),
                  vcombine_f32(vget_low_f32(a1.val[1]), vget_high_f32(x1)), x2);

  x2 = glmm_xor(x2, x3);

  return glmm_hadd(vmulq_f32(x2, r0));
}

/* old one */
#if 0
CGLM_INLINE
void
glm_mat4_inv_neon(mat4 mat, mat4 dest) {
  float32x4_t   r0, r1, r2, r3,
                v0, v1, v2, v3,
                t0, t1, t2, t3, t4, t5,
                x0, x1, x2, x3, x4, x5, x6, x7, x8;
  float32x4x2_t a1;
  float32x2_t   lp, ko, hg, jn, im, fe, ae, bf, cg, dh;
  float32x4_t   x9 = glmm_float32x4_SIGNMASK_NPNP;

  x8 = vrev64q_f32(x9);

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */
  
  /* l p k o, j n i m */
  a1  = vzipq_f32(r3, r2);
  
  jn  = vget_high_f32(a1.val[0]);
  im  = vget_low_f32(a1.val[0]);
  lp  = vget_high_f32(a1.val[1]);
  ko  = vget_low_f32(a1.val[1]);
  hg  = vget_high_f32(r1);

  x1  = vcombine_f32(vdup_lane_f32(lp, 0), lp);                   /* l p p p */
  x2  = vcombine_f32(vdup_lane_f32(ko, 0), ko);                   /* k o o o */
  x0  = vcombine_f32(vdup_lane_f32(lp, 1), vdup_lane_f32(hg, 1)); /* h h l l */
  x3  = vcombine_f32(vdup_lane_f32(ko, 1), vdup_lane_f32(hg, 0)); /* g g k k */
  
  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = glmm_fnmadd(x2, x0, vmulq_f32(x3, x1));

  fe = vget_low_f32(r1);
  x4 = vcombine_f32(vdup_lane_f32(jn, 0), jn);                   /* j n n n */
  x5 = vcombine_f32(vdup_lane_f32(jn, 1), vdup_lane_f32(fe, 1)); /* f f j j */
  
  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
   t1 = glmm_fnmadd(x4, x0, vmulq_f32(x5, x1));
  
  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = glmm_fnmadd(x4, x3, vmulq_f32(x5, x2));
  
  x6 = vcombine_f32(vdup_lane_f32(im, 1), vdup_lane_f32(fe, 0)); /* e e i i */
  x7 = vcombine_f32(vdup_lane_f32(im, 0), im);                   /* i m m m */
  
  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = glmm_fnmadd(x7, x0, vmulq_f32(x6, x1));
  
  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = glmm_fnmadd(x7, x3, vmulq_f32(x6, x2));
  
  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = glmm_fnmadd(x7, x5, vmulq_f32(x6, x4));
  
  /* h d f b, g c e a */
  a1 = vtrnq_f32(r0, r1);
  
  x4 = vrev64q_f32(a1.val[0]); /* c g a e */
  x5 = vrev64q_f32(a1.val[1]); /* d h b f */

  ae = vget_low_f32(x4);
  cg = vget_high_f32(x4);
  bf = vget_low_f32(x5);
  dh = vget_high_f32(x5);
  
  x0 = vcombine_f32(ae, vdup_lane_f32(ae, 1)); /* a a a e */
  x1 = vcombine_f32(bf, vdup_lane_f32(bf, 1)); /* b b b f */
  x2 = vcombine_f32(cg, vdup_lane_f32(cg, 1)); /* c c c g */
  x3 = vcombine_f32(dh, vdup_lane_f32(dh, 1)); /* d d d h */
  
  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = glmm_xor(glmm_fmadd(x3, t2, glmm_fnmadd(x2, t1, vmulq_f32(x1, t0))), x8);
  
  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = glmm_xor(glmm_fmadd(x3, t5, glmm_fnmadd(x1, t3, vmulq_f32(x0, t1))), x8);

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = glmm_xor(glmm_fmadd(x3, t4, glmm_fnmadd(x2, t3, vmulq_f32(x0, t0))), x9);
  
  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = glmm_xor(glmm_fmadd(x2, t5, glmm_fnmadd(x1, t4, vmulq_f32(x0, t2))), x9);

  /* determinant */
  x0 = vcombine_f32(vget_low_f32(vzipq_f32(v0, v1).val[0]),
                    vget_low_f32(vzipq_f32(v2, v3).val[0]));

  /*
  x0 = glmm_div(glmm_set1_rval(1.0f), glmm_vhadd(vmulq_f32(x0, r0)));

  glmm_store(dest[0], vmulq_f32(v0, x0));
  glmm_store(dest[1], vmulq_f32(v1, x0));
  glmm_store(dest[2], vmulq_f32(v2, x0));
  glmm_store(dest[3], vmulq_f32(v3, x0));
  */

  x0 = glmm_vhadd(vmulq_f32(x0, r0));

  glmm_store(dest[0], glmm_div(v0, x0));
  glmm_store(dest[1], glmm_div(v1, x0));
  glmm_store(dest[2], glmm_div(v2, x0));
  glmm_store(dest[3], glmm_div(v3, x0));
}
#endif

CGLM_INLINE
void
glm_mat4_inv_neon(mat4 mat, mat4 dest) {
  float32x4_t   r0, r1, r2, r3,
                v0, v1, v2, v3, v4, v5,
                t0, t1, t2;
  float32x4x2_t a0, a1, a2, a3, a4;
  float32x4_t   s1 = glmm_float32x4_SIGNMASK_PNPN, s2;

#if !CGLM_ARM64
  float32x2_t   l0, l1;
#endif

  s2 = vrev64q_f32(s1);

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]);                  /* d c b a */
  r1 = glmm_load(mat[1]);                  /* h g f e */
  r2 = glmm_load(mat[2]);                  /* l k j i */
  r3 = glmm_load(mat[3]);                  /* p o n m */

  a1 = vzipq_f32(r0, r2);                  /* l d k c, j b i a */
  a2 = vzipq_f32(r1, r3);                  /* p h o g, n f m e */
  a3 = vzipq_f32(a2.val[0], a1.val[0]);    /* j n b f, i m a e */
  a4 = vzipq_f32(a2.val[1], a1.val[1]);    /* l p d h, k o c g */

  v0 = vextq_f32(a1.val[0], a1.val[1], 2); /* k c j b */
  v1 = vextq_f32(a2.val[0], a2.val[1], 2); /* o g n f */
  v2 = vextq_f32(a1.val[1], a2.val[0], 2); /* m e l d */
  v3 = vextq_f32(a2.val[1], a1.val[0], 2); /* i a p h */
  v4 = vextq_f32(v1, v2, 2);               /* l d o g */
  v5 = vextq_f32(v0, v3, 2);               /* p h k c */

  /* c2 = c * h - g * d   c12 = a * g - c * e   c8  = a * f - b * e
     c1 = k * p - o * l   c11 = i * o - k * m   c7  = i * n - j * m
     c4 = h * a - d * e   c6  = b * h - d * f   c10 = b * g - c * f
     c3 = p * i - l * m   c5  = j * p - l * n   c9  = j * o - k * n */
  t0 = vmulq_f32(v5, v3);
  t1 = vmulq_f32(a1.val[0], a2.val[1]);
  t2 = vmulq_f32(a1.val[0], v1);

  t0 = glmm_fnmadd(v4, v2, t0);
  t1 = glmm_fnmadd(a1.val[1], a2.val[0], t1);
  t2 = glmm_fnmadd(v0, a2.val[0], t2);

  t0 = vrev64q_f32(t0);
  t1 = vrev64q_f32(t1);
  t2 = vrev64q_f32(t2);

  /* det */
  v0 = vrev64q_f32(t2);
  v1 = vextq_f32(t1, t1, 2);
  v0 = vmulq_f32(t0, v0);
  v1 = vrev64q_f32(v1);
  v1 = vmulq_f32(v1, t1);

  /* c3 * c10 + c4 * c9 + c1 * c8 + c2 * c7 */
#if CGLM_ARM64
  v0 = vpaddq_f32(v0, v0);
  v0 = vpaddq_f32(v0, v0);
#else
  l0 = vget_low_f32(v0);
  l1 = vget_high_f32(v0);

  l0 = vpadd_f32(l0, l0); /* [a+b, a+b] */ 
  l1 = vpadd_f32(l1, l1); /* [c+d, c+d] */ 
  l0 = vadd_f32(l0, l1);  /* [sum, sum] */ 

  v0 = vcombine_f32(l0, l0); 
#endif

  /* c5 * c12 + c6 * c11 */
#if CGLM_ARM64
  v1 = vpaddq_f32(v1, v1);
#else
  l0 = vget_low_f32(v1);
  l1 = vget_high_f32(v1);

  l0 = vpadd_f32(l0, l0); /* [a+b, a+b] */ 
  l1 = vpadd_f32(l1, l1); /* [c+d, c+d] */ 

  v1 = vcombine_f32(l0, l1);
#endif

  v0 = vsubq_f32(v0, v1);    /* det */

  /* inv div */
  v1 = vdupq_n_f32(1.0f);
  v0 = glmm_div(v1, v0);     /* inv div */

  /* multiply t0,t1,t2 by idt to reduce 1mul below: 2eor+4mul vs 3mul+4eor */
  t0 = vmulq_f32(t0, v0);
  t1 = vmulq_f32(t1, v0);
  t2 = vmulq_f32(t2, v0);

  a0 = vzipq_f32(t0, t0);    /* c4  c4  c3 c3, c2  c2  c1  c1  */
  a1 = vzipq_f32(t1, t1);    /* c6  c6  c5 c5, c12 c12 c11 c11 */
  a2 = vzipq_f32(t2, t2);    /* c10 c10 c9 c9, c8  c8  c7  c7  */

  /* result */

  /* dest[0][0] = (f * c1  - g * c5  + h * c9)  * idt;
     dest[0][1] = (b * c1  - c * c5  + d * c9)  * ndt;
     dest[0][2] = (n * c2  - o * c6  + p * c10) * idt;
     dest[0][3] = (j * c2  - k * c6  + l * c10) * ndt;

     dest[1][0] = (e * c1  - g * c3  + h * c11) * ndt;
     dest[1][1] = (a * c1  - c * c3  + d * c11) * idt;
     dest[1][2] = (m * c2  - o * c4  + p * c12) * ndt;
     dest[1][3] = (i * c2  - k * c4  + l * c12) * idt;

     dest[2][0] = (e * c5  - f * c3  + h * c7)  * idt;
     dest[2][1] = (a * c5  - b * c3  + d * c7)  * ndt;
     dest[2][2] = (m * c6  - n * c4  + p * c8)  * idt;
     dest[2][3] = (i * c6  - j * c4  + l * c8)  * ndt;

     dest[3][0] = (e * c9  - f * c11 + g * c7)  * ndt;
     dest[3][1] = (a * c9  - b * c11 + c * c7)  * idt;
     dest[3][2] = (m * c10 - n * c12 + o * c8)  * ndt;
     dest[3][3] = (i * c10 - j * c12 + k * c8)  * idt; */

  r0 = vmulq_f32(a3.val[1], a0.val[0]);
  r1 = vmulq_f32(a3.val[0], a0.val[0]);
  r2 = vmulq_f32(a3.val[0], a1.val[1]);
  r3 = vmulq_f32(a3.val[0], a2.val[1]);

  r0 = glmm_fnmadd(a4.val[0], a1.val[1], r0);
  r1 = glmm_fnmadd(a4.val[0], a0.val[1], r1);
  r2 = glmm_fnmadd(a3.val[1], a0.val[1], r2);
  r3 = glmm_fnmadd(a3.val[1], a1.val[0], r3);

  r0 = glmm_fmadd(a4.val[1], a2.val[1], r0);
  r1 = glmm_fmadd(a4.val[1], a1.val[0], r1);
  r2 = glmm_fmadd(a4.val[1], a2.val[0], r2);
  r3 = glmm_fmadd(a4.val[0], a2.val[0], r3);

  /* 4xor may be fastart then 4mul, see above  */
  r0 = glmm_xor(r0, s1);
  r1 = glmm_xor(r1, s2);
  r2 = glmm_xor(r2, s1);
  r3 = glmm_xor(r3, s2);

  glmm_store(dest[0], r0);
  glmm_store(dest[1], r1);
  glmm_store(dest[2], r2);
  glmm_store(dest[3], r3);
}

#endif
#endif /* cglm_mat4_neon_h */
