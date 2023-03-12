
undefined4
rsa_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,ASN1_OBJECT **param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  RSA_PSS_PARAMS *a;
  char *pcVar3;
  EVP_MD *p2;
  EVP_MD *type;
  long lVar4;
  int iVar5;
  ASN1_OBJECT *pAVar6;
  X509_ALGOR *pXVar7;
  undefined4 uVar8;
  X509_ALGOR *a_00;
  EVP_PKEY_CTX *local_24;
  
  iVar2 = OBJ_obj2nid(*param_4);
  if (iVar2 != 0x390) {
    ERR_put_error(4,0x9c,0x9b,"rsa_ameth.c",0x1be);
    return 0xffffffff;
  }
  pAVar6 = param_4[1];
  if ((pAVar6 == (ASN1_OBJECT *)0x0) || (pAVar6->sn != (char *)0x10)) {
LAB_001063fc:
    ERR_put_error(4,0x9c,0x95,"rsa_ameth.c",0x1c5);
    RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)0x0);
    return 0xffffffff;
  }
  local_24 = (EVP_PKEY_CTX *)pAVar6->ln[2];
  a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,(uchar **)&local_24,(long)*pAVar6->ln);
  if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_001063fc;
  a_00 = a->maskGenAlgorithm;
  if (a_00 == (X509_ALGOR *)0x0) {
LAB_00106496:
    p2 = EVP_sha1();
LAB_00106440:
    if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
      type = EVP_sha1();
    }
    else {
      iVar2 = OBJ_obj2nid(a->hashAlgorithm->algorithm);
      pcVar3 = OBJ_nid2sn(iVar2);
      type = EVP_get_digestbyname(pcVar3);
      if (type == (EVP_MD *)0x0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x98,"rsa_ameth.c",0x1dd);
        goto LAB_001063e4;
      }
    }
    if (a->saltLength == (ASN1_INTEGER *)0x0) {
      iVar2 = 0x14;
    }
    else {
      iVar2 = ASN1_INTEGER_get(a->saltLength);
      if (iVar2 < 0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x96,"rsa_ameth.c",0x1eb);
        goto LAB_001063e4;
      }
    }
    if ((a->trailerField == (ASN1_INTEGER *)0x0) ||
       (lVar4 = ASN1_INTEGER_get(a->trailerField), lVar4 == 1)) {
      iVar5 = EVP_DigestVerifyInit(param_1,&local_24,type,(ENGINE *)0x0,param_6);
      if ((iVar5 == 0) ||
         (((iVar5 = EVP_PKEY_CTX_ctrl(local_24,6,-1,0x1001,6,(void *)0x0), iVar5 < 1 ||
           (iVar2 = EVP_PKEY_CTX_ctrl(local_24,6,0x18,0x1002,iVar2,(void *)0x0), iVar2 < 1)) ||
          (iVar2 = EVP_PKEY_CTX_ctrl(local_24,6,0xf8,0x1005,0,p2), iVar2 < 1)))) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = 2;
      }
    }
    else {
      uVar8 = 0xffffffff;
      ERR_put_error(4,0x9c,0x8b,"rsa_ameth.c",0x1f6);
    }
  }
  else {
    ppAVar1 = &a_00->algorithm;
    a_00 = (X509_ALGOR *)a_00->parameter;
    iVar2 = OBJ_obj2nid(*ppAVar1);
    if (iVar2 == 0x38f) {
      if (a_00 != (X509_ALGOR *)0x0) {
        if (a_00->algorithm != (ASN1_OBJECT *)0x10) goto LAB_001063b2;
        local_24 = (EVP_PKEY_CTX *)a_00->parameter[1].type;
        a_00 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_24,a_00->parameter->type);
      }
      pXVar7 = a->maskGenAlgorithm;
    }
    else {
LAB_001063b2:
      pXVar7 = a->maskGenAlgorithm;
      a_00 = (X509_ALGOR *)0x0;
    }
    if (pXVar7 == (X509_ALGOR *)0x0) goto LAB_00106496;
    iVar2 = OBJ_obj2nid(pXVar7->algorithm);
    if (iVar2 == 0x38f) {
      if (a_00 == (X509_ALGOR *)0x0) {
        ERR_put_error(4,0x9c,0x9a,"rsa_ameth.c",0x1cf);
        RSA_PSS_PARAMS_free(a);
        return 0xffffffff;
      }
      iVar2 = OBJ_obj2nid(a_00->algorithm);
      pcVar3 = OBJ_nid2sn(iVar2);
      p2 = EVP_get_digestbyname(pcVar3);
      if (p2 == (EVP_MD *)0x0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x97,"rsa_ameth.c",0x1d4);
        RSA_PSS_PARAMS_free(a);
        goto LAB_001063ee;
      }
      goto LAB_00106440;
    }
    uVar8 = 0xffffffff;
    ERR_put_error(4,0x9c,0x99,"rsa_ameth.c",0x1cb);
  }
LAB_001063e4:
  RSA_PSS_PARAMS_free(a);
  if (a_00 == (X509_ALGOR *)0x0) {
    return uVar8;
  }
LAB_001063ee:
  X509_ALGOR_free(a_00);
  return uVar8;
}

