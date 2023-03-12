
int X509_print(BIO *bp,X509 *x)

{
  byte *pbVar1;
  int iVar2;
  long lVar3;
  ASN1_INTEGER *a;
  int iVar4;
  X509_NAME *pXVar5;
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  ASN1_UTCTIME *pAVar7;
  char *pcVar8;
  undefined4 uVar9;
  X509_ALGOR *pXVar10;
  X509_CINF *pXVar11;
  int local_20;
  int iStack_1c;
  
  pXVar11 = x->cert_info;
  iVar2 = BIO_write(bp,"Certificate:\n",0xd);
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = BIO_write(bp,"    Data:\n",10);
  if (iVar2 < 1) {
    return 0;
  }
  lVar3 = ASN1_INTEGER_get(x->cert_info->version);
  iVar2 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n","",lVar3 + 1,lVar3);
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = BIO_write(bp,"        Serial Number:",0x16);
  if (iVar2 < 1) {
    return 0;
  }
  a = X509_get_serialNumber(x);
  if (a->length < 5) {
    iVar2 = ASN1_INTEGER_get(a);
    if (a->type == 0x102) {
      pcVar8 = "-";
      iVar2 = -iVar2;
    }
    else {
      pcVar8 = "";
    }
    iVar2 = BIO_printf(bp," %s%lu (%s0x%lx)\n",pcVar8,iVar2,pcVar8,iVar2);
    if (iVar2 < 1) {
      return 0;
    }
  }
  else {
    pcVar8 = " (Negative)";
    if (a->type != 0x102) {
      pcVar8 = "";
    }
    iVar2 = BIO_printf(bp,"\n%12s%s","",pcVar8,lVar3);
    if (iVar2 < 1) {
      return 0;
    }
    iVar2 = 0;
    while (iVar2 < a->length) {
      pbVar1 = a->data + iVar2;
      iVar2 = iVar2 + 1;
      if (iVar2 == a->length) {
        uVar9 = 10;
      }
      else {
        uVar9 = 0x3a;
      }
      iVar4 = BIO_printf(bp,"%02x%c",(uint)*pbVar1,uVar9);
      if (iVar4 < 1) {
        return 0;
      }
    }
  }
  pXVar10 = x->sig_alg;
  iVar2 = BIO_puts(bp,"    Signature Algorithm: ");
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = i2a_ASN1_OBJECT(bp,pXVar10->algorithm);
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = OBJ_obj2nid(pXVar10->algorithm);
  if ((((iVar2 == 0) || (iVar2 = OBJ_find_sigid_algs(iVar2,&iStack_1c,&local_20), iVar2 == 0)) ||
      (pEVar6 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_20), pEVar6 == (EVP_PKEY_ASN1_METHOD *)0x0))
     || (*(code **)(pEVar6 + 0x50) == (code *)0x0)) {
    iVar2 = BIO_puts(bp,"\n");
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = (**(code **)(pEVar6 + 0x50))(bp,pXVar10,0,9,0);
  }
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = BIO_printf(bp,"        Issuer:%c",0x20);
  if (iVar2 < 1) {
    return 0;
  }
  pXVar5 = X509_get_issuer_name(x);
  iVar2 = X509_NAME_print_ex(bp,pXVar5,0x10,0);
  if (iVar2 < 0) {
    return 0;
  }
  iVar2 = BIO_write(bp,"\n",1);
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = BIO_write(bp,"        Validity\n",0x11);
  if (iVar2 < 1) {
    return 0;
  }
  iVar2 = BIO_write(bp,"            Not Before: ",0x18);
  if (iVar2 < 1) {
    return 0;
  }
  pAVar7 = x->cert_info->validity->notBefore;
  if (pAVar7->type == 0x17) {
    iVar2 = ASN1_UTCTIME_print(bp,pAVar7);
LAB_000ba62e:
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = BIO_write(bp,"\n            Not After : ",0x19);
    if (iVar2 < 1) {
      return 0;
    }
    pAVar7 = x->cert_info->validity->notAfter;
    if (pAVar7->type == 0x17) {
      iVar2 = ASN1_UTCTIME_print(bp,pAVar7);
    }
    else {
      if (pAVar7->type != 0x18) goto LAB_000ba5d2;
      iVar2 = ASN1_GENERALIZEDTIME_print(bp,pAVar7);
    }
    if (((iVar2 != 0) && (iVar2 = BIO_write(bp,"\n",1), 0 < iVar2)) &&
       (iVar2 = BIO_printf(bp,"        Subject:%c",0x20), 0 < iVar2)) {
      pXVar5 = X509_get_subject_name(x);
      iVar2 = X509_NAME_print_ex(bp,pXVar5,0x10,0);
      if (((-1 < iVar2) && (iVar2 = BIO_write(bp,"\n",1), 0 < iVar2)) &&
         ((iVar2 = BIO_write(bp,"        Subject Public Key Info:\n",0x21), 0 < iVar2 &&
          (((iVar2 = BIO_printf(bp,"%12sPublic Key Algorithm: ",""), 0 < iVar2 &&
            (iVar2 = i2a_ASN1_OBJECT(bp,pXVar11->key->algor->algorithm), 0 < iVar2)) &&
           (iVar2 = BIO_puts(bp,"\n"), 0 < iVar2)))))) {
        pkey = X509_get_pubkey(x);
        if (pkey == (EVP_PKEY *)0x0) {
          BIO_printf(bp,"%12sUnable to load Public Key\n","");
          ERR_print_errors(bp);
        }
        else {
          EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
          EVP_PKEY_free(pkey);
        }
        X509V3_extensions_print(bp,"X509v3 extensions",pXVar11->extensions,0,8);
        iVar2 = X509_signature_print(bp,x->sig_alg,x->signature);
        if (0 < iVar2) {
          iVar2 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
          if (iVar2 != 0) {
            iVar2 = 1;
          }
          return iVar2;
        }
      }
    }
  }
  else {
    if (pAVar7->type == 0x18) {
      iVar2 = ASN1_GENERALIZEDTIME_print(bp,pAVar7);
      goto LAB_000ba62e;
    }
LAB_000ba5d2:
    BIO_write(bp,"Bad time value",0xe);
  }
  return 0;
}

