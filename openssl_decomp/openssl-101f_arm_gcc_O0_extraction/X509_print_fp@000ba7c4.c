
int X509_print_fp(FILE *bp,X509 *x)

{
  byte *pbVar1;
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar2;
  long lVar3;
  ASN1_INTEGER *a;
  int iVar4;
  X509_NAME *pXVar5;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  EVP_PKEY *pkey;
  ASN1_UTCTIME *pAVar7;
  char *pcVar8;
  undefined4 uVar9;
  X509_ALGOR *pXVar10;
  X509_CINF *pXVar11;
  int local_20;
  int iStack_1c;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x76,7,"t_x509.c",0x5a);
    return 0;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  pXVar11 = x->cert_info;
  iVar2 = BIO_write(bp_00,"Certificate:\n",0xd);
  if ((0 < iVar2) && (iVar2 = BIO_write(bp_00,"    Data:\n",10), 0 < iVar2)) {
    lVar3 = ASN1_INTEGER_get(x->cert_info->version);
    iVar2 = BIO_printf(bp_00,"%8sVersion: %lu (0x%lx)\n","",lVar3 + 1,lVar3);
    if ((0 < iVar2) && (iVar2 = BIO_write(bp_00,"        Serial Number:",0x16), 0 < iVar2)) {
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
        iVar2 = BIO_printf(bp_00," %s%lu (%s0x%lx)\n",pcVar8,iVar2,pcVar8,iVar2);
        if (0 < iVar2) {
LAB_000ba8c0:
          pXVar10 = x->sig_alg;
          iVar2 = BIO_puts(bp_00,"    Signature Algorithm: ");
          if ((0 < iVar2) && (iVar2 = i2a_ASN1_OBJECT(bp_00,pXVar10->algorithm), 0 < iVar2)) {
            iVar2 = OBJ_obj2nid(pXVar10->algorithm);
            if ((iVar2 == 0) ||
               (((iVar2 = OBJ_find_sigid_algs(iVar2,&iStack_1c,&local_20), iVar2 == 0 ||
                 (pEVar6 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_20),
                 pEVar6 == (EVP_PKEY_ASN1_METHOD *)0x0)) ||
                (*(code **)(pEVar6 + 0x50) == (code *)0x0)))) {
              iVar2 = BIO_puts(bp_00,"\n");
              if (iVar2 < 1) {
                iVar2 = 0;
              }
              else {
                iVar2 = 1;
              }
            }
            else {
              iVar2 = (**(code **)(pEVar6 + 0x50))(bp_00,pXVar10,0,9,0);
            }
            if ((0 < iVar2) && (iVar2 = BIO_printf(bp_00,"        Issuer:%c",0x20), 0 < iVar2)) {
              pXVar5 = X509_get_issuer_name(x);
              iVar2 = X509_NAME_print_ex(bp_00,pXVar5,0x10,0);
              if (((-1 < iVar2) &&
                  ((iVar2 = BIO_write(bp_00,"\n",1), 0 < iVar2 &&
                   (iVar2 = BIO_write(bp_00,"        Validity\n",0x11), 0 < iVar2)))) &&
                 (iVar2 = BIO_write(bp_00,"            Not Before: ",0x18), 0 < iVar2)) {
                pAVar7 = x->cert_info->validity->notBefore;
                if (pAVar7->type != 0x17) {
                  if (pAVar7->type == 0x18) {
                    iVar2 = ASN1_GENERALIZEDTIME_print(bp_00,pAVar7);
                    goto LAB_000baa32;
                  }
LAB_000ba97e:
                  BIO_write(bp_00,"Bad time value",0xe);
                  iVar2 = 0;
                  goto LAB_000ba9ce;
                }
                iVar2 = ASN1_UTCTIME_print(bp_00,pAVar7);
LAB_000baa32:
                if ((iVar2 != 0) &&
                   (iVar2 = BIO_write(bp_00,"\n            Not After : ",0x19), 0 < iVar2)) {
                  pAVar7 = x->cert_info->validity->notAfter;
                  if (pAVar7->type == 0x17) {
                    iVar2 = ASN1_UTCTIME_print(bp_00,pAVar7);
                  }
                  else {
                    if (pAVar7->type != 0x18) goto LAB_000ba97e;
                    iVar2 = ASN1_GENERALIZEDTIME_print(bp_00,pAVar7);
                  }
                  if (((iVar2 != 0) && (iVar2 = BIO_write(bp_00,"\n",1), 0 < iVar2)) &&
                     (iVar2 = BIO_printf(bp_00,"        Subject:%c",0x20), 0 < iVar2)) {
                    pXVar5 = X509_get_subject_name(x);
                    iVar2 = X509_NAME_print_ex(bp_00,pXVar5,0x10,0);
                    if ((((-1 < iVar2) && (iVar2 = BIO_write(bp_00,"\n",1), 0 < iVar2)) &&
                        ((iVar2 = BIO_write(bp_00,"        Subject Public Key Info:\n",0x21),
                         0 < iVar2 &&
                         ((iVar2 = BIO_printf(bp_00,"%12sPublic Key Algorithm: ",""), 0 < iVar2 &&
                          (iVar2 = i2a_ASN1_OBJECT(bp_00,pXVar11->key->algor->algorithm), 0 < iVar2)
                          ))))) && (iVar2 = BIO_puts(bp_00,"\n"), 0 < iVar2)) {
                      pkey = X509_get_pubkey(x);
                      if (pkey == (EVP_PKEY *)0x0) {
                        BIO_printf(bp_00,"%12sUnable to load Public Key\n","");
                        ERR_print_errors(bp_00);
                      }
                      else {
                        EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
                        EVP_PKEY_free(pkey);
                      }
                      X509V3_extensions_print(bp_00,"X509v3 extensions",pXVar11->extensions,0,8);
                      iVar2 = X509_signature_print(bp_00,x->sig_alg,x->signature);
                      if (0 < iVar2) {
                        iVar2 = X509_CERT_AUX_print(bp_00,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0)
                        ;
                        if (iVar2 != 0) {
                          iVar2 = 1;
                        }
                        goto LAB_000ba9ce;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        pcVar8 = " (Negative)";
        if (a->type != 0x102) {
          pcVar8 = "";
        }
        iVar2 = BIO_printf(bp_00,"\n%12s%s","",pcVar8,lVar3);
        if (0 < iVar2) {
          iVar2 = 0;
          do {
            if (a->length <= iVar2) goto LAB_000ba8c0;
            pbVar1 = a->data + iVar2;
            iVar2 = iVar2 + 1;
            if (iVar2 == a->length) {
              uVar9 = 10;
            }
            else {
              uVar9 = 0x3a;
            }
            iVar4 = BIO_printf(bp_00,"%02x%c",(uint)*pbVar1,uVar9);
          } while (0 < iVar4);
        }
      }
    }
  }
  iVar2 = 0;
LAB_000ba9ce:
  BIO_free(bp_00);
  return iVar2;
}

