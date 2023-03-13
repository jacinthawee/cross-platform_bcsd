
uint aep_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  RSA_METHOD *pRVar8;
  uint uVar9;
  int in_GS_OFFSET;
  int line;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 uVar12;
  int local_24;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x309;
    iVar7 = 0x6f;
  }
  else {
    pBVar2 = param_3->q;
    if ((((pBVar2 != (BIGNUM *)0x0) && (pBVar3 = param_3->dmp1, pBVar3 != (BIGNUM *)0x0)) &&
        (pBVar4 = param_3->dmq1, pBVar4 != (BIGNUM *)0x0)) &&
       (pBVar5 = param_3->iqmp, pBVar5 != (BIGNUM *)0x0)) {
      pBVar6 = param_3->p;
      iVar7 = aep_get_connection();
      if (iVar7 == 0) {
        iVar7 = (*p_AEP_ModExpCrt)(local_24,param_2,pBVar6,pBVar2,pBVar3,pBVar4,pBVar5,param_1,0);
        if (iVar7 == 0) {
          CRYPTO_lock(0,9,(char *)0x1e,(int)"e_aep.c");
          iVar7 = 0;
          do {
            if (local_24 == *(int *)(aep_app_conn_table + iVar7 * 8 + 4)) {
              *(undefined4 *)(aep_app_conn_table + iVar7 * 8) = 1;
              break;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x100);
          CRYPTO_lock(iVar7,10,(char *)0x1e,(int)"e_aep.c");
          uVar9 = 1;
          goto LAB_0819daca;
        }
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x69,0x6d,"e_aep.c",0x2a5);
        uVar12 = 0x3f2;
        pcVar11 = "e_aep.c";
        uVar10 = 0x1e;
        CRYPTO_lock(local_24,9,(char *)0x1e,(int)"e_aep.c");
        iVar7 = 0;
        do {
          if (local_24 == *(int *)(aep_app_conn_table + iVar7 * 8 + 4)) {
            local_24 = (*p_AEP_CloseConnection)(local_24,uVar10,pcVar11,uVar12);
            if (local_24 == 0) {
              *(undefined4 *)(aep_app_conn_table + iVar7 * 8) = 0;
              *(undefined4 *)(aep_app_conn_table + iVar7 * 8 + 4) = 0;
            }
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x100);
        CRYPTO_lock(local_24,10,(char *)0x1e,(int)"e_aep.c");
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x69,0x69,"e_aep.c",0x29a);
      }
      pRVar8 = RSA_PKCS1_SSLeay();
      uVar9 = (*pRVar8->rsa_mod_exp)(param_1,param_2,param_3,param_4);
      goto LAB_0819daca;
    }
    pBVar2 = param_3->d;
    if ((pBVar2 != (BIGNUM *)0x0) && (pBVar3 = param_3->n, pBVar3 != (BIGNUM *)0x0)) {
      iVar7 = BN_num_bits(pBVar3);
      if (iVar7 < 0x881) {
        iVar7 = aep_mod_exp_part_0(pBVar3,param_4);
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
        iVar7 = BN_mod_exp(param_1,param_2,pBVar2,pBVar3,param_4);
      }
      uVar9 = (uint)(iVar7 == 0);
      goto LAB_0819daca;
    }
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x31c;
    iVar7 = 0x6c;
  }
  ERR_put_error(AEPHK_lib_error_code,0x6b,iVar7,"e_aep.c",line);
  uVar9 = 0;
LAB_0819daca:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

