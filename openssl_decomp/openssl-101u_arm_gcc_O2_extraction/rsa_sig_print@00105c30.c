
/* WARNING: Type propagation algorithm not settling */

uint rsa_sig_print(BIO *param_1,ASN1_OBJECT **param_2,ASN1_STRING *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  RSA_PSS_PARAMS *a;
  ASN1_OBJECT *pAVar3;
  X509_ALGOR *pXVar4;
  undefined uVar5;
  ASN1_TYPE *pAVar6;
  uchar *local_24 [2];
  
  iVar1 = OBJ_obj2nid(*param_2);
  if (iVar1 != 0x390) {
    if (param_3 == (ASN1_STRING *)0x0) {
      iVar1 = BIO_puts(param_1,"\n");
      return (uint)(0 < iVar1);
    }
    goto LAB_00105c4e;
  }
  pAVar3 = param_2[1];
  if ((pAVar3 == (ASN1_OBJECT *)0x0) || (pAVar3->sn != (char *)0x10)) {
LAB_00105cde:
    iVar1 = BIO_puts(param_1," (INVALID PSS PARAMETERS)\n");
    uVar5 = 0 < iVar1;
  }
  else {
    local_24[0] = (uchar *)pAVar3->ln[2];
    a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,local_24,(long)*pAVar3->ln);
    if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_00105cde;
    pXVar4 = a->maskGenAlgorithm;
    if (pXVar4 == (X509_ALGOR *)0x0) {
LAB_00105c9c:
      pXVar4 = (X509_ALGOR *)0x0;
    }
    else {
      pAVar6 = pXVar4->parameter;
      iVar1 = OBJ_obj2nid(pXVar4->algorithm);
      if (((iVar1 != 0x38f) || (pAVar6 == (ASN1_TYPE *)0x0)) || (pAVar6->type != 0x10))
      goto LAB_00105c9c;
      local_24[0] = ((pAVar6->value).asn1_string)->data;
      pXVar4 = d2i_X509_ALGOR((X509_ALGOR **)0x0,local_24,((pAVar6->value).asn1_string)->length);
    }
    iVar1 = BIO_puts(param_1,"\n");
    if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
       (iVar1 = BIO_puts(param_1,"Hash Algorithm: "), iVar1 < 1)) {
LAB_00105cbe:
      uVar5 = 0;
    }
    else {
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"sha1 (default)");
        if (0 < iVar1) goto LAB_00105d36;
        goto LAB_00105cbe;
      }
      iVar1 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar1 < 1) goto LAB_00105cbe;
LAB_00105d36:
      iVar1 = BIO_puts(param_1,"\n");
      if (((iVar1 < 1) || (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)) ||
         (iVar1 = BIO_puts(param_1,"Mask Algorithm: "), iVar1 < 1)) goto LAB_00105cbe;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        iVar1 = BIO_puts(param_1,"mgf1 with sha1 (default)");
      }
      else {
        iVar1 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar1 < 1) || (iVar1 = BIO_puts(param_1," with "), iVar1 < 1)) goto LAB_00105cbe;
        if (pXVar4 == (X509_ALGOR *)0x0) {
          iVar1 = BIO_puts(param_1,"INVALID");
        }
        else {
          iVar1 = i2a_ASN1_OBJECT(param_1,pXVar4->algorithm);
        }
      }
      if (iVar1 < 1) goto LAB_00105cbe;
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Salt Length: 0x"), iVar1 < 1))
      goto LAB_00105cbe;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"14 (default)");
        if (0 < iVar1) goto LAB_00105dea;
        goto LAB_00105cbe;
      }
      iVar1 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar1 < 1) goto LAB_00105cbe;
LAB_00105dea:
      BIO_puts(param_1,"\n");
      iVar1 = BIO_indent(param_1,param_4,0x80);
      if ((iVar1 == 0) || (iVar1 = BIO_puts(param_1,"Trailer Field: 0x"), iVar1 < 1))
      goto LAB_00105cbe;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar1 = BIO_puts(param_1,"BC (default)");
      }
      else {
        iVar1 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar1 < 1) goto LAB_00105cbe;
      uVar5 = 1;
      BIO_puts(param_1,"\n");
    }
    RSA_PSS_PARAMS_free(a);
    if (pXVar4 != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(pXVar4);
    }
  }
  if (!(bool)uVar5) {
    return 0;
  }
  if (param_3 == (ASN1_STRING *)0x0) {
    return 1;
  }
LAB_00105c4e:
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

