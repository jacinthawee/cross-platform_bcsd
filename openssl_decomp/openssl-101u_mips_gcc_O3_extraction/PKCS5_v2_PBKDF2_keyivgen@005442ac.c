
int PKCS5_v2_PBKDF2_keyivgen
              (EVP_CIPHER_CTX *param_1,char *param_2,int param_3,int *param_4,undefined4 param_5,
              undefined4 param_6,EVP_MD *param_7)

{
  undefined *puVar1;
  EVP_CIPHER *pEVar2;
  EVP_MD *digest;
  int **ppiVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  EVP_CIPHER *cipher;
  EVP_CIPHER_CTX *ctx;
  int *salt;
  int *piVar8;
  int iVar9;
  int *saltlen;
  undefined4 uStack_d0;
  int **ppiStack_cc;
  EVP_CIPHER *pEStack_c8;
  undefined *puStack_c4;
  int **ppiStack_c0;
  int iStack_bc;
  int *piStack_b8;
  char *pcStack_b4;
  int iStack_b0;
  code *pcStack_ac;
  int iVar10;
  EVP_MD *in_stack_ffffff6c;
  EVP_CIPHER *in_stack_ffffff70;
  undefined4 local_74;
  int local_70;
  int aiStack_6c [16];
  EVP_CIPHER_CTX *local_2c;
  
  puStack_c4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(EVP_CIPHER_CTX **)PTR___stack_chk_guard_006a9ae8;
  pEVar2 = EVP_CIPHER_CTX_cipher(param_1);
  if (pEVar2 == (EVP_CIPHER *)0x0) {
    salt = (int *)0x83;
    piVar8 = &DAT_006693d4;
    iVar10 = 0x105;
    ERR_put_error(6,0xa4,0x83,(char *)&DAT_006693d4,0x105);
    ppiStack_c0 = (int **)0x0;
    pEStack_c8 = (EVP_CIPHER *)0x0;
    iStack_bc = 0;
    param_7 = in_stack_ffffff6c;
  }
  else {
    pEStack_c8 = (EVP_CIPHER *)EVP_CIPHER_CTX_key_length(param_1);
    if ((EVP_CIPHER *)&DAT_00000040 < pEStack_c8) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)(&DAT_006693d4,0x109,"keylen <= sizeof key");
    }
    if ((param_4 == (int *)0x0) || (*param_4 != 0x10)) {
      salt = (int *)0x72;
      piVar8 = &DAT_006693d4;
      iVar10 = 0x10e;
      ERR_put_error(6,0xa4,0x72,(char *)&DAT_006693d4,0x10e);
      ppiStack_c0 = (int **)0x0;
      iStack_bc = 0;
      param_7 = in_stack_ffffff6c;
    }
    else {
      local_74 = ((undefined4 *)param_4[1])[2];
      ppiStack_c0 = (int **)(*(code *)PTR_d2i_PBKDF2PARAM_006a8c78)
                                      (0,&local_74,*(undefined4 *)param_4[1]);
      if (ppiStack_c0 == (int **)0x0) {
        salt = (int *)0x72;
        iVar10 = 0x116;
      }
      else {
        pEStack_c8 = (EVP_CIPHER *)EVP_CIPHER_CTX_key_length(param_1);
        if ((ASN1_INTEGER *)ppiStack_c0[2] != (ASN1_INTEGER *)0x0) {
          pEVar2 = (EVP_CIPHER *)ASN1_INTEGER_get((ASN1_INTEGER *)ppiStack_c0[2]);
          if (pEStack_c8 != pEVar2) {
            salt = (int *)0x7b;
            iVar10 = 0x11f;
            goto LAB_005444e0;
          }
        }
        if (ppiStack_c0[3] == (int *)0x0) {
          iVar10 = 0xa3;
        }
        else {
          iVar10 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*ppiStack_c0[3]);
        }
        iVar10 = EVP_PBE_find(1,iVar10,(int *)0x0,&local_70,(undefined1 **)0x0);
        if (iVar10 == 0) {
          salt = (int *)0x7d;
          iVar10 = 0x129;
        }
        else {
          pcVar7 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(local_70);
          digest = EVP_get_digestbyname(pcVar7);
          if (digest == (EVP_MD *)0x0) {
            salt = (int *)0x7d;
            iVar10 = 0x12f;
          }
          else {
            if (**ppiStack_c0 == 4) {
              ppiVar3 = (int **)(*ppiStack_c0)[1];
              piVar8 = aiStack_6c;
              salt = ppiVar3[2];
              saltlen = *ppiVar3;
              iVar10 = ASN1_INTEGER_get((ASN1_INTEGER *)ppiStack_c0[1]);
              in_stack_ffffff70 = pEStack_c8;
              iVar5 = PKCS5_PBKDF2_HMAC(param_2,param_3,(uchar *)salt,(int)saltlen,iVar10,digest,
                                        (int)pEStack_c8,(uchar *)piVar8);
              if (iVar5 == 0) {
                iStack_bc = 0;
                piVar8 = saltlen;
                param_7 = digest;
              }
              else {
                salt = (int *)0x0;
                iVar10 = 0;
                iStack_bc = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                              (uchar *)piVar8,(uchar *)0x0,(int)param_7);
              }
              goto LAB_00544378;
            }
            salt = (int *)0x7e;
            iVar10 = 0x134;
          }
        }
      }
LAB_005444e0:
      piVar8 = &DAT_006693d4;
      ERR_put_error(6,0xa4,(int)salt,(char *)&DAT_006693d4,iVar10);
      iStack_bc = 0;
      param_7 = in_stack_ffffff6c;
    }
  }
LAB_00544378:
  piStack_b8 = aiStack_6c;
  pEVar2 = pEStack_c8;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(piStack_b8);
  (*(code *)PTR_PBKDF2PARAM_free_006a8c7c)(ppiStack_c0);
  if (local_2c == *(EVP_CIPHER_CTX **)puStack_c4) {
    return iStack_bc;
  }
  pcStack_ac = PKCS5_v2_PBE_keyivgen;
  ctx = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  ppiStack_cc = *(int ***)PTR___stack_chk_guard_006a9ae8;
  pcStack_b4 = param_2;
  iStack_b0 = param_3;
  if (((piVar8 == (int *)0x0) || (*piVar8 != 0x10)) ||
     (puVar4 = (undefined4 *)piVar8[1], puVar4 == (undefined4 *)0x0)) {
    pEVar2 = (EVP_CIPHER *)&DAT_00000076;
    iVar9 = 0;
    ERR_put_error(6,0x76,0x72,(char *)&DAT_006693d4,0xcb);
    piVar8 = (int *)0x0;
    goto LAB_005446bc;
  }
  uStack_d0 = puVar4[2];
  piVar8 = (int *)(*(code *)PTR_d2i_PBE2PARAM_006a8c88)(0,&uStack_d0,*puVar4);
  if (piVar8 == (int *)0x0) {
    iVar5 = 0x72;
    iVar10 = 0xd2;
  }
  else {
    iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*piVar8);
    if (iVar5 == 0x45) {
      uVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)piVar8[1]);
      pcVar7 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(uVar6);
      cipher = EVP_get_cipherbyname(pcVar7);
      if (cipher == (EVP_CIPHER *)0x0) {
        iVar5 = 0x6b;
        iVar10 = 0xe5;
      }
      else {
        iVar5 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,
                                  (int)in_stack_ffffff70);
        if (iVar5 == 0) {
          iVar9 = 0;
          pEVar2 = cipher;
          goto LAB_005446bc;
        }
        iVar5 = EVP_CIPHER_asn1_to_param(ctx,*(ASN1_TYPE **)(piVar8[1] + 4));
        if (-1 < iVar5) {
          iVar9 = PKCS5_v2_PBKDF2_keyivgen
                            (ctx,pEVar2,salt,*(undefined4 *)(*piVar8 + 4),iVar10,param_7,
                             in_stack_ffffff70);
          goto LAB_005446bc;
        }
        iVar5 = 0x7a;
        iVar10 = 0xed;
      }
    }
    else {
      iVar5 = 0x7c;
      iVar10 = 0xda;
    }
  }
  pEVar2 = (EVP_CIPHER *)&DAT_00000076;
  iVar9 = 0;
  ERR_put_error(6,0x76,iVar5,(char *)&DAT_006693d4,iVar10);
LAB_005446bc:
  (*(code *)PTR_PBE2PARAM_free_006a8c84)(piVar8);
  if (ppiStack_cc == *(int ***)puVar1) {
    return iVar9;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return **ppiStack_cc - *(int *)pEVar2->nid;
}

