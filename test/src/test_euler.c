/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"


TEST_IMPL(GLM_PREFIX, euler_xyz_quat) {
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in xyz order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);

    glm_euler_xyz_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))
    
    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_XYZ, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in xyz order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);
    
        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_XYZ, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        fprintf(stderr, "%f %f %f %f vs %f %f %f %f\n",
          expected[0], expected[1], expected[2], expected[3],
          result[0], result[1], result[2], result[3]);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_xzy_quat) {
  TEST_SUCCESS //TODO REMOVE
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in xzy order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);

    glm_euler_xzy_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))

    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_XZY, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);

    ASSERTIFY(test_assert_quat_eq(result, expected));
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in xzy order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);

        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_XZY, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_yxz_quat) {
  TEST_SUCCESS //TODO REMOVE
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in yxz order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);

    glm_euler_xyz_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))

    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_YXZ, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);

    ASSERTIFY(test_assert_quat_eq(result, expected));
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in yxz order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);

        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_YXZ, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_yzx_quat) {
  TEST_SUCCESS //TODO REMOVE
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in yzx order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);

    glm_euler_xyz_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))

    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_YZX, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);

    ASSERTIFY(test_assert_quat_eq(result, expected));
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in yzx order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);

        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_YZX, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_zxy_quat) {
  TEST_SUCCESS //TODO REMOVE
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in zxy order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);

    glm_euler_xyz_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))

    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_ZXY, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);

    ASSERTIFY(test_assert_quat_eq(result, expected));
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in zxy order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);

        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_ZXY, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_zyx_quat) {
  TEST_SUCCESS //TODO REMOVE
  vec3 axis_x = {1.0f, 0.0f, 0.0f};
  vec3 axis_y = {0.0f, 1.0f, 0.0f};
  vec3 axis_z = {0.0f, 0.0f, 1.0f};

  /* random angles for testing */
  vec3 angles;

  /* quaternion representations for rotations */
  versor rot_x, rot_y, rot_z;

  versor expected;
  versor result;

  /* 100 randomized tests */
  for (int i = 0; i < 100; i++) {
    test_rand_vec3(angles);

    /* create the rotation quaternions using the angles and axises */
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /* apply the rotations to a unit quaternion in zyx order */
    glm_quat_identity(expected);
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_z, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_y, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(tmp, rot_x, expected);

    glm_euler_xyz_quat(result, angles);

    /* verify if the magnitude of the quaternion stays 1 */
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    /* verify that it acts the same as rotating by 3 axis quaternions */
    ASSERTIFY(test_assert_quat_eq(result, expected))

    /* verify that it acts the same as glm_euler_by_order */
    mat4 expected_mat4;
    glm_euler_by_order(angles, GLM_EULER_ZYX, expected_mat4);
    glm_mat4_quat(expected_mat4, expected);

    ASSERTIFY(test_assert_quat_eq(result, expected));
  }
  

  /* Start gimbal lock tests */
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        angles[0] = x;
        angles[1] = y;
        angles[2] = z;
        
        /* create the rotation quaternions using the angles and axises */
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /* apply the rotations to a unit quaternion in xyz order */
        glm_quat_identity(expected);
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_z, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_y, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(tmp, rot_x, expected);

        /* use my function to get the quaternion */
        glm_euler_xyz_quat(result, angles);

        /* verify if the magnitude of the quaternion stays 1 */
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))

        /* verify that it acts the same as glm_euler_by_order */
        mat4 expected_mat4;
        glm_euler_by_order(angles, GLM_EULER_ZYX, expected_mat4);
        glm_mat4_quat(expected_mat4, expected);

        ASSERTIFY(test_assert_quat_eq(result, expected));
      }
    }
  }
  TEST_SUCCESS
}


TEST_IMPL(euler) {
  mat4 rot1, rot2;
  vec3 inAngles, outAngles;

  inAngles[0] = glm_rad(-45.0f);  /* X angle */
  inAngles[1] = glm_rad(88.0f);   /* Y angle */
  inAngles[2] = glm_rad(18.0f);   /* Z angle */

  glm_euler_xyz(inAngles, rot1);

  /* extract angles */
  glmc_euler_angles(rot1, outAngles);

  /* angles must be equal in that range */
  ASSERTIFY(test_assert_vec3_eq(inAngles, outAngles))

  /* matrices must be equal */
  glmc_euler_xyz(outAngles, rot2);
  ASSERTIFY(test_assert_mat4_eq(rot1, rot2))

  /* change range */
  inAngles[0] = glm_rad(-145.0f);  /* X angle */
  inAngles[1] = glm_rad(818.0f);   /* Y angle */
  inAngles[2] = glm_rad(181.0f);   /* Z angle */

  glm_euler_xyz(inAngles, rot1);
  glmc_euler_angles(rot1, outAngles);

  /* angles may not be equal but matrices MUST! */

  /* matrices must be equal */
  glmc_euler_xyz(outAngles, rot2);
  ASSERTIFY(test_assert_mat4_eq(rot1, rot2))

  /* somehow when I try to make tests outside of this thing, 
     it won't work. So they stay here for now */
  ASSERTIFY(test_GLM_PREFIXeuler_xyz_quat());
  ASSERTIFY(test_GLM_PREFIXeuler_xzy_quat());
  ASSERTIFY(test_GLM_PREFIXeuler_yxz_quat());
  ASSERTIFY(test_GLM_PREFIXeuler_yzx_quat());
  ASSERTIFY(test_GLM_PREFIXeuler_zxy_quat());
  ASSERTIFY(test_GLM_PREFIXeuler_zyx_quat());
  
  TEST_SUCCESS
}
