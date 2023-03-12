
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  byte *pbVar1;
  long lVar2;
  ASN1_INTEGER *a;
  int iVar3;
  X509_NAME *pXVar4;
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  ASN1_UTCTIME *pAVar6;
  X509_CINF *pXVar7;
  char *pcVar8;
  undefined4 uVar9;
  X509_ALGOR *pXVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int local_30;
  int aiStack_2c [2];
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar12 = 0xc;
    uVar11 = 10;
  }
  else {
    if (nmflag == 0) {
      iVar12 = 0x10;
    }
    else {
      iVar12 = 0;
    }
    uVar11 = 0x20;
  }
  pXVar7 = x->cert_info;
  if (-1 < (int)(cflag << 0x1f)) {
    iVar3 = BIO_write(bp,"Certificate:\n",0xd);
    if (iVar3 < 1) {
      return 0;
    }
    iVar3 = BIO_write(bp,"    Data:\n",10);
    if (iVar3 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1e)) {
    lVar2 = ASN1_INTEGER_get(x->cert_info->version);
    iVar3 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n","",lVar2 + 1,lVar2);
    if (iVar3 < 1) {
      return 0;
    }
  }
  if ((cflag & 4) == 0) {
    uVar13 = cflag & 4;
    iVar3 = BIO_write(bp,"        Serial Number:",0x16);
    if (iVar3 < 1) {
      return 0;
    }
    a = X509_get_serialNumber(x);
    if (a->length < 5) {
      iVar3 = ASN1_INTEGER_get(a);
      if (a->type == 0x102) {
        pcVar8 = "-";
        iVar3 = -iVar3;
      }
      else {
        pcVar8 = "";
      }
      iVar3 = BIO_printf(bp," %s%lu (%s0x%lx)\n",pcVar8,iVar3,pcVar8,iVar3);
      if (iVar3 < 1) {
        return 0;
      }
    }
    else {
      pcVar8 = " (Negative)";
      if (a->type != 0x102) {
        pcVar8 = "";
      }
      iVar3 = BIO_printf(bp,"\n%12s%s","",pcVar8);
      while( true ) {
        if (iVar3 < 1) {
          return 0;
        }
        if (a->length <= (int)uVar13) break;
        pbVar1 = a->data + uVar13;
        uVar13 = uVar13 + 1;
        if (a->length == uVar13) {
          uVar9 = 10;
        }
        else {
          uVar9 = 0x3a;
        }
        iVar3 = BIO_printf(bp,"%02x%c",(uint)*pbVar1,uVar9);
      }
    }
  }
  if ((cflag & 8) == 0) {
    pXVar10 = x->sig_alg;
    iVar3 = BIO_puts(bp,"    Signature Algorithm: ");
    if (iVar3 < 1) {
      return 0;
    }
    iVar3 = i2a_ASN1_OBJECT(bp,pXVar10->algorithm);
    if (iVar3 < 1) {
      return 0;
    }
    iVar3 = OBJ_obj2nid(pXVar10->algorithm);
    if ((((iVar3 == 0) || (iVar3 = OBJ_find_sigid_algs(iVar3,aiStack_2c,&local_30), iVar3 == 0)) ||
        (pEVar5 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_30), pEVar5 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar5 + 0x50) == (code *)0x0)) {
      iVar3 = BIO_puts(bp,"\n");
      if (iVar3 < 1) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = (**(code **)(pEVar5 + 0x50))(bp,pXVar10,0,9,0);
    }
    if (iVar3 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1b)) {
    iVar3 = BIO_printf(bp,"        Issuer:%c",uVar11);
    if (iVar3 < 1) {
      return 0;
    }
    pXVar4 = X509_get_issuer_name(x);
    iVar3 = X509_NAME_print_ex(bp,pXVar4,iVar12,nmflag);
    if (iVar3 < 0) {
      return 0;
    }
    iVar3 = BIO_write(bp,"\n",1);
    if (iVar3 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x1a)) {
    iVar3 = BIO_write(bp,"        Validity\n",0x11);
    if (iVar3 < 1) {
      return 0;
    }
    iVar3 = BIO_write(bp,"            Not Before: ",0x18);
    if (iVar3 < 1) {
      return 0;
    }
    pAVar6 = x->cert_info->validity->notBefore;
    if (pAVar6->type == 0x17) {
      iVar3 = ASN1_UTCTIME_print(bp,pAVar6);
    }
    else {
      if (pAVar6->type != 0x18) goto LAB_000ba202;
      iVar3 = ASN1_GENERALIZEDTIME_print(bp,pAVar6);
    }
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = BIO_write(bp,"\n            Not After : ",0x19);
    if (iVar3 < 1) {
      return 0;
    }
    pAVar6 = x->cert_info->validity->notAfter;
    if (pAVar6->type == 0x17) {
      iVar3 = ASN1_UTCTIME_print(bp,pAVar6);
    }
    else {
      if (pAVar6->type != 0x18) {
LAB_000ba202:
        BIO_write(bp,"Bad time value",0xe);
        return 0;
      }
      iVar3 = ASN1_GENERALIZEDTIME_print(bp,pAVar6);
    }
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = BIO_write(bp,"\n",1);
    if (iVar3 < 1) {
      return 0;
    }
  }
  if (-1 < (int)(cflag << 0x19)) {
    iVar3 = BIO_printf(bp,"        Subject:%c",uVar11);
    if (iVar3 < 1) {
      return 0;
    }
    pXVar4 = X509_get_subject_name(x);
    iVar12 = X509_NAME_print_ex(bp,pXVar4,iVar12,nmflag);
    if (iVar12 < 0) {
      return 0;
    }
    iVar12 = BIO_write(bp,"\n",1);
    if (iVar12 < 1) {
      return 0;
    }
  }
  if ((cflag & 0x80) == 0) {
    iVar12 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
    if (iVar12 < 1) {
      return 0;
    }
    iVar12 = BIO_printf(bp,"%12sPublic Key Algorithm: ","");
    if (iVar12 < 1) {
      return 0;
    }
    iVar12 = i2a_ASN1_OBJECT(bp,pXVar7->key->algor->algorithm);
    if (iVar12 < 1) {
      return 0;
    }
    iVar12 = BIO_puts(bp,"\n");
    if (iVar12 < 1) {
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
    X509V3_extensions_print(bp,"X509v3 extensions",pXVar7->extensions,cflag,8);
  }
  if ((-1 < (int)(cflag << 0x16)) &&
     (iVar12 = X509_signature_print(bp,x->sig_alg,x->signature), iVar12 < 1)) {
    return 0;
  }
  if ((cflag & 0x400) == 0) {
    iVar12 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
    if (iVar12 != 0) {
      iVar12 = 1;
    }
  }
  else {
    iVar12 = 1;
  }
  return iVar12;
}

