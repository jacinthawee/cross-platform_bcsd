
uint rsa_sig_print(BIO *param_1,ASN1_OBJECT **param_2,ASN1_STRING *param_3,int param_4)

{
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  int iVar3;
  uint uVar4;
  RSA_PSS_PARAMS *a;
  X509_ALGOR *pXVar5;
  int in_GS_OFFSET;
  char *buf;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = OBJ_obj2nid(*param_2);
  if (iVar3 == 0x390) {
    pAVar1 = param_2[1];
    if ((pAVar1 == (ASN1_OBJECT *)0x0) || (pAVar1->sn != (char *)0x10)) {
LAB_081bfe60:
      iVar3 = BIO_puts(param_1," (INVALID PSS PARAMETERS)\n");
      uVar4 = (uint)(0 < iVar3);
LAB_081bfe79:
      if (uVar4 == 0) goto LAB_081bfd69;
    }
    else {
      local_24 = (uchar *)pAVar1->ln[2];
      a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,&local_24,(long)*pAVar1->ln);
      if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_081bfe60;
      pXVar5 = a->maskGenAlgorithm;
      if (pXVar5 == (X509_ALGOR *)0x0) {
LAB_081bfdf7:
        pXVar5 = (X509_ALGOR *)0x0;
      }
      else {
        pAVar2 = pXVar5->parameter;
        iVar3 = OBJ_obj2nid(pXVar5->algorithm);
        if (((pAVar2 == (ASN1_TYPE *)0x0) || (iVar3 != 0x38f)) || (pAVar2->type != 0x10))
        goto LAB_081bfdf7;
        local_24 = ((pAVar2->value).asn1_string)->data;
        pXVar5 = d2i_X509_ALGOR((X509_ALGOR **)0x0,&local_24,((pAVar2->value).asn1_string)->length);
      }
      iVar3 = BIO_puts(param_1,"\n");
      if (((iVar3 < 1) || (iVar3 = BIO_indent(param_1,param_4,0x80), iVar3 == 0)) ||
         (iVar3 = BIO_puts(param_1,"Hash Algorithm: "), iVar3 < 1)) {
LAB_081bfe2b:
        RSA_PSS_PARAMS_free(a);
        uVar4 = 0;
        if (pXVar5 == (X509_ALGOR *)0x0) goto LAB_081bfd69;
LAB_081bfe41:
        X509_ALGOR_free(pXVar5);
        goto LAB_081bfe79;
      }
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar3 = BIO_puts(param_1,"sha1 (default)");
        if (0 < iVar3) goto LAB_081bff1a;
        goto LAB_081bfe2b;
      }
      iVar3 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar3 < 1) goto LAB_081bfe2b;
LAB_081bff1a:
      iVar3 = BIO_puts(param_1,"\n");
      if (((iVar3 < 1) || (iVar3 = BIO_indent(param_1,param_4,0x80), iVar3 == 0)) ||
         (iVar3 = BIO_puts(param_1,"Mask Algorithm: "), iVar3 < 1)) goto LAB_081bfe2b;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        buf = "mgf1 with sha1 (default)";
LAB_081c00d5:
        iVar3 = BIO_puts(param_1,buf);
      }
      else {
        iVar3 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar3 < 1) || (iVar3 = BIO_puts(param_1," with "), iVar3 < 1)) goto LAB_081bfe2b;
        if (pXVar5 == (X509_ALGOR *)0x0) {
          buf = "INVALID";
          goto LAB_081c00d5;
        }
        iVar3 = i2a_ASN1_OBJECT(param_1,pXVar5->algorithm);
      }
      if (iVar3 < 1) goto LAB_081bfe2b;
      BIO_puts(param_1,"\n");
      iVar3 = BIO_indent(param_1,param_4,0x80);
      if ((iVar3 == 0) || (iVar3 = BIO_puts(param_1,"Salt Length: 0x"), iVar3 < 1))
      goto LAB_081bfe2b;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar3 = BIO_puts(param_1,"14 (default)");
        if (0 < iVar3) goto LAB_081c0023;
        goto LAB_081bfe2b;
      }
      iVar3 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar3 < 1) goto LAB_081bfe2b;
LAB_081c0023:
      BIO_puts(param_1,"\n");
      iVar3 = BIO_indent(param_1,param_4,0x80);
      if ((iVar3 == 0) || (iVar3 = BIO_puts(param_1,"Trailer Field: 0x"), iVar3 < 1))
      goto LAB_081bfe2b;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar3 = BIO_puts(param_1,"BC (default)");
      }
      else {
        iVar3 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar3 < 1) goto LAB_081bfe2b;
      BIO_puts(param_1,"\n");
      RSA_PSS_PARAMS_free(a);
      uVar4 = 1;
      if (pXVar5 != (X509_ALGOR *)0x0) goto LAB_081bfe41;
    }
    if (param_3 == (ASN1_STRING *)0x0) {
      uVar4 = 1;
      goto LAB_081bfd69;
    }
  }
  else if (param_3 == (ASN1_STRING *)0x0) {
    iVar3 = BIO_puts(param_1,"\n");
    uVar4 = (uint)(0 < iVar3);
    goto LAB_081bfd69;
  }
  uVar4 = X509_signature_dump(param_1,param_3,param_4);
LAB_081bfd69:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

