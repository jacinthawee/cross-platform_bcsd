
int X509_print_fp(FILE *bp,X509 *x)

{
  undefined *puVar1;
  undefined4 uVar2;
  BIO *bp_00;
  int iVar3;
  long lVar4;
  ASN1_INTEGER *a;
  uchar *puVar5;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  EVP_PKEY *pkey;
  char cVar8;
  int iVar7;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  ASN1_UTCTIME *a_00;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  X509_CINF *pXVar15;
  int local_34;
  undefined auStack_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar2);
  if (bp_00 == (BIO *)0x0) {
    pcVar12 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar14 = 0;
    goto LAB_00559490;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,bp);
  pXVar15 = x->cert_info;
  pcVar11 = "Certificate:\n";
  iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"Certificate:\n",0xd);
  if (iVar3 < 1) {
LAB_00559478:
    pcVar12 = pcVar11;
    uVar14 = 0;
  }
  else {
    pcVar11 = "    Data:\n";
    iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"    Data:\n",10);
    if (iVar3 < 1) goto LAB_00559478;
    lVar4 = ASN1_INTEGER_get(x->cert_info->version);
    pcVar11 = "%8sVersion: %lu (0x%lx)\n";
    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%8sVersion: %lu (0x%lx)\n","",lVar4 + 1,lVar4)
    ;
    if (iVar3 < 1) goto LAB_00559478;
    pcVar11 = "        Serial Number:";
    iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"        Serial Number:",0x16);
    if (iVar3 < 1) goto LAB_00559478;
    a = X509_get_serialNumber(x);
    if ((3 < a->length) && ((a->length != 4 || ((char)*a->data < '\0')))) {
      if (a->type == 0x102) {
        pcVar12 = " (Negative)";
      }
      else {
        pcVar12 = "";
      }
      pcVar11 = "\n%12s%s";
      iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n%12s%s","",pcVar12);
      if (0 < iVar3) {
        iVar3 = 0;
        do {
          if (a->length <= iVar3) goto LAB_005592c0;
          puVar5 = a->data + iVar3;
          iVar3 = iVar3 + 1;
          uVar2 = 10;
          if (iVar3 != a->length) {
            uVar2 = 0x3a;
          }
          pcVar11 = "%02x%c";
          iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%02x%c",*puVar5,uVar2);
        } while (0 < iVar7);
      }
      goto LAB_00559478;
    }
    iVar3 = ASN1_INTEGER_get(a);
    if (a->type == 0x102) {
      iVar3 = -iVar3;
      pcVar12 = "-";
    }
    else {
      pcVar12 = "";
    }
    pcVar11 = " %s%lu (%s0x%lx)\n";
    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp_00," %s%lu (%s0x%lx)\n",pcVar12,iVar3,pcVar12,iVar3);
    if (iVar3 < 1) goto LAB_00559478;
LAB_005592c0:
    pcVar12 = (char *)pXVar15->signature;
    pcVar11 = "    Signature Algorithm: ";
    iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
    if (iVar3 < 1) goto LAB_00559478;
    pcVar11 = (char *)*(stack_st_X509_NAME_ENTRY **)pcVar12;
    iVar3 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar11);
    if (iVar3 < 1) goto LAB_00559478;
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(stack_st_X509_NAME_ENTRY **)pcVar12);
    if ((((iVar3 == 0) ||
         (iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(iVar3,auStack_30,&local_34),
         iVar3 == 0)) ||
        (pEVar6 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34), pEVar6 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar6 + 0x50) == (code *)0x0)) {
      pcVar11 = "\n";
      iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
      if (0 < iVar3) goto LAB_00559328;
      goto LAB_00559478;
    }
    iVar3 = (**(code **)(pEVar6 + 0x50))(bp_00,pcVar12,0,9,0);
    if (0 < iVar3) {
LAB_00559328:
      pcVar11 = "        Issuer:%c";
      iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"        Issuer:%c",0x20);
      if (0 < iVar3) {
        pcVar11 = (char *)X509_get_issuer_name(x);
        iVar3 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar11,0x10,0);
        if (-1 < iVar3) {
          pcVar11 = "\n";
          iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
          if (0 < iVar3) {
            pcVar11 = "        Validity\n";
            iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"        Validity\n",0x11);
            if (0 < iVar3) {
              pcVar11 = "            Not Before: ";
              iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"            Not Before: ",0x18);
              if (0 < iVar3) {
                a_00 = x->cert_info->validity->notBefore;
                if (a_00->type != 0x17) {
                  if (a_00->type == 0x18) {
                    iVar3 = ASN1_GENERALIZEDTIME_print(bp_00,a_00);
                    goto LAB_0055957c;
                  }
LAB_005593fc:
                  pcVar12 = "Bad time value";
                  (*(code *)PTR_BIO_write_006a6e14)(bp_00,"Bad time value",0xe);
                  uVar14 = 0;
                  goto LAB_0055947c;
                }
                iVar3 = ASN1_UTCTIME_print(bp_00,a_00);
LAB_0055957c:
                pcVar11 = (char *)(ASN1_OBJECT *)0x670000;
                if (iVar3 != 0) {
                  pcVar11 = "\n            Not After : ";
                  iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n            Not After : ",0x19)
                  ;
                  if (0 < iVar3) {
                    pcVar11 = (char *)x->cert_info->validity->notAfter;
                    if (*(char ***)((int)pcVar11 + 4) == (char **)&DAT_00000017) {
                      iVar3 = ASN1_UTCTIME_print(bp_00,(ASN1_UTCTIME *)pcVar11);
                    }
                    else {
                      if (*(char ***)((int)pcVar11 + 4) != (char **)&DAT_00000018)
                      goto LAB_005593fc;
                      iVar3 = ASN1_GENERALIZEDTIME_print(bp_00,(ASN1_GENERALIZEDTIME *)pcVar11);
                    }
                    if (iVar3 != 0) {
                      pcVar11 = "\n";
                      iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
                      if (0 < iVar3) {
                        pcVar11 = "        Subject:%c";
                        iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"        Subject:%c",0x20);
                        if (0 < iVar3) {
                          pcVar11 = (char *)X509_get_subject_name(x);
                          iVar3 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar11,0x10,0);
                          if (-1 < iVar3) {
                            pcVar11 = "\n";
                            iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
                            if (0 < iVar3) {
                              pcVar11 = "        Subject Public Key Info:\n";
                              iVar3 = (*(code *)PTR_BIO_write_006a6e14)
                                                (bp_00,"        Subject Public Key Info:\n",0x21);
                              if (0 < iVar3) {
                                pcVar11 = "%12sPublic Key Algorithm: ";
                                iVar3 = (*(code *)PTR_BIO_printf_006a6e38)
                                                  (bp_00,"%12sPublic Key Algorithm: ","");
                                if (0 < iVar3) {
                                  pcVar11 = (char *)pXVar15->key->algor->algorithm;
                                  iVar3 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar11);
                                  if (0 < iVar3) {
                                    pcVar11 = "\n";
                                    iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
                                    if (0 < iVar3) {
                                      pkey = X509_get_pubkey(x);
                                      if (pkey == (EVP_PKEY *)0x0) {
                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                  (bp_00,"%12sUnable to load Public Key\n","");
                                        (*(code *)PTR_ERR_print_errors_006a6e40)(bp_00);
                                      }
                                      else {
                                        EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
                                        EVP_PKEY_free(pkey);
                                      }
                                      (*(code *)PTR_X509V3_extensions_print_006a8d60)
                                                (bp_00,"X509v3 extensions",pXVar15->extensions,0,8);
                                      pcVar11 = (char *)x->sig_alg;
                                      iVar3 = X509_signature_print
                                                        (bp_00,(X509_ALGOR *)pcVar11,x->signature);
                                      if (0 < iVar3) {
                                        pcVar12 = *(char **)(x->sha1_hash + 0xc);
                                        iVar3 = X509_CERT_AUX_print(bp_00,(X509_CERT_AUX *)pcVar12,0
                                                                   );
                                        uVar14 = (uint)(iVar3 != 0);
                                        goto LAB_0055947c;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_00559478;
    }
    uVar14 = 0;
  }
LAB_0055947c:
  (*(code *)PTR_BIO_free_006a6e70)(bp_00);
LAB_00559490:
  if (local_2c == *(int *)puVar1) {
    return uVar14;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pcVar12 = X509_NAME_oneline((X509_NAME *)pcVar12,(char *)0x0,0);
  if (pcVar12 == (char *)0x0) {
    return 0;
  }
  pcVar11 = pcVar12 + 2;
  if (*pcVar12 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar12);
    return 1;
  }
  cVar8 = pcVar12[1];
  pcVar9 = pcVar12 + 1;
  if (cVar8 == '/') goto LAB_00559908;
LAB_0055985c:
  pcVar10 = pcVar9;
  pcVar13 = pcVar11;
  if (cVar8 != '\0') goto LAB_005598fc;
  while (pcVar9 = pcVar11,
        pcVar11 = (char *)(*(code *)PTR_BIO_write_006a6e14)
                                    (iVar3,pcVar10,pcVar9 + (-1 - (int)pcVar10)),
        pcVar9 + (-1 - (int)pcVar10) == pcVar11) {
    if (pcVar9[-1] == '\0') {
LAB_00559894:
      iVar3 = 1;
      goto LAB_00559898;
    }
    iVar7 = (*(code *)PTR_BIO_write_006a6e14)(iVar3,", ",2);
    if (iVar7 != 2) break;
    pcVar13 = pcVar9;
    if (pcVar9[-1] == '\0') goto LAB_00559894;
LAB_005598fc:
    do {
      pcVar11 = pcVar13 + 1;
      cVar8 = *pcVar13;
      if (cVar8 != '/') goto LAB_0055985c;
LAB_00559908:
      pcVar13 = pcVar11;
    } while ((0x19 < (byte)(*pcVar11 + 0xbfU)) ||
            ((pcVar10 = pcVar9, pcVar11[1] != 0x3d &&
             ((0x19 < ((int)pcVar11[1] - 0x41U & 0xff) || (pcVar11[2] != '='))))));
  }
  iVar3 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x75,7,"t_x509.c",0x219);
LAB_00559898:
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar12);
  return iVar3;
}

