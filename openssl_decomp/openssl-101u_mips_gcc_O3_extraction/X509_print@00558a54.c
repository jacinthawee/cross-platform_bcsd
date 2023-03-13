
int X509_print(BIO *bp,X509 *x)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  BIO *bp_00;
  long lVar5;
  ASN1_INTEGER *a;
  uchar *puVar6;
  EVP_PKEY_ASN1_METHOD *pEVar7;
  EVP_PKEY *pkey;
  char cVar9;
  int iVar8;
  char *pcVar10;
  char *pcVar11;
  ASN1_UTCTIME *pAVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *unaff_s2;
  char *unaff_s4;
  X509_CINF *pXVar16;
  char *unaff_s6;
  ASN1_INTEGER *unaff_s7;
  undefined4 unaff_s8;
  int iStack_8c;
  undefined auStack_88 [4];
  int iStack_84;
  BIO *pBStack_80;
  X509 *pXStack_7c;
  X509 *pXStack_78;
  undefined *puStack_74;
  char *pcStack_70;
  X509_CINF *pXStack_6c;
  char *pcStack_68;
  ASN1_INTEGER *pAStack_64;
  undefined4 uStack_60;
  code *pcStack_5c;
  char *local_48;
  int local_44;
  undefined *local_40;
  int local_34;
  undefined auStack_30 [4];
  int local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  pcVar11 = "Certificate:\n";
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pXStack_6c = x->cert_info;
  iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"Certificate:\n",0xd);
  if (iVar2 < 1) {
LAB_00558db4:
    uVar3 = 0;
  }
  else {
    pcVar11 = "    Data:\n";
    iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"    Data:\n",10);
    if (iVar2 < 1) goto LAB_00558db4;
    unaff_s4 = "-check_ss_sig";
    local_48 = (char *)ASN1_INTEGER_get(x->cert_info->version);
    pcVar11 = "%8sVersion: %lu (0x%lx)\n";
    iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"%8sVersion: %lu (0x%lx)\n","",local_48 + 1);
    if (iVar2 < 1) goto LAB_00558db4;
    pcVar11 = "        Serial Number:";
    iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"        Serial Number:",0x16);
    if (iVar2 < 1) goto LAB_00558db4;
    unaff_s7 = X509_get_serialNumber(x);
    if ((3 < unaff_s7->length) && ((unaff_s7->length != 4 || ((char)*unaff_s7->data < '\0')))) {
      if (unaff_s7->type == 0x102) {
        pcVar14 = " (Negative)";
      }
      else {
        pcVar14 = "";
      }
      pcVar11 = "\n%12s%s";
      iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"\n%12s%s","",pcVar14);
      if (0 < iVar2) {
        unaff_s2 = (char *)0x0;
        unaff_s8 = 0x3a;
        unaff_s6 = "%02x%c";
        do {
          if ((int)(X509 *)unaff_s7->length <= (int)unaff_s2) goto LAB_00558bfc;
          puVar6 = unaff_s7->data + (int)unaff_s2;
          unaff_s2 = (char *)((int)(X509_CINF **)unaff_s2 + 1);
          uVar4 = 10;
          if ((X509 *)unaff_s2 != (X509 *)unaff_s7->length) {
            uVar4 = 0x3a;
          }
          pcVar11 = unaff_s6;
          iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"%02x%c",*puVar6,uVar4);
        } while (0 < iVar2);
      }
      goto LAB_00558db4;
    }
    local_44 = ASN1_INTEGER_get(unaff_s7);
    if (unaff_s7->type == 0x102) {
      local_44 = -local_44;
      local_48 = "-";
    }
    else {
      local_48 = "";
    }
    pcVar11 = " %s%lu (%s0x%lx)\n";
    iVar2 = (**(code **)(local_40 + -0x7fa8))(bp," %s%lu (%s0x%lx)\n",local_48,local_44);
    if (iVar2 < 1) goto LAB_00558db4;
LAB_00558bfc:
    unaff_s2 = (char *)pXStack_6c->signature;
    pcVar11 = "    Signature Algorithm: ";
    iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
    if (iVar2 < 1) goto LAB_00558db4;
    pcVar11 = (char *)*(X509_CINF **)unaff_s2;
    iVar2 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcVar11);
    if (iVar2 < 1) goto LAB_00558db4;
    iVar2 = (**(code **)(local_40 + -0x7cb4))(*(X509_CINF **)unaff_s2);
    if ((((iVar2 == 0) ||
         (iVar2 = (**(code **)(local_40 + -0x6a94))(iVar2,auStack_30,&local_34), iVar2 == 0)) ||
        (pEVar7 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34), pEVar7 == (EVP_PKEY_ASN1_METHOD *)0x0
        )) || (*(code **)(pEVar7 + 0x50) == (code *)0x0)) {
      pcVar11 = "\n";
      iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
      if (0 < iVar2) goto LAB_00558c64;
      goto LAB_00558db4;
    }
    local_48 = (char *)0x0;
    pcVar11 = unaff_s2;
    iVar2 = (**(code **)(pEVar7 + 0x50))(bp,unaff_s2,0,9);
    if (0 < iVar2) {
LAB_00558c64:
      pcVar11 = "        Issuer:%c";
      iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"        Issuer:%c",0x20);
      if (0 < iVar2) {
        pcVar11 = (char *)X509_get_issuer_name(x);
        iVar2 = X509_NAME_print_ex(bp,(X509_NAME *)pcVar11,0x10,0);
        if (-1 < iVar2) {
          unaff_s2 = "-check_ss_sig";
          pcVar11 = "\n";
          iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
          if (0 < iVar2) {
            pcVar11 = "        Validity\n";
            iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"        Validity\n",0x11);
            if (0 < iVar2) {
              pcVar11 = "            Not Before: ";
              iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"            Not Before: ",0x18);
              if (0 < iVar2) {
                pAVar12 = x->cert_info->validity->notBefore;
                if (pAVar12->type != 0x17) {
                  if (pAVar12->type == 0x18) {
                    iVar2 = ASN1_GENERALIZEDTIME_print(bp,pAVar12);
                    goto LAB_00558e10;
                  }
LAB_00558d38:
                  pcVar11 = "Bad time value";
                  (**(code **)(local_40 + -0x7fcc))(bp,"Bad time value",0xe);
                  uVar3 = 0;
                  goto LAB_00558db8;
                }
                iVar2 = ASN1_UTCTIME_print(bp,pAVar12);
LAB_00558e10:
                pcVar11 = "encrypt";
                if (iVar2 != 0) {
                  pcVar11 = "\n            Not After : ";
                  iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n            Not After : ",0x19);
                  if (0 < iVar2) {
                    pcVar11 = (char *)x->cert_info->validity->notAfter;
                    if (*(X509_ALGOR **)((int)pcVar11 + 4) == (X509_ALGOR *)&DAT_00000017) {
                      iVar2 = ASN1_UTCTIME_print(bp,(ASN1_UTCTIME *)pcVar11);
                    }
                    else {
                      if (*(X509_ALGOR **)((int)pcVar11 + 4) != (X509_ALGOR *)&DAT_00000018)
                      goto LAB_00558d38;
                      iVar2 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)pcVar11);
                    }
                    if (iVar2 != 0) {
                      pcVar11 = "\n";
                      iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
                      unaff_s2 = "-check_ss_sig";
                      if (0 < iVar2) {
                        pcVar11 = "        Subject:%c";
                        iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"        Subject:%c",0x20);
                        if (0 < iVar2) {
                          pcVar11 = (char *)X509_get_subject_name(x);
                          iVar2 = X509_NAME_print_ex(bp,(X509_NAME *)pcVar11,0x10,0);
                          if (-1 < iVar2) {
                            pcVar11 = "\n";
                            iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
                            if (0 < iVar2) {
                              pcVar11 = "        Subject Public Key Info:\n";
                              iVar2 = (**(code **)(local_40 + -0x7fcc))
                                                (bp,"        Subject Public Key Info:\n",0x21);
                              if (0 < iVar2) {
                                pcVar11 = "%12sPublic Key Algorithm: ";
                                iVar2 = (**(code **)(local_40 + -0x7fa8))
                                                  (bp,"%12sPublic Key Algorithm: ","");
                                if (0 < iVar2) {
                                  pcVar11 = (char *)pXStack_6c->key->algor->algorithm;
                                  iVar2 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcVar11);
                                  if (0 < iVar2) {
                                    pcVar11 = "\n";
                                    iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
                                    if (0 < iVar2) {
                                      unaff_s2 = (char *)X509_get_pubkey(x);
                                      if ((X509 *)unaff_s2 == (X509 *)0x0) {
                                        (**(code **)(local_40 + -0x7fa8))
                                                  (bp,"%12sUnable to load Public Key\n","");
                                        (**(code **)(local_40 + -0x7fa0))(bp);
                                      }
                                      else {
                                        EVP_PKEY_print_public
                                                  (bp,(EVP_PKEY *)unaff_s2,0x10,(ASN1_PCTX *)0x0);
                                        EVP_PKEY_free((EVP_PKEY *)unaff_s2);
                                      }
                                      local_48 = (char *)0x8;
                                      (**(code **)(local_40 + -0x6080))
                                                (bp,"X509v3 extensions",pXStack_6c->extensions,0);
                                      pcVar11 = (char *)x->sig_alg;
                                      iVar2 = X509_signature_print
                                                        (bp,(X509_ALGOR *)pcVar11,x->signature);
                                      if (0 < iVar2) {
                                        pcVar11 = *(char **)(x->sha1_hash + 0xc);
                                        iVar2 = X509_CERT_AUX_print(bp,(X509_CERT_AUX *)pcVar11,0);
                                        uVar3 = (uint)(iVar2 != 0);
                                        goto LAB_00558db8;
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
      goto LAB_00558db4;
    }
    uVar3 = 0;
  }
LAB_00558db8:
  if (local_2c == *(int *)puStack_74) {
    return uVar3;
  }
  pcStack_5c = X509_print_fp;
  iVar2 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pBStack_80 = bp;
  pXStack_7c = x;
  pXStack_78 = (X509 *)unaff_s2;
  pcStack_70 = unaff_s4;
  pcStack_68 = unaff_s6;
  pAStack_64 = unaff_s7;
  uStack_60 = unaff_s8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (bp_00 == (BIO *)0x0) {
    pcVar14 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar3 = 0;
    goto LAB_00559490;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,iVar2);
  pXVar16 = *(X509_CINF **)pcVar11;
  pcVar13 = "Certificate:\n";
  iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"Certificate:\n",0xd);
  if (iVar2 < 1) {
LAB_00559478:
    pcVar14 = pcVar13;
    uVar3 = 0;
  }
  else {
    pcVar13 = "    Data:\n";
    iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"    Data:\n",10);
    if (iVar2 < 1) goto LAB_00559478;
    lVar5 = ASN1_INTEGER_get((*(X509_CINF **)pcVar11)->version);
    pcVar13 = "%8sVersion: %lu (0x%lx)\n";
    iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%8sVersion: %lu (0x%lx)\n","",lVar5 + 1,lVar5)
    ;
    if (iVar2 < 1) goto LAB_00559478;
    pcVar13 = "        Serial Number:";
    iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"        Serial Number:",0x16);
    if (iVar2 < 1) goto LAB_00559478;
    a = X509_get_serialNumber((X509 *)pcVar11);
    if ((3 < a->length) && ((a->length != 4 || ((char)*a->data < '\0')))) {
      if (a->type == 0x102) {
        pcVar14 = " (Negative)";
      }
      else {
        pcVar14 = "";
      }
      pcVar13 = "\n%12s%s";
      iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"\n%12s%s","",pcVar14);
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          if (a->length <= iVar2) goto LAB_005592c0;
          puVar6 = a->data + iVar2;
          iVar2 = iVar2 + 1;
          uVar4 = 10;
          if (iVar2 != a->length) {
            uVar4 = 0x3a;
          }
          pcVar13 = "%02x%c";
          iVar8 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"%02x%c",*puVar6,uVar4);
        } while (0 < iVar8);
      }
      goto LAB_00559478;
    }
    iVar2 = ASN1_INTEGER_get(a);
    if (a->type == 0x102) {
      iVar2 = -iVar2;
      pcVar14 = "-";
    }
    else {
      pcVar14 = "";
    }
    pcVar13 = " %s%lu (%s0x%lx)\n";
    iVar2 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp_00," %s%lu (%s0x%lx)\n",pcVar14,iVar2,pcVar14,iVar2);
    if (iVar2 < 1) goto LAB_00559478;
LAB_005592c0:
    pcVar14 = (char *)pXVar16->signature;
    pcVar13 = "    Signature Algorithm: ";
    iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
    if (iVar2 < 1) goto LAB_00559478;
    pcVar13 = (char *)*(stack_st_X509_NAME_ENTRY **)pcVar14;
    iVar2 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar13);
    if (iVar2 < 1) goto LAB_00559478;
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(stack_st_X509_NAME_ENTRY **)pcVar14);
    if (((iVar2 == 0) ||
        (iVar2 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(iVar2,auStack_88,&iStack_8c),
        iVar2 == 0)) ||
       ((pEVar7 = EVP_PKEY_asn1_find((ENGINE **)0x0,iStack_8c),
        pEVar7 == (EVP_PKEY_ASN1_METHOD *)0x0 || (*(code **)(pEVar7 + 0x50) == (code *)0x0)))) {
      pcVar13 = "\n";
      iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
      if (0 < iVar2) goto LAB_00559328;
      goto LAB_00559478;
    }
    iVar2 = (**(code **)(pEVar7 + 0x50))(bp_00,pcVar14,0,9,0);
    if (0 < iVar2) {
LAB_00559328:
      pcVar13 = "        Issuer:%c";
      iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"        Issuer:%c",0x20);
      if (0 < iVar2) {
        pcVar13 = (char *)X509_get_issuer_name((X509 *)pcVar11);
        iVar2 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar13,0x10,0);
        if (-1 < iVar2) {
          pcVar13 = "\n";
          iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
          if (0 < iVar2) {
            pcVar13 = "        Validity\n";
            iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"        Validity\n",0x11);
            if (0 < iVar2) {
              pcVar13 = "            Not Before: ";
              iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"            Not Before: ",0x18);
              if (0 < iVar2) {
                pAVar12 = (*(X509_CINF **)pcVar11)->validity->notBefore;
                if (pAVar12->type != 0x17) {
                  if (pAVar12->type == 0x18) {
                    iVar2 = ASN1_GENERALIZEDTIME_print(bp_00,pAVar12);
                    goto LAB_0055957c;
                  }
LAB_005593fc:
                  pcVar14 = "Bad time value";
                  (*(code *)PTR_BIO_write_006a6e14)(bp_00,"Bad time value",0xe);
                  uVar3 = 0;
                  goto LAB_0055947c;
                }
                iVar2 = ASN1_UTCTIME_print(bp_00,pAVar12);
LAB_0055957c:
                pcVar13 = (char *)(ASN1_OBJECT *)0x670000;
                if (iVar2 != 0) {
                  pcVar13 = "\n            Not After : ";
                  iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n            Not After : ",0x19)
                  ;
                  if (0 < iVar2) {
                    pcVar13 = (char *)(*(X509_CINF **)pcVar11)->validity->notAfter;
                    if (*(char ***)((int)pcVar13 + 4) == (char **)&DAT_00000017) {
                      iVar2 = ASN1_UTCTIME_print(bp_00,(ASN1_UTCTIME *)pcVar13);
                    }
                    else {
                      if (*(char ***)((int)pcVar13 + 4) != (char **)&DAT_00000018)
                      goto LAB_005593fc;
                      iVar2 = ASN1_GENERALIZEDTIME_print(bp_00,(ASN1_GENERALIZEDTIME *)pcVar13);
                    }
                    if (iVar2 != 0) {
                      pcVar13 = "\n";
                      iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
                      if (0 < iVar2) {
                        pcVar13 = "        Subject:%c";
                        iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp_00,"        Subject:%c",0x20);
                        if (0 < iVar2) {
                          pcVar13 = (char *)X509_get_subject_name((X509 *)pcVar11);
                          iVar2 = X509_NAME_print_ex(bp_00,(X509_NAME *)pcVar13,0x10,0);
                          if (-1 < iVar2) {
                            pcVar13 = "\n";
                            iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp_00,"\n",1);
                            if (0 < iVar2) {
                              pcVar13 = "        Subject Public Key Info:\n";
                              iVar2 = (*(code *)PTR_BIO_write_006a6e14)
                                                (bp_00,"        Subject Public Key Info:\n",0x21);
                              if (0 < iVar2) {
                                pcVar13 = "%12sPublic Key Algorithm: ";
                                iVar2 = (*(code *)PTR_BIO_printf_006a6e38)
                                                  (bp_00,"%12sPublic Key Algorithm: ","");
                                if (0 < iVar2) {
                                  pcVar13 = (char *)pXVar16->key->algor->algorithm;
                                  iVar2 = i2a_ASN1_OBJECT(bp_00,(ASN1_OBJECT *)pcVar13);
                                  if (0 < iVar2) {
                                    pcVar13 = "\n";
                                    iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(bp_00);
                                    if (0 < iVar2) {
                                      pkey = X509_get_pubkey((X509 *)pcVar11);
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
                                                (bp_00,"X509v3 extensions",pXVar16->extensions,0,8);
                                      pcVar13 = *(char **)((int)pcVar11 + 4);
                                      iVar2 = X509_signature_print
                                                        (bp_00,(X509_ALGOR *)pcVar13,
                                                         *(ASN1_BIT_STRING **)((int)pcVar11 + 8));
                                      if (0 < iVar2) {
                                        pcVar14 = *(char **)((uchar *)((int)pcVar11 + 0x58) + 0xc);
                                        iVar2 = X509_CERT_AUX_print(bp_00,(X509_CERT_AUX *)pcVar14,0
                                                                   );
                                        uVar3 = (uint)(iVar2 != 0);
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
    uVar3 = 0;
  }
LAB_0055947c:
  (*(code *)PTR_BIO_free_006a6e70)(bp_00);
LAB_00559490:
  if (iStack_84 == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pcVar11 = X509_NAME_oneline((X509_NAME *)pcVar14,(char *)0x0,0);
  if (pcVar11 == (char *)0x0) {
    return 0;
  }
  pcVar14 = pcVar11 + 2;
  if (*pcVar11 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar11);
    return 1;
  }
  cVar9 = pcVar11[1];
  pcVar13 = pcVar11 + 1;
  if (cVar9 == '/') goto LAB_00559908;
LAB_0055985c:
  pcVar10 = pcVar13;
  pcVar15 = pcVar14;
  if (cVar9 != '\0') goto LAB_005598fc;
  while (pcVar13 = pcVar14,
        pcVar14 = (char *)(*(code *)PTR_BIO_write_006a6e14)
                                    (iVar2,pcVar10,pcVar13 + (-1 - (int)pcVar10)),
        pcVar13 + (-1 - (int)pcVar10) == pcVar14) {
    if (pcVar13[-1] == '\0') {
LAB_00559894:
      iVar2 = 1;
      goto LAB_00559898;
    }
    iVar8 = (*(code *)PTR_BIO_write_006a6e14)(iVar2,", ",2);
    if (iVar8 != 2) break;
    pcVar15 = pcVar13;
    if (pcVar13[-1] == '\0') goto LAB_00559894;
LAB_005598fc:
    do {
      pcVar14 = pcVar15 + 1;
      cVar9 = *pcVar15;
      if (cVar9 != '/') goto LAB_0055985c;
LAB_00559908:
      pcVar15 = pcVar14;
    } while ((0x19 < (byte)(*pcVar14 + 0xbfU)) ||
            ((pcVar10 = pcVar13, pcVar14[1] != 0x3d &&
             ((0x19 < ((int)pcVar14[1] - 0x41U & 0xff) || (pcVar14[2] != '='))))));
  }
  iVar2 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x75,7,"t_x509.c",0x219);
LAB_00559898:
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar11);
  return iVar2;
}

