
undefined4
rsa_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,ASN1_OBJECT **param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  ASN1_STRING *pAVar3;
  int iVar4;
  RSA_PSS_PARAMS *a;
  X509_ALGOR *pXVar5;
  char *pcVar6;
  long lVar7;
  X509_ALGOR *pXVar8;
  undefined4 uVar9;
  int in_GS_OFFSET;
  int line;
  EVP_MD *local_38;
  EVP_MD *local_34;
  long local_30;
  EVP_PKEY_CTX *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = OBJ_obj2nid(*param_4);
  if (iVar4 != 0x390) {
    ERR_put_error(4,0x9c,0x9b,"rsa_ameth.c",0x1d9);
    uVar9 = 0xffffffff;
    goto LAB_081c1b37;
  }
  pAVar1 = param_4[1];
  if ((pAVar1 != (ASN1_OBJECT *)0x0) && (pAVar1->sn == (char *)0x10)) {
    local_24 = (EVP_PKEY_CTX *)pAVar1->ln[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,(uchar **)&local_24,(long)*pAVar1->ln);
    if (a != (RSA_PSS_PARAMS *)0x0) {
      pXVar8 = a->maskGenAlgorithm;
      if (pXVar8 == (X509_ALGOR *)0x0) {
        pXVar8 = (X509_ALGOR *)0x0;
LAB_081c1ce2:
        local_34 = EVP_sha1();
LAB_081c1bb9:
        if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
          local_38 = EVP_sha1();
LAB_081c1bec:
          if (a->saltLength == (ASN1_INTEGER *)0x0) {
            local_30 = 0x14;
          }
          else {
            local_30 = ASN1_INTEGER_get(a->saltLength);
            if (local_30 < 0) {
              line = 0x210;
              iVar4 = 0x96;
              goto LAB_081c1b01;
            }
          }
          if ((a->trailerField != (ASN1_INTEGER *)0x0) &&
             (lVar7 = ASN1_INTEGER_get(a->trailerField), lVar7 != 1)) {
            line = 0x21c;
            iVar4 = 0x8b;
            goto LAB_081c1b01;
          }
          iVar4 = EVP_DigestVerifyInit(param_1,&local_24,local_38,(ENGINE *)0x0,param_6);
          if ((((iVar4 == 0) ||
               (iVar4 = EVP_PKEY_CTX_ctrl(local_24,6,-1,0x1001,6,(void *)0x0), iVar4 < 1)) ||
              (iVar4 = EVP_PKEY_CTX_ctrl(local_24,6,0x18,0x1002,local_30,(void *)0x0), iVar4 < 1))
             || (iVar4 = EVP_PKEY_CTX_ctrl(local_24,6,0xf8,0x1005,0,local_34), iVar4 < 1))
          goto LAB_081c1b10;
          uVar9 = 2;
        }
        else {
          iVar4 = OBJ_obj2nid(a->hashAlgorithm->algorithm);
          pcVar6 = OBJ_nid2sn(iVar4);
          local_38 = EVP_get_digestbyname(pcVar6);
          if (local_38 != (EVP_MD *)0x0) goto LAB_081c1bec;
          line = 0x200;
          iVar4 = 0x98;
LAB_081c1b01:
          ERR_put_error(4,0x9c,iVar4,"rsa_ameth.c",line);
LAB_081c1b10:
          uVar9 = 0xffffffff;
        }
        RSA_PSS_PARAMS_free(a);
        if (pXVar8 == (X509_ALGOR *)0x0) goto LAB_081c1b37;
      }
      else {
        pAVar2 = pXVar8->parameter;
        iVar4 = OBJ_obj2nid(pXVar8->algorithm);
        if ((iVar4 == 0x38f) && (pAVar2->type == 0x10)) {
          pAVar3 = (pAVar2->value).asn1_string;
          local_24 = (EVP_PKEY_CTX *)pAVar3->data;
          pXVar8 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_24,pAVar3->length);
          pXVar5 = a->maskGenAlgorithm;
        }
        else {
          pXVar5 = a->maskGenAlgorithm;
          pXVar8 = (X509_ALGOR *)0x0;
        }
        if (pXVar5 == (X509_ALGOR *)0x0) goto LAB_081c1ce2;
        iVar4 = OBJ_obj2nid(pXVar5->algorithm);
        if (iVar4 != 0x38f) {
          line = 0x1e9;
          iVar4 = 0x99;
          goto LAB_081c1b01;
        }
        if (pXVar8 == (X509_ALGOR *)0x0) {
          ERR_put_error(4,0x9c,0x9a,"rsa_ameth.c",0x1ee);
          RSA_PSS_PARAMS_free(a);
          uVar9 = 0xffffffff;
          goto LAB_081c1b37;
        }
        iVar4 = OBJ_obj2nid(pXVar8->algorithm);
        pcVar6 = OBJ_nid2sn(iVar4);
        local_34 = EVP_get_digestbyname(pcVar6);
        if (local_34 != (EVP_MD *)0x0) goto LAB_081c1bb9;
        uVar9 = 0xffffffff;
        ERR_put_error(4,0x9c,0x97,"rsa_ameth.c",500);
        RSA_PSS_PARAMS_free(a);
      }
      X509_ALGOR_free(pXVar8);
      goto LAB_081c1b37;
    }
  }
  ERR_put_error(4,0x9c,0x95,"rsa_ameth.c",0x1e1);
  RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)0x0);
  uVar9 = 0xffffffff;
LAB_081c1b37:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}

