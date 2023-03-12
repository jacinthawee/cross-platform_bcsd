
undefined4
rsa_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,ASN1_OBJECT **param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  int iVar1;
  RSA_PSS_PARAMS *a;
  char *pcVar2;
  EVP_MD *p2;
  EVP_MD *type;
  long lVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  X509_ALGOR *pXVar6;
  ASN1_STRING *pAVar7;
  undefined4 uVar8;
  X509_ALGOR *a_00;
  ASN1_TYPE *pAVar9;
  EVP_PKEY_CTX *local_24;
  
  iVar1 = OBJ_obj2nid(*param_4);
  if (iVar1 != 0x390) {
    ERR_put_error(4,0x9c,0x9b,"rsa_ameth.c",0x1d9);
    return 0xffffffff;
  }
  pAVar5 = param_4[1];
  if ((pAVar5 == (ASN1_OBJECT *)0x0) || (pAVar5->sn != (char *)0x10)) {
LAB_0010816c:
    ERR_put_error(4,0x9c,0x95,"rsa_ameth.c",0x1e1);
    RSA_PSS_PARAMS_free((RSA_PSS_PARAMS *)0x0);
    return 0xffffffff;
  }
  local_24 = (EVP_PKEY_CTX *)pAVar5->ln[2];
  a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,(uchar **)&local_24,(long)*pAVar5->ln);
  if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_0010816c;
  a_00 = a->maskGenAlgorithm;
  if (a_00 == (X509_ALGOR *)0x0) {
LAB_00108206:
    p2 = EVP_sha1();
LAB_001081b0:
    if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
      type = EVP_sha1();
    }
    else {
      iVar1 = OBJ_obj2nid(a->hashAlgorithm->algorithm);
      pcVar2 = OBJ_nid2sn(iVar1);
      type = EVP_get_digestbyname(pcVar2);
      if (type == (EVP_MD *)0x0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x98,"rsa_ameth.c",0x200);
        goto LAB_00108154;
      }
    }
    if (a->saltLength == (ASN1_INTEGER *)0x0) {
      iVar1 = 0x14;
    }
    else {
      iVar1 = ASN1_INTEGER_get(a->saltLength);
      if (iVar1 < 0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x96,"rsa_ameth.c",0x210);
        goto LAB_00108154;
      }
    }
    if ((a->trailerField == (ASN1_INTEGER *)0x0) ||
       (lVar3 = ASN1_INTEGER_get(a->trailerField), lVar3 == 1)) {
      iVar4 = EVP_DigestVerifyInit(param_1,&local_24,type,(ENGINE *)0x0,param_6);
      if ((iVar4 == 0) ||
         (((iVar4 = EVP_PKEY_CTX_ctrl(local_24,6,-1,0x1001,6,(void *)0x0), iVar4 < 1 ||
           (iVar1 = EVP_PKEY_CTX_ctrl(local_24,6,0x18,0x1002,iVar1,(void *)0x0), iVar1 < 1)) ||
          (iVar1 = EVP_PKEY_CTX_ctrl(local_24,6,0xf8,0x1005,0,p2), iVar1 < 1)))) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = 2;
      }
    }
    else {
      uVar8 = 0xffffffff;
      ERR_put_error(4,0x9c,0x8b,"rsa_ameth.c",0x21c);
    }
  }
  else {
    pAVar9 = a_00->parameter;
    iVar1 = OBJ_obj2nid(a_00->algorithm);
    if ((iVar1 == 0x38f) && (pAVar9->type == 0x10)) {
      pAVar7 = (pAVar9->value).asn1_string;
      local_24 = (EVP_PKEY_CTX *)pAVar7->data;
      a_00 = d2i_X509_ALGOR((X509_ALGOR **)0x0,(uchar **)&local_24,pAVar7->length);
      pXVar6 = a->maskGenAlgorithm;
    }
    else {
      pXVar6 = a->maskGenAlgorithm;
      a_00 = (X509_ALGOR *)0x0;
    }
    if (pXVar6 == (X509_ALGOR *)0x0) goto LAB_00108206;
    iVar1 = OBJ_obj2nid(pXVar6->algorithm);
    if (iVar1 == 0x38f) {
      if (a_00 == (X509_ALGOR *)0x0) {
        ERR_put_error(4,0x9c,0x9a,"rsa_ameth.c",0x1ee);
        RSA_PSS_PARAMS_free(a);
        return 0xffffffff;
      }
      iVar1 = OBJ_obj2nid(a_00->algorithm);
      pcVar2 = OBJ_nid2sn(iVar1);
      p2 = EVP_get_digestbyname(pcVar2);
      if (p2 == (EVP_MD *)0x0) {
        uVar8 = 0xffffffff;
        ERR_put_error(4,0x9c,0x97,"rsa_ameth.c",500);
        RSA_PSS_PARAMS_free(a);
        goto LAB_0010815e;
      }
      goto LAB_001081b0;
    }
    uVar8 = 0xffffffff;
    ERR_put_error(4,0x9c,0x99,"rsa_ameth.c",0x1e9);
  }
LAB_00108154:
  RSA_PSS_PARAMS_free(a);
  if (a_00 == (X509_ALGOR *)0x0) {
    return uVar8;
  }
LAB_0010815e:
  X509_ALGOR_free(a_00);
  return uVar8;
}

