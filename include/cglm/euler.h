/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 NOTE:
  angles must be passed as [X-Angle, Y-Angle, Z-angle] order
  For instance you don't pass angles as [Z-Angle, X-Angle, Y-angle] to
  glm_euler_zxy funciton, All RELATED functions accept angles same order
  which is [X, Y, Z].
 */

/*
 Types:
   enum glm_euler_seq

 Functions:
   CGLM_INLINE glm_eul_mat4(vec3 ea, int order, mat4 dest)
 */

#ifndef cglm_euler_h
#define cglm_euler_h

#include "common.h"
#include "util.h"

/* ---------- Notice for Ken Shoemake's algorithm Implementation -------------*
 | Ken Shoemake's algorithm impl. is taken from this repo by permission:      |
 |   https://github.com/erich666/GraphicsGems/blob/master/gemsiv/euler_angle  |
 |                                                                            |
 | cglm doesn't claim the ownership of GraphicsGems source codes              |
 | and the algorithm itself. But cglm may change variable names or some piece |
 | of codes in order to apply optimizations or to make it usable in cglm.     |
 | The ownership of improvements                                              |
 |                                                                            |
 | Related issue: https://github.com/recp/cglm/issues/30                      |
 |                                                                            |
 * -------------------------- GraphicsGems EULA ----------------------------- *
 | Related EULA for GraphicsGems can be found at and below, plus in CREDITS:  |
 |   http://www.realtimerendering.com/resources/GraphicsGems/                 |
 |                                                                            |
 | EULA: The Graphics Gems code is copyright-protected. In other words, you   |
 | cannot claim the text of the code as your own and resell it. Using the     |
 | code is permitted in any program, product, or library, non-commercial or   |
 | commercial. Giving credit is not required, though is a nice gesture.       |
 | The code comes as-is, and if there are any flaws or problems with any Gems |
 | code, nobody involved with Gems - authors, editors, publishers, or         |
 | webmasters - are to be held responsible. Basically, don't be a jerk, and   |
 | remember that anything free comes with no guarantee.                       |
 * -------------------------------- END --------------------------------------*/

/* Order type constants, constructors, extractors
 * There are 24 possible conventions, designated by:
 *	  o EulAxI = axis used initially
 *	  o EulPar = parity of axis permutation
 *	  o EulRep = repetition of initial axis as last
 *	  o EulFrm = frame from which axes are taken
 * Axes I,J,K will be a permutation of X,Y,Z.
 * Axis H will be either I or K, depending on EulRep.
 * Frame S takes axes from initial static frame.
 * If ord = (AxI=X, Par=Even, Rep=No, Frm=S), then
 * {a,b,c,ord} means Rz(c)Ry(b)Rx(a), where Rz(c)v
 * rotates v around Z by c radians.			    
*/

#define EulFrmS	     0
#define EulFrmR	     1
#define EulFrm(ord)  ((unsigned)(ord)&1)
#define EulRepNo     0
#define EulRepYes    1
#define EulRep(ord)  (((unsigned)(ord)>>1)&1)
#define EulParEven   0
#define EulParOdd    1
#define EulPar(ord)  (((unsigned)(ord)>>2)&1)

/*! this code is merely a quick (and legal!) way to set arrays,
    EulSafe being 0,1,2,0 */
#define EulSafe	     "\000\001\002\000"
#define EulNext	     "\001\002\000\001"
#define EulAxI(ord)  ((int)(EulSafe[(((unsigned)(ord)>>3)&3)]))
#define EulAxJ(ord)  ((int)(EulNext[EulAxI(ord)+(EulPar(ord)==EulParOdd)]))
#define EulAxK(ord)  ((int)(EulNext[EulAxI(ord)+(EulPar(ord)!=EulParOdd)]))
#define EulAxH(ord)  ((EulRep(ord)==EulRepNo)?EulAxK(ord):EulAxI(ord))
/*! EulGetOrd unpacks all useful information about order simultaneously. */
#define EulGetOrd(ord,i,j,k,h,n,s,f)                                          \
  {unsigned o=(unsigned)ord;f=o&1;o>>=1;s=o&1;o>>=1;\
    n=o&1;o>>=1;i=EulSafe[o&3];j=EulNext[i+n];k=EulNext[i+1-n];h=s?k:i;}
/*! EulOrd creates an order value between 0 and 23 from 4-tuple choices. */
#define EulOrd(i,p,r,f)	   (((((((i)<<1)+(p))<<1)+(r))<<1)+(f))

/* EulOrd first param: X = 0, Y = 1, Z = 2 */

/*! Static axes */
#define GLM_EUL_XYZs    EulOrd(0,EulParEven,EulRepNo,EulFrmS)
#define GLM_EUL_XYXs    EulOrd(0,EulParEven,EulRepYes,EulFrmS)
#define GLM_EUL_XZYs    EulOrd(0,EulParOdd,EulRepNo,EulFrmS)
#define GLM_EUL_XZXs    EulOrd(0,EulParOdd,EulRepYes,EulFrmS)
#define GLM_EUL_YZXs    EulOrd(1,EulParEven,EulRepNo,EulFrmS)
#define GLM_EUL_YZYs    EulOrd(1,EulParEven,EulRepYes,EulFrmS)
#define GLM_EUL_YXZs    EulOrd(1,EulParOdd,EulRepNo,EulFrmS)
#define GLM_EUL_YXYs    EulOrd(1,EulParOdd,EulRepYes,EulFrmS)
#define GLM_EUL_ZXYs    EulOrd(2,EulParEven,EulRepNo,EulFrmS)
#define GLM_EUL_ZXZs    EulOrd(2,EulParEven,EulRepYes,EulFrmS)
#define GLM_EUL_ZYXs    EulOrd(2,EulParOdd,EulRepNo,EulFrmS)
#define GLM_EUL_ZYZs    EulOrd(2,EulParOdd,EulRepYes,EulFrmS)

/*! Rotating axes */
#define GLM_EUL_ZYXr    EulOrd(0,EulParEven,EulRepNo,EulFrmR)
#define GLM_EUL_XYXr    EulOrd(0,EulParEven,EulRepYes,EulFrmR)
#define GLM_EUL_YZXr    EulOrd(0,EulParOdd,EulRepNo,EulFrmR)
#define GLM_EUL_XZXr    EulOrd(0,EulParOdd,EulRepYes,EulFrmR)
#define GLM_EUL_XZYr    EulOrd(1,EulParEven,EulRepNo,EulFrmR)
#define GLM_EUL_YZYr    EulOrd(1,EulParEven,EulRepYes,EulFrmR)
#define GLM_EUL_ZXYr    EulOrd(1,EulParOdd,EulRepNo,EulFrmR)
#define GLM_EUL_YXYr    EulOrd(1,EulParOdd,EulRepYes,EulFrmR)
#define GLM_EUL_YXZr    EulOrd(2,EulParEven,EulRepNo,EulFrmR)
#define GLM_EUL_ZXZr    EulOrd(2,EulParEven,EulRepYes,EulFrmR)
#define GLM_EUL_XYZr    EulOrd(2,EulParOdd,EulRepNo,EulFrmR)
#define GLM_EUL_ZYZr    EulOrd(2,EulParOdd,EulRepYes,EulFrmR)

/*!
 * @brief build matrix from euler angles
 *
 * @param[in]  ea     [Xangle, Yangle, Zangle, OrderCode]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_eul_mat4(vec3 ea, int order, mat4 dest) {
  float ti, tj, th, ci, cj, ch, si, sj, sh, cc, cs, sc, ss;
  int   i, j, k, h, n, s, f;

  EulGetOrd(order, i, j, k, h, n, s, f);
  
  if (f == EulFrmR)
    glm_swapf(&ea[0], &ea[2]);
  
  if (n == EulParOdd)
    glm_vec3_negate(ea);
  
  ti = ea[0]; tj = ea[1]; th = ea[2];
  
  ci = cosf(ti);  cj = cosf(tj);
  ch = cosf(th);  si = sinf(ti);
  sj = sinf(tj);  sh = sinf(th);
  
  cc = ci * ch;  cs = ci * sh;
  sc = si * ch;  ss = si * sh;
  
  if (s == EulRepYes) {
    dest[i][i] =  cj;
    dest[i][j] =  sj * si;
    dest[i][k] =  sj * ci;
    dest[j][i] =  sj * sh;
    dest[j][j] = -cj * ss + cc;
    dest[j][k] = -cj * cs - sc;
    dest[k][i] = -sj * ch;
    dest[k][j] =  cj * sc + cs;
    dest[k][k] =  cj * cc - ss;
  } else {
    dest[i][i] =  cj * ch;
    dest[i][j] =  sj * sc - cs;
    dest[i][k] =  sj * cc + ss;
    dest[j][i] =  cj * sh;
    dest[j][j] =  sj * ss + cc;
    dest[j][k] =  sj * cs - sc;
    dest[k][i] = -sj;
    dest[k][j] =  cj * si;
    dest[k][k] =  cj * ci;
  }
  
  dest[3][0] = 0.f;
  dest[3][1] = 0.f;
  dest[3][2] = 0.f;
  dest[0][3] = 0.f;
  dest[1][3] = 0.f;
  dest[2][3] = 0.f;
  dest[3][3] = 1.f;
}

/*!
 * if you have axis order like vec3 orderVec = [0, 1, 2] or [0, 2, 1]...
 * vector then you can convert it to this enum by doing this:
 * @code
 * glm_euler_seq order;
 * order = orderVec[0] | orderVec[1] << 2 | orderVec[2] << 4;
 * @endcode
 * you may need to explicit cast if required
 */
typedef enum glm_euler_seq {
  GLM_EULER_XYZ = 0 << 0 | 1 << 2 | 2 << 4,
  GLM_EULER_XZY = 0 << 0 | 2 << 2 | 1 << 4,
  GLM_EULER_YZX = 1 << 0 | 2 << 2 | 0 << 4,
  GLM_EULER_YXZ = 1 << 0 | 0 << 2 | 2 << 4,
  GLM_EULER_ZXY = 2 << 0 | 0 << 2 | 1 << 4,
  GLM_EULER_ZYX = 2 << 0 | 1 << 2 | 0 << 4
} glm_euler_seq;

typedef glm_euler_seq glm_euler_sq;

CGLM_INLINE
glm_euler_seq
glm_euler_order(int ord[3]) {
  return (glm_euler_seq)(ord[0] << 0 | ord[1] << 2 | ord[2] << 4);
}

/*!
 * @brief extract euler angles (in radians) using xyz order
 *
 * @param[in]  m    affine transform
 * @param[out] dest angles vector [x, y, z]
 */
CGLM_INLINE
void
glm_euler_angles(mat4 m, vec3 dest) {
  float m00, m01, m10, m11, m20, m21, m22;
  float thetaX, thetaY, thetaZ;

  m00 = m[0][0];  m10 = m[1][0];  m20 = m[2][0];
  m01 = m[0][1];  m11 = m[1][1];  m21 = m[2][1];
                                  m22 = m[2][2];

  if (m20 < 1.0f) {
    if (m20 > -1.0f) {
      thetaY = asinf(m20);
      thetaX = atan2f(-m21, m22);
      thetaZ = atan2f(-m10, m00);
    } else { /* m20 == -1 */
      /* Not a unique solution */
      thetaY = -GLM_PI_2f;
      thetaX = -atan2f(m01, m11);
      thetaZ =  0.0f;
    }
  } else { /* m20 == +1 */
    thetaY = GLM_PI_2f;
    thetaX = atan2f(m01, m11);
    thetaZ = 0.0f;
  }

  dest[0] = thetaX;
  dest[1] = thetaY;
  dest[2] = thetaZ;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_xyz(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, czsx, cxcz, sysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  czsx = cz * sx;
  cxcz = cx * cz;
  sysz = sy * sz;

  dest[0][0] =  cy * cz;
  dest[0][1] =  czsx * sy + cx * sz;
  dest[0][2] = -cxcz * sy + sx * sz;
  dest[1][0] = -cy * sz;
  dest[1][1] =  cxcz - sx * sysz;
  dest[1][2] =  czsx + cx * sysz;
  dest[2][0] =  sy;
  dest[2][1] = -cy * sx;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler(vec3 angles, mat4 dest) {
  glm_euler_xyz(angles, dest);
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_xzy(vec3 angles, mat4 dest) {
  float cx, cy, cz,
  sx, sy, sz, sxsy, cysx, cxsy, cxcy;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  sxsy = sx * sy;
  cysx = cy * sx;
  cxsy = cx * sy;
  cxcy = cx * cy;

  dest[0][0] =  cy * cz;
  dest[0][1] =  sxsy + cxcy * sz;
  dest[0][2] = -cxsy + cysx * sz;
  dest[1][0] = -sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cz * sx;
  dest[2][0] =  cz * sy;
  dest[2][1] = -cysx + cxsy * sz;
  dest[2][2] =  cxcy + sxsy * sz;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}


/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_yxz(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, cycz, sysz, czsy, cysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz;
  sysz = sy * sz;
  czsy = cz * sy;
  cysz = cy * sz;

  dest[0][0] =  cycz + sx * sysz;
  dest[0][1] =  cx * sz;
  dest[0][2] = -czsy + cysz * sx;
  dest[1][0] = -cysz + czsy * sx;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cycz * sx + sysz;
  dest[2][0] =  cx * sy;
  dest[2][1] = -sx;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_yzx(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, sxsy, cxcy, cysx, cxsy;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  sxsy = sx * sy;
  cxcy = cx * cy;
  cysx = cy * sx;
  cxsy = cx * sy;

  dest[0][0] =  cy * cz;
  dest[0][1] =  sz;
  dest[0][2] = -cz * sy;
  dest[1][0] =  sxsy - cxcy * sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cysx + cxsy * sz;
  dest[2][0] =  cxsy + cysx * sz;
  dest[2][1] = -cz * sx;
  dest[2][2] =  cxcy - sxsy * sz;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_zxy(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, cycz, sxsy, cysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz;
  sxsy = sx * sy;
  cysz = cy * sz;

  dest[0][0] =  cycz - sxsy * sz;
  dest[0][1] =  cz * sxsy + cysz;
  dest[0][2] = -cx * sy;
  dest[1][0] = -cx * sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  sx;
  dest[2][0] =  cz * sy + cysz * sx;
  dest[2][1] = -cycz * sx + sy * sz;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_zyx(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, czsx, cxcz, sysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  czsx = cz * sx;
  cxcz = cx * cz;
  sysz = sy * sz;

  dest[0][0] =  cy * cz;
  dest[0][1] =  cy * sz;
  dest[0][2] = -sy;
  dest[1][0] =  czsx * sy - cx * sz;
  dest[1][1] =  cxcz + sx * sysz;
  dest[1][2] =  cy * sx;
  dest[2][0] =  cxcz * sy + sx * sz;
  dest[2][1] = -czsx + cx * sysz;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[in]  ord    euler order
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_by_order(vec3 angles, glm_euler_seq ord, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  float cycz, cysz, cysx, cxcy,
        czsy, cxcz, czsx, cxsz,
        sysz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz; cysz = cy * sz;
  cysx = cy * sx; cxcy = cx * cy;
  czsy = cz * sy; cxcz = cx * cz;
  czsx = cz * sx; cxsz = cx * sz;
  sysz = sy * sz;

  switch (ord) {
    case GLM_EULER_XZY:
      dest[0][0] =  cycz;
      dest[0][1] =  sx * sy + cx * cysz;
      dest[0][2] = -cx * sy + cysx * sz;
      dest[1][0] = -sz;
      dest[1][1] =  cxcz;
      dest[1][2] =  czsx;
      dest[2][0] =  czsy;
      dest[2][1] = -cysx + cx * sysz;
      dest[2][2] =  cxcy + sx * sysz;
      break;
    case GLM_EULER_XYZ:
      dest[0][0] =  cycz;
      dest[0][1] =  czsx * sy + cxsz;
      dest[0][2] = -cx * czsy + sx * sz;
      dest[1][0] = -cysz;
      dest[1][1] =  cxcz - sx * sysz;
      dest[1][2] =  czsx + cx * sysz;
      dest[2][0] =  sy;
      dest[2][1] = -cysx;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_YXZ:
      dest[0][0] =  cycz + sx * sysz;
      dest[0][1] =  cxsz;
      dest[0][2] = -czsy + cysx * sz;
      dest[1][0] =  czsx * sy - cysz;
      dest[1][1] =  cxcz;
      dest[1][2] =  cycz * sx + sysz;
      dest[2][0] =  cx * sy;
      dest[2][1] = -sx;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_YZX:
      dest[0][0] =  cycz;
      dest[0][1] =  sz;
      dest[0][2] = -czsy;
      dest[1][0] =  sx * sy - cx * cysz;
      dest[1][1] =  cxcz;
      dest[1][2] =  cysx + cx * sysz;
      dest[2][0] =  cx * sy + cysx * sz;
      dest[2][1] = -czsx;
      dest[2][2] =  cxcy - sx * sysz;
      break;
    case GLM_EULER_ZXY:
      dest[0][0] =  cycz - sx * sysz;
      dest[0][1] =  czsx * sy + cysz;
      dest[0][2] = -cx * sy;
      dest[1][0] = -cxsz;
      dest[1][1] =  cxcz;
      dest[1][2] =  sx;
      dest[2][0] =  czsy + cysx * sz;
      dest[2][1] = -cycz * sx + sysz;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_ZYX:
      dest[0][0] =  cycz;
      dest[0][1] =  cysz;
      dest[0][2] = -sy;
      dest[1][0] =  czsx * sy - cxsz;
      dest[1][1] =  cxcz + sx * sysz;
      dest[1][2] =  cysx;
      dest[2][0] =  cx * czsy + sx * sz;
      dest[2][1] = -czsx + cx * sysz;
      dest[2][2] =  cxcy;
      break;
  }

  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

#endif /* cglm_euler_h */
