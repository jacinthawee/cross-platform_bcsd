
int X509_print_ex_fp(FILE *bp,X509 *x,ulong nmflag,ulong cflag)

{
  undefined *puVar1;
  undefined4 uVar2;
  BIO *bp_00;
  long lVar3;
  ASN1_INTEGER *a;
  uchar *puVar4;
  undefined4 uVar5;
  int iVar6;
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar7;
  char cVar9;
  int iVar8;
  X509_CINF *pXVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  ASN1_UTCTIME *pAVar14;
  char *pcVar15;
  char *pcVar16;
  uint uVar17;
  int iVar18;
  char *local_3c;
  int local_34;
  undefined auStack_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (bp_00 == (BIO *)0x0) {
    pcVar13 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar17 = 0;
    goto LAB_0055c87c;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(bp_00,0x6a,0,bp);
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar18 = 0xc;
    uVar2 = 10;
  }
  else {
    iVar18 = 0x10;
    uVar2 = 0x20;
    if (nmflag != 0) {
      iVar18 = 0;
    }
  }
  pXVar10 = x->cert_info;
  if ((cflag & 1) == 0) {
    pcVar15 = "Certificate:\n";
    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"Certificate:\n",0xd);
    if (0 < iVar8) {
      pcVar15 = "    Data:\n";
      iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"    Data:\n",10);
      if (0 < iVar8) goto LAB_0055c7a8;
    }
LAB_0055c864:
    pcVar13 = pcVar15;
    uVar17 = 0;
  }
  else {
LAB_0055c7a8:
    if ((cflag & 2) == 0) {
      lVar3 = ASN1_INTEGER_get(x->cert_info->version);
      pcVar15 = "%8sVersion: %lu (0x%lx)\n";
      iVar8 = (*(code *)PTR_BIO_printf_006a7f38)
                        (bp_00,"%8sVersion: %lu (0x%lx)\n","",lVar3 + 1,lVar3);
      if (iVar8 < 1) goto LAB_0055c864;
    }
    if ((cflag & 4) == 0) {
      pcVar15 = "        Serial Number:";
      iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"        Serial Number:",0x16);
      if (0 < iVar8) {
        a = X509_get_serialNumber(x);
        if (a->length < 5) {
          iVar8 = ASN1_INTEGER_get(a);
          if (a->type == 0x102) {
            iVar8 = -iVar8;
            pcVar15 = "-";
          }
          else {
            pcVar15 = "";
          }
          pcVar13 = " %s%lu (%s0x%lx)\n";
          iVar8 = (*(code *)PTR_BIO_printf_006a7f38)
                            (bp_00," %s%lu (%s0x%lx)\n",pcVar15,iVar8,pcVar15,iVar8);
          if (0 < iVar8) goto LAB_0055c7c0;
          uVar17 = 0;
        }
        else {
          if (a->type == 0x102) {
            pcVar13 = " (Negative)";
          }
          else {
            pcVar13 = "";
          }
          pcVar15 = "\n%12s%s";
          iVar8 = (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"\n%12s%s","",pcVar13);
          if (iVar8 < 1) goto LAB_0055c864;
          iVar8 = 0;
          local_3c = "%02x%c";
          do {
            if (a->length <= iVar8) goto LAB_0055c7c0;
            puVar4 = a->data + iVar8;
            iVar8 = iVar8 + 1;
            uVar5 = 10;
            if (iVar8 != a->length) {
              uVar5 = 0x3a;
            }
            pcVar13 = local_3c;
            iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"%02x%c",*puVar4,uVar5);
          } while (0 < iVar6);
          uVar17 = 0;
        }
        goto LAB_0055c868;
      }
      goto LAB_0055c864;
    }
LAB_0055c7c0:
    if ((cflag & 8) != 0) goto LAB_0055c7c8;
    pcVar13 = (char *)x->sig_alg;
    pcVar15 = "    Signature Algorithm: ";
    iVar8 = (*(code *)PTR_BIO_puts_006a8058)(bp_00);
    if (iVar8 < 1) goto LAB_0055c864;
    pcVar15 = (char *)*(stack_st_X509_NAME_ENTRY **)pcVar13;
    iVar8 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar15);
    if (iVar8 < 1) goto LAB_0055c864;
    iVar8 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(stack_st_X509_NAME_ENTRY **)pcVar13);
    if ((((iVar8 == 0) ||
         (iVar8 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(iVar8,auStack_30,&local_34),
         iVar8 == 0)) ||
        (pEVar7 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34), pEVar7 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar7 + 0x50) == (code *)0x0)) {
      pcVar13 = "\n";
      iVar8 = (*(code *)PTR_BIO_puts_006a8058)(bp_00);
      if (0 < iVar8) goto LAB_0055c7c8;
      uVar17 = 0;
    }
    else {
      iVar8 = (**(code **)(pEVar7 + 0x50))(bp_00,pcVar13,0,9,0);
      if (0 < iVar8) {
LAB_0055c7c8:
        if ((cflag & 0x10) == 0) {
          pcVar15 = "        Issuer:%c";
          iVar8 = (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"        Issuer:%c",uVar2);
          if (0 < iVar8) {
            pcVar15 = (char *)X509_get_issuer_name(x);
            iVar8 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar15,iVar18,nmflag);
            if (-1 < iVar8) {
              pcVar13 = "\n";
              iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"\n",1);
              if (iVar8 < 1) {
                uVar17 = 0;
                goto LAB_0055c868;
              }
              goto LAB_0055c7d4;
            }
          }
          goto LAB_0055c864;
        }
LAB_0055c7d4:
        if ((cflag & 0x20) == 0) {
          pcVar15 = "        Validity\n";
          iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"        Validity\n",0x11);
          if (0 < iVar8) {
            pcVar15 = "            Not Before: ";
            iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"            Not Before: ",0x18);
            if (0 < iVar8) {
              pAVar14 = x->cert_info->validity->notBefore;
              if (pAVar14->type != 0x17) {
                if (pAVar14->type == 0x18) {
                  iVar8 = ASN1_GENERALIZEDTIME_print(bp_00,pAVar14);
                  goto LAB_0055cd88;
                }
LAB_0055cbec:
                pcVar13 = "Bad time value";
                (*(code *)PTR_BIO_write_006a7f14)(bp_00,"Bad time value",0xe);
                uVar17 = 0;
                goto LAB_0055c868;
              }
              iVar8 = ASN1_UTCTIME_print(bp_00,pAVar14);
LAB_0055cd88:
              pcVar15 = (char *)(EVP_PKEY *)0x670000;
              if (iVar8 != 0) {
                pcVar15 = "\n            Not After : ";
                iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"\n            Not After : ",0x19);
                if (0 < iVar8) {
                  pAVar14 = x->cert_info->validity->notAfter;
                  if (pAVar14->type == 0x17) {
                    iVar8 = ASN1_UTCTIME_print(bp_00,pAVar14);
                  }
                  else {
                    if (pAVar14->type != 0x18) goto LAB_0055cbec;
                    iVar8 = ASN1_GENERALIZEDTIME_print(bp_00,pAVar14);
                  }
                  pcVar15 = (char *)(EVP_PKEY *)0x640000;
                  if (iVar8 != 0) {
                    pcVar13 = "\n";
                    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"\n",1);
                    if (0 < iVar8) goto LAB_0055c7e0;
                    uVar17 = 0;
                    goto LAB_0055c868;
                  }
                }
              }
            }
          }
        }
        else {
LAB_0055c7e0:
          if ((cflag & 0x40) == 0) {
            pcVar15 = "        Subject:%c";
            iVar8 = (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"        Subject:%c",uVar2);
            if (0 < iVar8) {
              pcVar15 = (char *)X509_get_subject_name(x);
              iVar18 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar15,iVar18,nmflag);
              if (-1 < iVar18) {
                pcVar13 = "\n";
                iVar18 = (*(code *)PTR_BIO_write_006a7f14)(bp_00,"\n",1);
                if (iVar18 < 1) {
                  uVar17 = 0;
                  goto LAB_0055c868;
                }
                goto LAB_0055c7ec;
              }
            }
          }
          else {
LAB_0055c7ec:
            pcVar13 = "7 datafinal";
            if ((cflag & 0x80) != 0) {
LAB_0055c7f8:
              if ((cflag & 0x100) == 0) {
                pcVar13 = "X509v3 extensions";
                (*(code *)PTR_X509V3_extensions_print_006a9e80)
                          (bp_00,"X509v3 extensions",pXVar10->extensions,cflag,8);
              }
              if ((cflag & 0x200) == 0) {
                pcVar13 = (char *)x->sig_alg;
                iVar18 = X509_signature_print(bp_00,(X509_ALGOR *)pcVar13,x->signature);
                if (iVar18 < 1) {
                  uVar17 = 0;
                  goto LAB_0055c868;
                }
              }
              if ((cflag & 0x400) == 0) {
                pcVar13 = *(char **)(x->sha1_hash + 0xc);
                iVar18 = X509_CERT_AUX_print(bp_00,(X509_CERT_AUX *)pcVar13,0);
                uVar17 = (uint)(iVar18 != 0);
              }
              else {
                uVar17 = 1;
              }
              goto LAB_0055c868;
            }
            pcVar15 = "        Subject Public Key Info:\n";
            iVar18 = (*(code *)PTR_BIO_write_006a7f14)
                               (bp_00,"        Subject Public Key Info:\n",0x21);
            if (0 < iVar18) {
              pcVar15 = "%12sPublic Key Algorithm: ";
              iVar18 = (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"%12sPublic Key Algorithm: ","");
              if (0 < iVar18) {
                pcVar15 = (char *)pXVar10->key->algor->algorithm;
                iVar18 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar15);
                if (0 < iVar18) {
                  pcVar15 = "\n";
                  iVar18 = (*(code *)PTR_BIO_puts_006a8058)(bp_00);
                  if (0 < iVar18) {
                    pkey = X509_get_pubkey(x);
                    if (pkey == (EVP_PKEY *)0x0) {
                      pcVar13 = "%12sUnable to load Public Key\n";
                      (*(code *)PTR_BIO_printf_006a7f38)(bp_00,"%12sUnable to load Public Key\n","")
                      ;
                      (*(code *)PTR_ERR_print_errors_006a7f40)(bp_00);
                    }
                    else {
                      pcVar13 = (char *)pkey;
                      EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
                      EVP_PKEY_free(pkey);
                    }
                    goto LAB_0055c7f8;
                  }
                }
              }
            }
          }
        }
        goto LAB_0055c864;
      }
      uVar17 = 0;
    }
  }
LAB_0055c868:
  (*(code *)PTR_BIO_free_006a7f70)(bp_00);
LAB_0055c87c:
  if (local_2c == *(int *)puVar1) {
    return uVar17;
  }
  iVar18 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcVar13 = X509_NAME_oneline((X509_NAME *)pcVar13,(char *)0x0,0);
  if (*pcVar13 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar13);
    return 1;
  }
  pcVar15 = pcVar13 + 2;
  cVar9 = pcVar13[1];
  pcVar11 = pcVar13 + 1;
  if (cVar9 == '/') goto LAB_0055cffc;
LAB_0055cf50:
  pcVar12 = pcVar11;
  pcVar16 = pcVar15;
  if (cVar9 != '\0') goto LAB_0055cff0;
  while (pcVar11 = pcVar15,
        pcVar15 = (char *)(*(code *)PTR_BIO_write_006a7f14)
                                    (iVar18,pcVar12,pcVar11 + (-1 - (int)pcVar12)),
        pcVar11 + (-1 - (int)pcVar12) == pcVar15) {
    if (pcVar11[-1] == '\0') {
LAB_0055cf88:
      iVar18 = 1;
      goto LAB_0055cf8c;
    }
    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(iVar18,", ",2);
    if (iVar8 != 2) break;
    pcVar16 = pcVar11;
    if (pcVar11[-1] == '\0') goto LAB_0055cf88;
LAB_0055cff0:
    do {
      pcVar15 = pcVar16 + 1;
      cVar9 = *pcVar16;
      if (cVar9 != '/') goto LAB_0055cf50;
LAB_0055cffc:
      pcVar16 = pcVar15;
    } while ((0x19 < (byte)(*pcVar15 + 0xbfU)) ||
            ((pcVar12 = pcVar11, pcVar15[1] != 0x3d &&
             ((0x19 < ((int)pcVar15[1] - 0x41U & 0xff) || (pcVar15[2] != '='))))));
  }
  iVar18 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x75,7,"t_x509.c",0x20c);
LAB_0055cf8c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar13);
  return iVar18;
}

