
uint aep_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  uint uVar3;
  undefined4 uVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  int iVar9;
  BIGNUM *pBVar10;
  int local_2c [2];
  
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x6b,0x6f,"e_aep.c",0x309);
    uVar3 = 0;
  }
  else {
    pBVar7 = param_3->q;
    if ((((pBVar7 != (BIGNUM *)0x0) && (pBVar8 = param_3->dmp1, pBVar8 != (BIGNUM *)0x0)) &&
        (pBVar5 = param_3->dmq1, pBVar5 != (BIGNUM *)0x0)) &&
       (pBVar10 = param_3->iqmp, pBVar10 != (BIGNUM *)0x0)) {
      pBVar6 = param_3->p;
      iVar1 = aep_get_connection(local_2c);
      if (iVar1 == 0) {
        iVar1 = (*p_AEP_ModExpCrt)(local_2c[0],param_2,pBVar6,pBVar7,pBVar8,pBVar5,pBVar10,param_1,0
                                  );
        if (iVar1 == 0) {
          CRYPTO_lock(9,0x1e,"e_aep.c",0x3dc);
          do {
            iVar9 = iVar1 * 8;
            iVar1 = iVar1 + 1;
            if (local_2c[0] == *(int *)(aep_app_conn_table + iVar9 + 4)) {
              *(undefined4 *)(aep_app_conn_table + iVar9) = 1;
              break;
            }
          } while (iVar1 != 0x100);
          CRYPTO_lock(10,0x1e,"e_aep.c",1000);
          return 1;
        }
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x69,0x6d,"e_aep.c",0x2a5);
        CRYPTO_lock(9,0x1e,"e_aep.c",0x3f2);
        iVar1 = 0;
        do {
          iVar9 = iVar1 * 8;
          iVar1 = iVar1 + 1;
          if (local_2c[0] == *(int *)(PTR_aep_app_conn_table_000ef25c + iVar9 + 4)) {
            iVar1 = (*p_AEP_CloseConnection)(local_2c[0]);
            if (iVar1 == 0) {
              *(undefined4 *)(aep_app_conn_table + iVar9) = 0;
              *(undefined4 *)(aep_app_conn_table + iVar9 + 4) = 0;
            }
            break;
          }
        } while (iVar1 != 0x100);
        CRYPTO_lock(10,0x1e,"e_aep.c",0x403);
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x69,0x69,"e_aep.c",0x29a);
      }
      pRVar2 = RSA_PKCS1_SSLeay();
      uVar3 = (*pRVar2->rsa_mod_exp)(param_1,param_2,param_3,param_4);
      return uVar3;
    }
    if ((param_3->d == (BIGNUM *)0x0) || (param_3->n == (BIGNUM *)0x0)) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x6b,0x6c,"e_aep.c",0x31c);
      return 0;
    }
    uVar4 = aep_mod_exp(param_1,param_2,param_3->d,param_3->n,param_4);
    uVar3 = count_leading_zeroes(uVar4);
    uVar3 = uVar3 >> 5;
  }
  return uVar3;
}

