
/* WARNING: Type propagation algorithm not settling */

uint rsa_sig_print(BIO *param_1,ASN1_OBJECT **param_2,ASN1_STRING *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  RSA_PSS_PARAMS *a;
  ASN1_STRING *pAVar3;
  ASN1_OBJECT *pAVar4;
  X509_ALGOR *pXVar5;
  undefined uVar6;
  ASN1_TYPE *pAVar7;
  uchar *local_24 [2];
  
  iVar1 = OBJ_obj2nid(*param_2);
  if (iVar1 != 0x390) {
    if (param_3 == (ASN1_STRING *)0x0) {
      iVar1 = BIO_puts(param_1,"\n");
      return (uint)(0 < iVar1);
    }
    goto LAB_001079ca;
  }
  pAVar4 = param_2[1];
  if ((pAVar4 == (ASN1_OBJECT *)0x0) || (pAVar4->sn != (char *)0x10)) {
LAB_00107a5a:
    iVar1 = BIO_puts(param_1," (INVALID PSS PARAMETERS)\n");
    uVar6 = 0 < iVar1;
  }
  else {
    local_24[0] = (uchar *)pAVar4->ln[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,local_24,(long)*pAVar4->ln);
    if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_00107a5a;
    pXVar5 = a->maskGenAlgorithm;
    if (pXVar5 == (X509_ALGOR *)0x0) {
LAB_00107a18:
      pXVar5 = (X509_ALGOR *)0x0;
    }
    else {
      pAVar7 = pXVar5->parameter;
      iVar1 = OBJ_obj2nid(pXVar5->algorithm);
      if ((iVar1 != 0x38f) || (pAVar7->type != 0x10)) goto LAB_00107a18;
      pAVar3 = (pAVar7->value).asn1_string;
      local_24[0] = pAVar3->data;
      pXVar5 = d2i_X509_ALGOR((X509_ALGOR **)0x0,local_24,pAVar3->length);
    }
    iVar1 = BIO_puts(param_1,"\n");
    if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
       (iVar1 = BIO_puts(param_1,"Hash Algorithm: "), iVar1 < 1)) {
LAB_00107a3a:
      uVar6 = 0;
    }
    else {
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"sha1 (default)");
        if (0 < iVar1) goto LAB_00107ab2;
        goto LAB_00107a3a;
      }
      iVar1 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar1 < 1) goto LAB_00107a3a;
LAB_00107ab2:
      iVar1 = BIO_puts(param_1,"\n");
      if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
         (iVar1 = BIO_puts(param_1,"Mask Algorithm: "), iVar1 < 1)) goto LAB_00107a3a;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"mgf1 with sha1 (default)");
      }
      else {
        iVar1 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar1 < 1) || (iVar1 = BIO_puts(param_1," with "), iVar1 < 1)) goto LAB_00107a3a;
        if (pXVar5 == (X509_ALGOR *)0x0) {
          iVar1 = BIO_puts(param_1,"INVALID");
        }
        else {
          iVar1 = i2a_ASN1_OBJECT(param_1,pXVar5->algorithm);
        }
      }
      if (iVar1 < 1) goto LAB_00107a3a;
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Salt Length: 0x"), iVar1 < 1))
      goto LAB_00107a3a;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"0x14 (default)");
        if (0 < iVar1) goto LAB_00107b66;
        goto LAB_00107a3a;
      }
      iVar1 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar1 < 1) goto LAB_00107a3a;
LAB_00107b66:
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Trailer Field: 0x"), iVar1 < 1))
      goto LAB_00107a3a;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"BC (default)");
      }
      else {
        iVar1 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar1 < 1) goto LAB_00107a3a;
      uVar6 = 1;
      BIO_puts(param_1,"\n");
    }
    RSA_PSS_PARAMS_free(a);
    if (pXVar5 != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(pXVar5);
    }
  }
  if (!(bool)uVar6) {
    return 0;
  }
  if (param_3 == (ASN1_STRING *)0x0) {
    return 1;
  }
LAB_001079ca:
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

