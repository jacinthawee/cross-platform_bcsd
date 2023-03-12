
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  byte *pbVar1;
  long lVar2;
  ASN1_INTEGER *a;
  int iVar3;
  int iVar4;
  X509_NAME *pXVar5;
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  ASN1_UTCTIME *pAVar7;
  X509_CINF *pXVar8;
  char *pcVar9;
  undefined4 uVar10;
  X509_ALGOR *pXVar11;
  undefined4 uVar12;
  int iVar13;
  int local_30;
  int aiStack_2c [2];
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar13 = 0xc;
    uVar12 = 10;
  }
  else {
    if (nmflag == 0) {
      iVar13 = 0x10;
    }
    else {
      iVar13 = 0;
    }
    uVar12 = 0x20;
  }
  pXVar8 = x->cert_info;
  if (-1 < (int)(cflag << 0x1f)) {
    iVar4 = BIO_write(bp,"Certificate:\n",0xd);
    if (iVar4 < 1) {
      return 0;
    }
    iVar4 = BIO_write(bp,"    Data:\n",10);
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1e)) {
    lVar2 = ASN1_INTEGER_get(x->cert_info->version);
    iVar4 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n","",lVar2 + 1,lVar2);
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1d)) {
    iVar4 = BIO_write(bp,"        Serial Number:",0x16);
    if (iVar4 < 1) {
      return 0;
    }
    a = X509_get_serialNumber(x);
    if ((a->length < 4) || ((a->length == 4 && (-1 < (char)*a->data)))) {
      iVar4 = ASN1_INTEGER_get(a);
      if (a->type == 0x102) {
        pcVar9 = "-";
        iVar4 = -iVar4;
      }
      else {
        pcVar9 = "";
      }
      iVar4 = BIO_printf(bp," %s%lu (%s0x%lx)\n",pcVar9,iVar4,pcVar9,iVar4);
      if (iVar4 < 1) {
        return 0;
      }
    }
    else {
      pcVar9 = " (Negative)";
      if (a->type != 0x102) {
        pcVar9 = "";
      }
      iVar4 = BIO_printf(bp,"\n%12s%s","",pcVar9);
      if (iVar4 < 1) {
        return 0;
      }
      iVar4 = 0;
      while (iVar4 < a->length) {
        pbVar1 = a->data + iVar4;
        iVar4 = iVar4 + 1;
        if (a->length == iVar4) {
          uVar10 = 10;
        }
        else {
          uVar10 = 0x3a;
        }
        iVar3 = BIO_printf(bp,"%02x%c",(uint)*pbVar1,uVar10);
        if (iVar3 < 1) {
          return 0;
        }
      }
    }
  }
  if ((cflag & 8) == 0) {
    pXVar11 = pXVar8->signature;
    iVar4 = BIO_puts(bp,"    Signature Algorithm: ");
    if (iVar4 < 1) {
      return 0;
    }
    iVar4 = i2a_ASN1_OBJECT(bp,pXVar11->algorithm);
    if (iVar4 < 1) {
      return 0;
    }
    iVar4 = OBJ_obj2nid(pXVar11->algorithm);
    if ((((iVar4 == 0) || (iVar4 = OBJ_find_sigid_algs(iVar4,aiStack_2c,&local_30), iVar4 == 0)) ||
        (pEVar6 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_30), pEVar6 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar6 + 0x50) == (code *)0x0)) {
      iVar4 = BIO_puts(bp,"\n");
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      iVar4 = (**(code **)(pEVar6 + 0x50))(bp,pXVar11,0,9,0);
    }
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1b)) {
    iVar4 = BIO_printf(bp,"        Issuer:%c",uVar12);
    if (iVar4 < 1) {
      return 0;
    }
    pXVar5 = X509_get_issuer_name(x);
    iVar4 = X509_NAME_print_ex(bp,pXVar5,iVar13,nmflag);
    if (iVar4 < 0) {
      return 0;
    }
    iVar4 = BIO_write(bp,"\n",1);
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1a)) {
    iVar4 = BIO_write(bp,"        Validity\n",0x11);
    if (iVar4 < 1) {
      return 0;
    }
    iVar4 = BIO_write(bp,"            Not Before: ",0x18);
    if (iVar4 < 1) {
      return 0;
    }
    pAVar7 = x->cert_info->validity->notBefore;
    if (pAVar7->type == 0x17) {
      iVar4 = ASN1_UTCTIME_print(bp,pAVar7);
    }
    else {
      if (pAVar7->type != 0x18) goto LAB_000b7750;
      iVar4 = ASN1_GENERALIZEDTIME_print(bp,pAVar7);
    }
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = BIO_write(bp,"\n            Not After : ",0x19);
    if (iVar4 < 1) {
      return 0;
    }
    pAVar7 = x->cert_info->validity->notAfter;
    if (pAVar7->type == 0x17) {
      iVar4 = ASN1_UTCTIME_print(bp,pAVar7);
    }
    else {
      if (pAVar7->type != 0x18) {
LAB_000b7750:
        BIO_write(bp,"Bad time value",0xe);
        return 0;
      }
      iVar4 = ASN1_GENERALIZEDTIME_print(bp,pAVar7);
    }
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = BIO_write(bp,"\n",1);
    if (iVar4 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x19)) {
    iVar4 = BIO_printf(bp,"        Subject:%c",uVar12);
    if (iVar4 < 1) {
      return 0;
    }
    pXVar5 = X509_get_subject_name(x);
    iVar13 = X509_NAME_print_ex(bp,pXVar5,iVar13,nmflag);
    if (iVar13 < 0) {
      return 0;
    }
    iVar13 = BIO_write(bp,"\n",1);
    if (iVar13 < 1) {
      return 0;
    }
  }
  if ((cflag & 0x80) == 0) {
    iVar13 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
    if (iVar13 < 1) {
      return 0;
    }
    iVar13 = BIO_printf(bp,"%12sPublic Key Algorithm: ","");
    if (iVar13 < 1) {
      return 0;
    }
    iVar13 = i2a_ASN1_OBJECT(bp,pXVar8->key->algor->algorithm);
    if (iVar13 < 1) {
      return 0;
    }
    iVar13 = BIO_puts(bp,"\n");
    if (iVar13 < 1) {
      return 0;
    }
    pkey = X509_get_pubkey(x);
    if (pkey == (EVP_PKEY *)0x0) {
      BIO_printf(bp,"%12sUnable to load Public Key\n","");
      ERR_print_errors(bp);
    }
    else {
      EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
    }
  }
  if (-1 < (int)(cflag << 0x17)) {
    X509V3_extensions_print(bp,"X509v3 extensions",pXVar8->extensions,cflag,8);
  }
  if ((-1 < (int)(cflag << 0x16)) &&
     (iVar13 = X509_signature_print(bp,x->sig_alg,x->signature), iVar13 < 1)) {
    return 0;
  }
  if ((cflag & 0x400) == 0) {
    iVar13 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
    if (iVar13 != 0) {
      iVar13 = 1;
    }
  }
  else {
    iVar13 = 1;
  }
  return iVar13;
}

