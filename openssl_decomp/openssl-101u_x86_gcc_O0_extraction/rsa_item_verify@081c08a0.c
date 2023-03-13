
undefined4
rsa_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,ASN1_OBJECT **param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  int iVar3;
  RSA_PSS_PARAMS *a;
  X509_ALGOR *pXVar4;
  long lVar5;
  char *pcVar6;
  X509_ALGOR *pXVar7;
  undefined4 uVar8;
  int in_GS_OFFSET;
  int line;
  EVP_MD *local_38;
  EVP_MD *local_34;
  long local_30;
  EVP_PKEY_CTX *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = OBJ_obj2nid(*param_4);
  if (iVar3 != 0x390) {
    ERR_put_error(4,0x9c,0x9b,"rsa_ameth.c",0x1be);
    uVar8 = 0xffffffff;
    goto LAB_081c09b0;
  }
  pAVar1 = param_4[1];
  if ((pAVar1 != (ASN1_OBJECT *)0x0) && (pAVar1->sn == (char *)0x10)) {
    local_24 = (EVP_PKEY_CTX *)pAVar1->ln[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,(uchar **)&local_24,(long)*pAVar1->ln);
    if (a != (RSA_PSS_PARAMS *)0x0) {
      pXVar7 = a->maskGenAlgorithm;
      if (pXVar7 == (X509_ALGOR *)0x0) {
        pXVar7 = (X509_ALGOR *)0x0;
LAB_081c09d2:
        local_34 = EVP_sha1();
LAB_081c09db:
        if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
          local_38 = EVP_sha1();
LAB_081c0a0e:
          if (a->saltLength == (ASN1_INTEGER *)0x0) {
            local_30 = 0x14;
          }
          else {
            local_30 = ASN1_INTEGER_get(a->saltLength);
            if (local_30 < 0) {
              line = 0x1eb;
              iVar3 = 0x96;
              goto LAB_081c0a63;
            }
          }
          if ((a->trailerField != (ASN1_INTEGER *)0x0) &&
             (lVar5 = ASN1_INTEGER_get(a->trailerField), lVar5 != 1)) {
            line = 0x1f6;
            iVar3 = 0x8b;
            goto LAB_081c0a63;
          }
          iVar3 = EVP_DigestVerifyInit(param_1,&local_24,local_38,(ENGINE *)0x0,param_6);
          if (((iVar3 == 0) ||
              (iVar3 = EVP_PKEY_CTX_ctrl(local_24,6,-1,0x1001,6,(void *)0x0), iVar3 < 1)) ||
             ((iVar3 = EVP_PKEY_CTX_ctrl(local_24,6,0x18,0x1002,local_30,(void *)0x0), iVar3 < 1 ||
              (iVar3 = EVP_PKEY_CTX_ctrl(local_24,6,0xf8,0x1005,0,local_34), iVar3 < 1))))
          goto LAB_081c0a72;
          uVar8 = 2;
        }
        else {
          iVar3 = OBJ_obj2nid(a->hashAlgorithm->algorithm);
          pcVar6 = OBJ_nid2sn(iVar3);
          local_38 = EVP_get_digestbyname(pcVar6);
          if (local_38 != (EVP_MD *)0x0) goto LAB_081c0a0e;
          line = 0x1dd;
          iVar3 = 0x98;
LAB_081c0a63:
          ERR_put_error(4,0x9c,iVar3,"rsa_ameth.c",line);
LAB_081c0a72:
          uVar8 = 0xffffffff;
        }
        RSA_PSS_PARAMS_free(a);
        if (pXVar7 == (X509_ALGOR *)0x0) goto LAB_081c09b0;
      }
      else {
        pAVar2 = pXVar7->parameter;
        iVar3 = OBJ_obj2nid(pXVar7->algorithm);
        if (((iVar3 == 0x38f) && (pAVar2 != (ASN1_TYPE *)0x0)) && (pAVar2->type == 0x10)) {
          local_24 = (EVP_PKEY_CTX *)((pAVar2->value).asn1_string)->data;
          pXVar7 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_24,
                                  ((pAVar2->value).asn1_string)->length);
          pXVar4 = a->maskGenAlgorithm;
        }
        else {
          pXVar4 = a->maskGenAlgorithm;
          pXVar7 = (X509_ALGOR *)0x0;
        }
        if (pXVar4 == (X509_ALGOR *)0x0) goto LAB_081c09d2;
        iVar3 = OBJ_obj2nid(pXVar4->algorithm);
        if (iVar3 != 0x38f) {
          line = 0x1cb;
          iVar3 = 0x99;
          goto LAB_081c0a63;
        }
        if (pXVar7 == (X509_ALGOR *)0x0) {
          ERR_put_error(4,0x9c,0x9a,"rsa_ameth.c",0x1cf);
          RSA_PSS_PARAMS_free(a);
          uVar8 = 0xffffffff;
          goto LAB_081c09b0;
        }
        iVar3 = OBJ_obj2nid(pXVar7->algorithm);
        pcVar6 = OBJ_nid2sn(iVar3);
        local_34 = EVP_get_digestbyname(pcVar6);
        if (local_34 != (EVP_MD *)0x0) goto LAB_081c09db;
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x97,"rsa_ameth.c",0x1d4);
        RSA_PSS_PARAMS_free(a);
      }
      X509_ALGOR_free(pXVar7);
      goto LAB_081c09b0;
    }
  }
  ERR_put_error(4,0x9c,0x95,"rsa_ameth.c",0x1c5);
  RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)0x0);
  uVar8 = 0xffffffff;
LAB_081c09b0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

