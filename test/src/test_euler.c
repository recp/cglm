/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"


TEST_IMPL(GLM_PREFIX, euler_xyz_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in xyz order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);

    /*use my function to get the quaternion*/
    glm_euler_xyz_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }
  

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in xyz order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);

        /*use my function to get the quaternion*/
        glm_euler_xyz_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
      }
    }
  }
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_xzy_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in xzy order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);

    /*use my function to get the quaternion*/
    glm_euler_xzy_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in xyz order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);

        /*use my function to get the quaternion*/
        glm_euler_xzy_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
      }
    }
  }
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_yxz_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in yxz order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);

    /*use my function to get the quaternion*/
    glm_euler_yxz_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in yxz order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);

        /*use my function to get the quaternion*/
        glm_euler_yxz_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
      }
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_yzx_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in yzx order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);

    /*use my function to get the quaternion*/
    glm_euler_yzx_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in yzx order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);

        /*use my function to get the quaternion*/
        glm_euler_yzx_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
      }
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_zxy_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in zxy order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);

    /*use my function to get the quaternion*/
    glm_euler_zxy_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in zxy order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);


        /*use my function to get the quaternion*/
        glm_euler_zxy_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
      }
    }
  }

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, euler_zyx_quat) {
  for (int i = 0; i < 100; i++) {
    /*random angles for testing*/
    vec3 angles;

    /*quaternion representations for rotations*/
    versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
    versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

    vec3 axis_x = {1.0f, 0.0f, 0.0f};
    vec3 axis_y = {0.0f, 1.0f, 0.0f};
    vec3 axis_z = {0.0f, 0.0f, 1.0f};

    versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
    versor result;

    test_rand_vec3(angles);

    /*create the rotation quaternions using the angles and axises*/
    glm_quatv(rot_x, angles[0], axis_x);
    glm_quatv(rot_y, angles[1], axis_y);
    glm_quatv(rot_z, angles[2], axis_z);

    /*apply the rotations to a unit quaternion in zyx order*/
    versor tmp;
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_z, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_y, tmp, expected);
    glm_quat_copy(expected, tmp);
    glm_quat_mul(rot_x, tmp, expected);


    /*use my function to get the quaternion*/
    glm_euler_zyx_quat(result, angles);

    /*verify if the magnitude of the quaternion stays 1*/
    ASSERT(test_eq(glm_quat_norm(result), 1.0f))

    ASSERTIFY(test_assert_quat_eq(result, expected))
  }

  /*Start gimbal lock tests*/
  for (float x = -90.0f; x <= 90.0f; x += 90.0f) {
    for (float y = -90.0f; y <= 90.0f; y += 90.0f) {
      for (float z = -90.0f; z <= 90.0f; z += 90.0f) {
        
        /* angles that will cause gimbal lock*/
        vec3 angles = {x, y, z};

        /*quaternion representations for rotations*/
        versor rot_x = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_y = {0.0f, 0.0f, 0.0f, 1.0f};
        versor rot_z = {0.0f, 0.0f, 0.0f, 1.0f};

        vec3 axis_x = {1.0f, 0.0f, 0.0f};
        vec3 axis_y = {0.0f, 1.0f, 0.0f};
        vec3 axis_z = {0.0f, 0.0f, 1.0f};

        versor expected = {0.0f, 0.0f, 0.0f, 1.0f};
        versor result;

        /*create the rotation quaternions using the angles and axises*/
        glm_quatv(rot_x, angles[0], axis_x);
        glm_quatv(rot_y, angles[1], axis_y);
        glm_quatv(rot_z, angles[2], axis_z);

        /*apply the rotations to a unit quaternion in zyx order*/
        versor tmp;
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_z, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_y, tmp, expected);
        glm_quat_copy(expected, tmp);
        glm_quat_mul(rot_x, tmp, expected);


        /*use my function to get the quaternion*/
        glm_euler_zyx_quat(result, angles);

        /*verify if the magnitude of the quaternion stays 1*/
        ASSERT(test_eq(glm_quat_norm(result), 1.0f))

        ASSERTIFY(test_assert_quat_eq(result, expected))
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
