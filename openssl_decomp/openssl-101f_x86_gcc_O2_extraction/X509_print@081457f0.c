
int X509_print(BIO *bp,X509 *x)

{
  X509_CINF *pXVar1;
  X509_ALGOR *pXVar2;
  ASN1_GENERALIZEDTIME *pAVar3;
  int iVar4;
  long lVar5;
  ASN1_INTEGER *a;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  X509_NAME *pXVar9;
  uint uVar10;
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar11;
  undefined1 *puVar12;
  int in_GS_OFFSET;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pXVar1 = x->cert_info;
  iVar4 = BIO_write(bp,"Certificate:\n",0xd);
  if ((0 < iVar4) && (iVar4 = BIO_write(bp,"    Data:\n",10), 0 < iVar4)) {
    lVar5 = ASN1_INTEGER_get(x->cert_info->version);
    iVar4 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n",&DAT_081ec74a,lVar5 + 1,lVar5);
    if ((0 < iVar4) && (iVar4 = BIO_write(bp,"        Serial Number:",0x16), 0 < iVar4)) {
      a = X509_get_serialNumber(x);
      if (a->length < 5) {
        lVar5 = ASN1_INTEGER_get(a);
        puVar12 = &DAT_081ec74a;
        if (a->type == 0x102) {
          lVar5 = -lVar5;
          puVar12 = &DAT_0823b414;
        }
        iVar4 = BIO_printf(bp," %s%lu (%s0x%lx)\n",puVar12,lVar5,puVar12,lVar5);
        if (0 < iVar4) {
LAB_08145910:
          pXVar2 = x->sig_alg;
          iVar4 = BIO_puts(bp,"    Signature Algorithm: ");
          if ((0 < iVar4) && (iVar4 = i2a_ASN1_OBJECT(bp,pXVar2->algorithm), 0 < iVar4)) {
            iVar4 = OBJ_obj2nid(pXVar2->algorithm);
            if ((iVar4 == 0) ||
               (((iVar4 = OBJ_find_sigid_algs(iVar4,&local_24,&local_28), iVar4 == 0 ||
                 (pEVar11 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_28),
                 pEVar11 == (EVP_PKEY_ASN1_METHOD *)0x0)) ||
                (*(code **)(pEVar11 + 0x50) == (code *)0x0)))) {
              iVar4 = BIO_puts(bp,"\n");
            }
            else {
              iVar4 = (**(code **)(pEVar11 + 0x50))(bp,pXVar2,0,9,0);
            }
            if ((0 < iVar4) && (iVar4 = BIO_printf(bp,"        Issuer:%c",0x20), 0 < iVar4)) {
              pXVar9 = X509_get_issuer_name(x);
              iVar4 = X509_NAME_print_ex(bp,pXVar9,0x10,0);
              if (((-1 < iVar4) &&
                  ((iVar4 = BIO_write(bp,&DAT_081f11d3,1), 0 < iVar4 &&
                   (iVar4 = BIO_write(bp,"        Validity\n",0x11), 0 < iVar4)))) &&
                 (iVar4 = BIO_write(bp,"            Not Before: ",0x18), 0 < iVar4)) {
                pAVar3 = x->cert_info->validity->notBefore;
                if (pAVar3->type != 0x17) {
                  if (pAVar3->type == 0x18) {
                    iVar4 = ASN1_GENERALIZEDTIME_print(bp,pAVar3);
                    goto LAB_08145a9d;
                  }
LAB_08145a11:
                  BIO_write(bp,"Bad time value",0xe);
                  uVar10 = 0;
                  goto LAB_08145a72;
                }
                iVar4 = ASN1_UTCTIME_print(bp,pAVar3);
LAB_08145a9d:
                if ((iVar4 != 0) &&
                   (iVar4 = BIO_write(bp,"\n            Not After : ",0x19), 0 < iVar4)) {
                  pAVar3 = x->cert_info->validity->notAfter;
                  if (pAVar3->type == 0x17) {
                    iVar4 = ASN1_UTCTIME_print(bp,pAVar3);
                  }
                  else {
                    if (pAVar3->type != 0x18) goto LAB_08145a11;
                    iVar4 = ASN1_GENERALIZEDTIME_print(bp,pAVar3);
                  }
                  if (((iVar4 != 0) && (iVar4 = BIO_write(bp,&DAT_081f11d3,1), 0 < iVar4)) &&
                     (iVar4 = BIO_printf(bp,"        Subject:%c",0x20), 0 < iVar4)) {
                    pXVar9 = X509_get_subject_name(x);
                    iVar4 = X509_NAME_print_ex(bp,pXVar9,0x10,0);
                    if ((((-1 < iVar4) && (iVar4 = BIO_write(bp,&DAT_081f11d3,1), 0 < iVar4)) &&
                        ((iVar4 = BIO_write(bp,"        Subject Public Key Info:\n",0x21), 0 < iVar4
                         && ((iVar4 = BIO_printf(bp,"%12sPublic Key Algorithm: ",&DAT_081ec74a),
                             0 < iVar4 &&
                             (iVar4 = i2a_ASN1_OBJECT(bp,pXVar1->key->algor->algorithm), 0 < iVar4))
                            )))) && (iVar4 = BIO_puts(bp,"\n"), 0 < iVar4)) {
                      pkey = X509_get_pubkey(x);
                      if (pkey == (EVP_PKEY *)0x0) {
                        BIO_printf(bp,"%12sUnable to load Public Key\n",&DAT_081ec74a);
                        ERR_print_errors(bp);
                      }
                      else {
                        EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
                        EVP_PKEY_free(pkey);
                      }
                      X509V3_extensions_print(bp,"X509v3 extensions",pXVar1->extensions,0,8);
                      iVar4 = X509_signature_print(bp,x->sig_alg,x->signature);
                      if (0 < iVar4) {
                        iVar4 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
                        uVar10 = (uint)(iVar4 != 0);
                        goto LAB_08145a72;
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
        pcVar6 = " (Negative)";
        if (a->type != 0x102) {
          pcVar6 = "";
        }
        iVar4 = BIO_printf(bp,"\n%12s%s",&DAT_081ec74a,pcVar6);
        if (0 < iVar4) {
          iVar4 = 0;
          do {
            if (a->length <= iVar4) goto LAB_08145910;
            uVar7 = 10;
            if (iVar4 + 1 != a->length) {
              uVar7 = 0x3a;
            }
            iVar8 = BIO_printf(bp,"%02x%c",(uint)a->data[iVar4],uVar7);
            iVar4 = iVar4 + 1;
          } while (0 < iVar8);
        }
      }
    }
  }
  uVar10 = 0;
LAB_08145a72:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

