
uint rsa_sig_print(BIO *param_1,ASN1_OBJECT **param_2,ASN1_STRING *param_3,int param_4)

{
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  ASN1_STRING *pAVar3;
  int iVar4;
  uint uVar5;
  RSA_PSS_PARAMS *a;
  X509_ALGOR *pXVar6;
  int in_GS_OFFSET;
  char *buf;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = OBJ_obj2nid(*param_2);
  if (iVar4 == 0x390) {
    pAVar1 = param_2[1];
    if ((pAVar1 == (ASN1_OBJECT *)0x0) || (pAVar1->sn != (char *)0x10)) {
LAB_081c0ff8:
      iVar4 = BIO_puts(param_1," (INVALID PSS PARAMETERS)\n");
      uVar5 = (uint)(0 < iVar4);
LAB_081c0fd8:
      if (uVar5 == 0) goto LAB_081c0ef9;
    }
    else {
      local_24 = (uchar *)pAVar1->ln[2];
      a = d2i_RSA_PSS_PARAMS((RSA_PSS_PARAMS **)0x0,&local_24,(long)*pAVar1->ln);
      if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_081c0ff8;
      pXVar6 = a->maskGenAlgorithm;
      if (pXVar6 == (X509_ALGOR *)0x0) {
LAB_081c0f7a:
        pXVar6 = (X509_ALGOR *)0x0;
      }
      else {
        pAVar2 = pXVar6->parameter;
        iVar4 = OBJ_obj2nid(pXVar6->algorithm);
        if ((iVar4 != 0x38f) || (pAVar2->type != 0x10)) goto LAB_081c0f7a;
        pAVar3 = (pAVar2->value).asn1_string;
        local_24 = pAVar3->data;
        pXVar6 = d2i_X509_ALGOR((X509_ALGOR **)0x0,&local_24,pAVar3->length);
      }
      iVar4 = BIO_puts(param_1,"\n");
      if (((iVar4 < 1) || (iVar4 = BIO_indent(param_1,param_4,0x80), iVar4 == 0)) ||
         (iVar4 = BIO_puts(param_1,"Hash Algorithm: "), iVar4 < 1)) {
LAB_081c0fae:
        RSA_PSS_PARAMS_free(a);
        uVar5 = 0;
        if (pXVar6 == (X509_ALGOR *)0x0) goto LAB_081c0ef9;
LAB_081c0fc4:
        X509_ALGOR_free(pXVar6);
        goto LAB_081c0fd8;
      }
      if (a->hashAlgorithm == (X509_ALGOR *)0x0) {
        iVar4 = BIO_puts(param_1,"sha1 (default)");
        if (0 < iVar4) goto LAB_081c1079;
        goto LAB_081c0fae;
      }
      iVar4 = i2a_ASN1_OBJECT(param_1,a->hashAlgorithm->algorithm);
      if (iVar4 < 1) goto LAB_081c0fae;
LAB_081c1079:
      iVar4 = BIO_puts(param_1,"\n");
      if (((iVar4 < 1) || (iVar4 = BIO_indent(param_1,param_4,0x80), iVar4 == 0)) ||
         (iVar4 = BIO_puts(param_1,"Mask Algorithm: "), iVar4 < 1)) goto LAB_081c0fae;
      if (a->maskGenAlgorithm == (X509_ALGOR *)0x0) {
        buf = "mgf1 with sha1 (default)";
LAB_081c1263:
        iVar4 = BIO_puts(param_1,buf);
      }
      else {
        iVar4 = i2a_ASN1_OBJECT(param_1,a->maskGenAlgorithm->algorithm);
        if ((iVar4 < 1) || (iVar4 = BIO_puts(param_1," with "), iVar4 < 1)) goto LAB_081c0fae;
        if (pXVar6 == (X509_ALGOR *)0x0) {
          buf = "INVALID";
          goto LAB_081c1263;
        }
        iVar4 = i2a_ASN1_OBJECT(param_1,pXVar6->algorithm);
      }
      if (iVar4 < 1) goto LAB_081c0fae;
      BIO_puts(param_1,"\n");
      iVar4 = BIO_indent(param_1,param_4,0x80);
      if ((iVar4 == 0) || (iVar4 = BIO_puts(param_1,"Salt Length: 0x"), iVar4 < 1))
      goto LAB_081c0fae;
      if (a->saltLength == (ASN1_INTEGER *)0x0) {
        iVar4 = BIO_puts(param_1,"0x14 (default)");
        if (0 < iVar4) goto LAB_081c1183;
        goto LAB_081c0fae;
      }
      iVar4 = i2a_ASN1_INTEGER(param_1,a->saltLength);
      if (iVar4 < 1) goto LAB_081c0fae;
LAB_081c1183:
      BIO_puts(param_1,"\n");
      iVar4 = BIO_indent(param_1,param_4,0x80);
      if ((iVar4 == 0) || (iVar4 = BIO_puts(param_1,"Trailer Field: 0x"), iVar4 < 1))
      goto LAB_081c0fae;
      if (a->trailerField == (ASN1_INTEGER *)0x0) {
        iVar4 = BIO_puts(param_1,"BC (default)");
      }
      else {
        iVar4 = i2a_ASN1_INTEGER(param_1,a->trailerField);
      }
      if (iVar4 < 1) goto LAB_081c0fae;
      BIO_puts(param_1,"\n");
      RSA_PSS_PARAMS_free(a);
      uVar5 = 1;
      if (pXVar6 != (X509_ALGOR *)0x0) goto LAB_081c0fc4;
    }
    if (param_3 == (ASN1_STRING *)0x0) {
      uVar5 = 1;
      goto LAB_081c0ef9;
    }
  }
  else if (param_3 == (ASN1_STRING *)0x0) {
    iVar4 = BIO_puts(param_1,"\n");
    uVar5 = (uint)(0 < iVar4);
    goto LAB_081c0ef9;
  }
  uVar5 = X509_signature_dump(param_1,param_3,param_4);
LAB_081c0ef9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

