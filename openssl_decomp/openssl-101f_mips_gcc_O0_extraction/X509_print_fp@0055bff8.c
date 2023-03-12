
int X509_print_fp(FILE *bp,X509 *x)

{
  undefined *puVar1;
  undefined4 uVar2;
  BIO *pBVar3;
  int iVar4;
  byte *pbVar5;
  long lVar6;
  ASN1_INTEGER *a;
  uchar *puVar7;
  undefined4 uVar8;
  int iVar9;
  EVP_PKEY *pEVar10;
  EVP_PKEY_ASN1_METHOD *pEVar11;
  char cVar13;
  int iVar12;
  X509_CINF *pXVar14;
  char *pcVar15;
  ASN1_UTCTIME *pAVar16;
  char *pcVar17;
  char *pcVar18;
  ASN1_STRING *sig;
  FILE *pFVar19;
  BIO *unaff_s0;
  char *pcVar20;
  FILE *pFVar21;
  char *pcVar22;
  uint uVar23;
  char *unaff_s4;
  X509_CINF *unaff_s5;
  char *unaff_s6;
  ASN1_INTEGER *unaff_s7;
  undefined4 unaff_s8;
  char *pcStack_94;
  int iStack_8c;
  undefined auStack_88 [4];
  int iStack_84;
  BIO *pBStack_80;
  FILE *pFStack_7c;
  X509 *pXStack_78;
  undefined *puStack_74;
  char *pcStack_70;
  X509_CINF *pXStack_6c;
  char *pcStack_68;
  ASN1_INTEGER *pAStack_64;
  undefined4 uStack_60;
  code *pcStack_5c;
  ASN1_STRING *local_48;
  FILE *local_44;
  undefined *local_40;
  int local_34;
  undefined auStack_30 [4];
  uchar *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(uchar **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar3 = (BIO *)(**(code **)(local_40 + -0x7f3c))(uVar2);
  if (pBVar3 == (BIO *)0x0) {
    sig = (ASN1_STRING *)&DAT_00000007;
    pcVar15 = "t_x509.c";
    local_48 = (ASN1_STRING *)&DAT_0000005a;
    pcVar22 = &DAT_00000076;
    (**(code **)(local_40 + -0x6eb0))(0xb);
    pFVar21 = (FILE *)0x0;
  }
  else {
    (**(code **)(local_40 + -0x7fc8))(pBVar3,0x6a,0);
    sig = (ASN1_STRING *)&DAT_0000000d;
    unaff_s5 = x->cert_info;
    pcVar15 = "Certificate:\n";
    iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
    if (iVar4 < 1) {
LAB_0055c380:
      pcVar22 = pcVar15;
      pFVar21 = (FILE *)0x0;
    }
    else {
      sig = (ASN1_STRING *)&DAT_0000000a;
      pcVar15 = "    Data:\n";
      iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
      if (iVar4 < 1) goto LAB_0055c380;
      unaff_s4 = "s\n";
      local_48 = (ASN1_STRING *)ASN1_INTEGER_get(x->cert_info->version);
      bp = (FILE *)((int)&local_48->length + 1);
      sig = (ASN1_STRING *)0x6395d0;
      pcVar15 = "%8sVersion: %lu (0x%lx)\n";
      iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
      if (iVar4 < 1) goto LAB_0055c380;
      sig = (ASN1_STRING *)&DAT_00000016;
      pcVar15 = "        Serial Number:";
      iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
      if (iVar4 < 1) goto LAB_0055c380;
      unaff_s7 = X509_get_serialNumber(x);
      if (4 < unaff_s7->length) {
        if (unaff_s7->type == 0x102) {
          bp = (FILE *)" (Negative)";
        }
        else {
          bp = (FILE *)0x6395d0;
        }
        sig = (ASN1_STRING *)0x6395d0;
        pcVar15 = "\n%12s%s";
        iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
        if (0 < iVar4) {
          pFVar21 = (FILE *)0x0;
          unaff_s8 = 0x3a;
          unaff_s6 = "%02x%c";
          do {
            pFVar19 = (FILE *)unaff_s7->length;
            bp = pFVar19;
            if ((int)pFVar19 <= (int)pFVar21) goto LAB_0055c1d8;
            pbVar5 = unaff_s7->data + (int)pFVar21;
            pFVar21 = (FILE *)((int)&pFVar21->_flags + 1);
            sig = (ASN1_STRING *)(uint)*pbVar5;
            bp = (FILE *)&DAT_0000000a;
            if (pFVar21 != pFVar19) {
              bp = (FILE *)&DAT_0000003a;
            }
            pcVar15 = unaff_s6;
            iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
          } while (0 < iVar4);
        }
        goto LAB_0055c380;
      }
      bp = (FILE *)ASN1_INTEGER_get(unaff_s7);
      if (unaff_s7->type == 0x102) {
        bp = (FILE *)-(int)bp;
        sig = (ASN1_STRING *)&DAT_00662b74;
      }
      else {
        sig = (ASN1_STRING *)0x6395d0;
      }
      pcVar15 = " %s%lu (%s0x%lx)\n";
      local_48 = sig;
      local_44 = bp;
      iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
      if (iVar4 < 1) goto LAB_0055c380;
LAB_0055c1d8:
      pcVar22 = (char *)x->sig_alg;
      pcVar15 = "    Signature Algorithm: ";
      iVar4 = (**(code **)(local_40 + -0x7e88))(pBVar3);
      if (iVar4 < 1) goto LAB_0055c380;
      pcVar15 = (char *)*(X509_CINF **)pcVar22;
      iVar4 = i2a_ASN1_OBJECT(pBVar3,(ASN1_OBJECT *)pcVar15);
      if (iVar4 < 1) goto LAB_0055c380;
      iVar4 = (**(code **)(local_40 + -0x7cb4))(*(X509_CINF **)pcVar22);
      if (iVar4 == 0) {
LAB_0055c224:
        pcVar15 = "\n";
        iVar4 = (**(code **)(local_40 + -0x7e88))(pBVar3);
        if (0 < iVar4) {
LAB_0055c240:
          sig = (ASN1_STRING *)&DAT_00000020;
          pcVar15 = "        Issuer:%c";
          iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
          if (0 < iVar4) {
            pcVar15 = (char *)X509_get_issuer_name(x);
            bp = (FILE *)0x0;
            sig = (ASN1_STRING *)&SUB_00000010;
            iVar4 = X509_NAME_print_ex(pBVar3,(X509_NAME *)pcVar15,0x10,0);
            if (-1 < iVar4) {
              sig = (ASN1_STRING *)0x1;
              pcVar15 = "\n";
              iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
              if (0 < iVar4) {
                sig = (ASN1_STRING *)&DAT_00000011;
                pcVar15 = "        Validity\n";
                iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                if (0 < iVar4) {
                  sig = (ASN1_STRING *)&DAT_00000018;
                  pcVar15 = "            Not Before: ";
                  iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                  if (0 < iVar4) {
                    pAVar16 = x->cert_info->validity->notBefore;
                    if (pAVar16->type != 0x17) {
                      if (pAVar16->type == 0x18) {
                        iVar4 = ASN1_GENERALIZEDTIME_print(pBVar3,pAVar16);
                        goto LAB_0055c474;
                      }
LAB_0055c314:
                      sig = (ASN1_STRING *)&DAT_0000000e;
                      pcVar22 = "Bad time value";
                      (**(code **)(local_40 + -0x7fcc))(pBVar3);
                      pFVar21 = (FILE *)0x0;
                      goto LAB_0055c384;
                    }
                    iVar4 = ASN1_UTCTIME_print(pBVar3,pAVar16);
LAB_0055c474:
                    pcVar15 = (char *)(X509 *)0x670000;
                    if (iVar4 != 0) {
                      sig = (ASN1_STRING *)&DAT_00000019;
                      pcVar15 = "\n            Not After : ";
                      iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                      if (0 < iVar4) {
                        pcVar15 = (char *)x->cert_info->validity->notAfter;
                        if (*(X509_ALGOR **)((int)pcVar15 + 4) == (X509_ALGOR *)&DAT_00000017) {
                          iVar4 = ASN1_UTCTIME_print(pBVar3,(ASN1_UTCTIME *)pcVar15);
                        }
                        else {
                          if (*(X509_ALGOR **)((int)pcVar15 + 4) != (X509_ALGOR *)&DAT_00000018)
                          goto LAB_0055c314;
                          iVar4 = ASN1_GENERALIZEDTIME_print(pBVar3,(ASN1_GENERALIZEDTIME *)pcVar15)
                          ;
                        }
                        if (iVar4 != 0) {
                          pcVar15 = "\n";
                          sig = (ASN1_STRING *)0x1;
                          iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                          if (0 < iVar4) {
                            sig = (ASN1_STRING *)&DAT_00000020;
                            pcVar15 = "        Subject:%c";
                            iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
                            if (0 < iVar4) {
                              pcVar15 = (char *)X509_get_subject_name(x);
                              bp = (FILE *)0x0;
                              sig = (ASN1_STRING *)&SUB_00000010;
                              iVar4 = X509_NAME_print_ex(pBVar3,(X509_NAME *)pcVar15,0x10,0);
                              if (-1 < iVar4) {
                                sig = (ASN1_STRING *)0x1;
                                pcVar15 = "\n";
                                iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                                if (0 < iVar4) {
                                  sig = (ASN1_STRING *)0x21;
                                  pcVar15 = "        Subject Public Key Info:\n";
                                  iVar4 = (**(code **)(local_40 + -0x7fcc))(pBVar3);
                                  if (0 < iVar4) {
                                    sig = (ASN1_STRING *)0x6395d0;
                                    pcVar15 = "%12sPublic Key Algorithm: ";
                                    iVar4 = (**(code **)(local_40 + -0x7fa8))(pBVar3);
                                    if (0 < iVar4) {
                                      pcVar15 = (char *)unaff_s5->key->algor->algorithm;
                                      iVar4 = i2a_ASN1_OBJECT(pBVar3,(ASN1_OBJECT *)pcVar15);
                                      if (0 < iVar4) {
                                        pcVar15 = "\n";
                                        iVar4 = (**(code **)(local_40 + -0x7e88))(pBVar3);
                                        if (0 < iVar4) {
                                          pEVar10 = X509_get_pubkey(x);
                                          if (pEVar10 == (EVP_PKEY *)0x0) {
                                            (**(code **)(local_40 + -0x7fa8))
                                                      (pBVar3,"%12sUnable to load Public Key\n","");
                                            (**(code **)(local_40 + -0x7fa0))(pBVar3);
                                          }
                                          else {
                                            EVP_PKEY_print_public
                                                      (pBVar3,pEVar10,0x10,(ASN1_PCTX *)0x0);
                                            EVP_PKEY_free(pEVar10);
                                          }
                                          bp = (FILE *)0x0;
                                          local_48 = (ASN1_STRING *)&DAT_00000008;
                                          (**(code **)(local_40 + -0x6060))
                                                    (pBVar3,"X509v3 extensions",unaff_s5->extensions
                                                    );
                                          sig = x->signature;
                                          pcVar15 = (char *)x->sig_alg;
                                          iVar4 = X509_signature_print
                                                            (pBVar3,(X509_ALGOR *)pcVar15,sig);
                                          if (0 < iVar4) {
                                            sig = (ASN1_STRING *)0x0;
                                            pcVar22 = *(char **)(x->sha1_hash + 0xc);
                                            iVar4 = X509_CERT_AUX_print(pBVar3,(X509_CERT_AUX *)
                                                                               pcVar22,0);
                                            pFVar21 = (FILE *)(uint)(iVar4 != 0);
                                            goto LAB_0055c384;
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
        }
        goto LAB_0055c380;
      }
      sig = (ASN1_STRING *)&local_34;
      iVar4 = (**(code **)(local_40 + -0x6a78))(iVar4,auStack_30);
      if ((iVar4 == 0) ||
         (pEVar11 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34),
         pEVar11 == (EVP_PKEY_ASN1_METHOD *)0x0)) goto LAB_0055c224;
      bp = (FILE *)&DAT_00000009;
      if (*(code **)(pEVar11 + 0x50) == (code *)0x0) goto LAB_0055c224;
      local_48 = (ASN1_STRING *)0x0;
      sig = (ASN1_STRING *)0x0;
      iVar4 = (**(code **)(pEVar11 + 0x50))(pBVar3);
      if (0 < iVar4) goto LAB_0055c240;
      pFVar21 = (FILE *)0x0;
    }
LAB_0055c384:
    (**(code **)(local_40 + -0x7f70))(pBVar3);
    pcVar15 = (char *)bp;
    unaff_s0 = pBVar3;
    bp = pFVar21;
  }
  if (local_2c == *(uchar **)puStack_74) {
    return (int)pFVar21;
  }
  pcStack_5c = X509_print_ex_fp;
  puVar7 = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_80 = unaff_s0;
  pFStack_7c = bp;
  pXStack_78 = x;
  pcStack_70 = unaff_s4;
  pXStack_6c = unaff_s5;
  pcStack_68 = unaff_s6;
  pAStack_64 = unaff_s7;
  uStack_60 = unaff_s8;
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar3 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (pBVar3 == (BIO *)0x0) {
    pcVar17 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar23 = 0;
    goto LAB_0055c87c;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0x6a,0,puVar7);
  if (((uint)sig & 0xf0000) == 0x40000) {
    iVar4 = 0xc;
    uVar2 = 10;
  }
  else {
    iVar4 = 0x10;
    uVar2 = 0x20;
    if (sig != (ASN1_STRING *)0x0) {
      iVar4 = 0;
    }
  }
  pXVar14 = *(X509_CINF **)pcVar22;
  if (((uint)pcVar15 & 1) == 0) {
    pcVar18 = "Certificate:\n";
    iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"Certificate:\n",0xd);
    if (0 < iVar12) {
      pcVar18 = "    Data:\n";
      iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"    Data:\n",10);
      if (0 < iVar12) goto LAB_0055c7a8;
    }
LAB_0055c864:
    pcVar17 = pcVar18;
    uVar23 = 0;
  }
  else {
LAB_0055c7a8:
    if (((uint)pcVar15 & 2) == 0) {
      lVar6 = ASN1_INTEGER_get((*(X509_CINF **)pcVar22)->version);
      pcVar18 = "%8sVersion: %lu (0x%lx)\n";
      iVar12 = (*(code *)PTR_BIO_printf_006a7f38)
                         (pBVar3,"%8sVersion: %lu (0x%lx)\n","",lVar6 + 1,lVar6);
      if (iVar12 < 1) goto LAB_0055c864;
    }
    if (((uint)pcVar15 & 4) == 0) {
      pcVar18 = "        Serial Number:";
      iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"        Serial Number:",0x16);
      if (0 < iVar12) {
        a = X509_get_serialNumber((X509 *)pcVar22);
        if (a->length < 5) {
          iVar12 = ASN1_INTEGER_get(a);
          if (a->type == 0x102) {
            iVar12 = -iVar12;
            pcVar18 = "-";
          }
          else {
            pcVar18 = "";
          }
          pcVar17 = " %s%lu (%s0x%lx)\n";
          iVar12 = (*(code *)PTR_BIO_printf_006a7f38)
                             (pBVar3," %s%lu (%s0x%lx)\n",pcVar18,iVar12,pcVar18,iVar12);
          if (0 < iVar12) goto LAB_0055c7c0;
          uVar23 = 0;
        }
        else {
          if (a->type == 0x102) {
            pcVar17 = " (Negative)";
          }
          else {
            pcVar17 = "";
          }
          pcVar18 = "\n%12s%s";
          iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar3,"\n%12s%s","",pcVar17);
          if (iVar12 < 1) goto LAB_0055c864;
          iVar12 = 0;
          pcStack_94 = "%02x%c";
          do {
            if (a->length <= iVar12) goto LAB_0055c7c0;
            puVar7 = a->data + iVar12;
            iVar12 = iVar12 + 1;
            uVar8 = 10;
            if (iVar12 != a->length) {
              uVar8 = 0x3a;
            }
            pcVar17 = pcStack_94;
            iVar9 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar3,"%02x%c",*puVar7,uVar8);
          } while (0 < iVar9);
          uVar23 = 0;
        }
        goto LAB_0055c868;
      }
      goto LAB_0055c864;
    }
LAB_0055c7c0:
    if (((uint)pcVar15 & 8) != 0) goto LAB_0055c7c8;
    pcVar17 = *(char **)((int)pcVar22 + 4);
    pcVar18 = "    Signature Algorithm: ";
    iVar12 = (*(code *)PTR_BIO_puts_006a8058)(pBVar3);
    if (iVar12 < 1) goto LAB_0055c864;
    pcVar18 = (char *)*(stack_st_X509_NAME_ENTRY **)pcVar17;
    iVar12 = i2a_ASN1_OBJECT(pBVar3,(ASN1_OBJECT *)pcVar18);
    if (iVar12 < 1) goto LAB_0055c864;
    iVar12 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(stack_st_X509_NAME_ENTRY **)pcVar17);
    if ((((iVar12 == 0) ||
         (iVar12 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(iVar12,auStack_88,&iStack_8c),
         iVar12 == 0)) ||
        (pEVar11 = EVP_PKEY_asn1_find((ENGINE **)0x0,iStack_8c),
        pEVar11 == (EVP_PKEY_ASN1_METHOD *)0x0)) || (*(code **)(pEVar11 + 0x50) == (code *)0x0)) {
      pcVar17 = "\n";
      iVar12 = (*(code *)PTR_BIO_puts_006a8058)(pBVar3);
      if (0 < iVar12) goto LAB_0055c7c8;
      uVar23 = 0;
    }
    else {
      iVar12 = (**(code **)(pEVar11 + 0x50))(pBVar3,pcVar17,0,9,0);
      if (0 < iVar12) {
LAB_0055c7c8:
        if (((uint)pcVar15 & 0x10) == 0) {
          pcVar18 = "        Issuer:%c";
          iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar3,"        Issuer:%c",uVar2);
          if (0 < iVar12) {
            pcVar18 = (char *)X509_get_issuer_name((X509 *)pcVar22);
            iVar12 = X509_NAME_print_ex(pBVar3,(X509_NAME *)pcVar18,iVar4,(ulong)sig);
            if (-1 < iVar12) {
              pcVar17 = "\n";
              iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"\n",1);
              if (iVar12 < 1) {
                uVar23 = 0;
                goto LAB_0055c868;
              }
              goto LAB_0055c7d4;
            }
          }
          goto LAB_0055c864;
        }
LAB_0055c7d4:
        if (((uint)pcVar15 & 0x20) == 0) {
          pcVar18 = "        Validity\n";
          iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"        Validity\n",0x11);
          if (0 < iVar12) {
            pcVar18 = "            Not Before: ";
            iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"            Not Before: ",0x18);
            if (0 < iVar12) {
              pAVar16 = (*(X509_CINF **)pcVar22)->validity->notBefore;
              if (pAVar16->type != 0x17) {
                if (pAVar16->type == 0x18) {
                  iVar12 = ASN1_GENERALIZEDTIME_print(pBVar3,pAVar16);
                  goto LAB_0055cd88;
                }
LAB_0055cbec:
                pcVar17 = "Bad time value";
                (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"Bad time value",0xe);
                uVar23 = 0;
                goto LAB_0055c868;
              }
              iVar12 = ASN1_UTCTIME_print(pBVar3,pAVar16);
LAB_0055cd88:
              pcVar18 = (char *)(EVP_PKEY *)0x670000;
              if (iVar12 != 0) {
                pcVar18 = "\n            Not After : ";
                iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"\n            Not After : ",0x19)
                ;
                if (0 < iVar12) {
                  pAVar16 = (*(X509_CINF **)pcVar22)->validity->notAfter;
                  if (pAVar16->type == 0x17) {
                    iVar12 = ASN1_UTCTIME_print(pBVar3,pAVar16);
                  }
                  else {
                    if (pAVar16->type != 0x18) goto LAB_0055cbec;
                    iVar12 = ASN1_GENERALIZEDTIME_print(pBVar3,pAVar16);
                  }
                  pcVar18 = (char *)(EVP_PKEY *)0x640000;
                  if (iVar12 != 0) {
                    pcVar17 = "\n";
                    iVar12 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"\n",1);
                    if (0 < iVar12) goto LAB_0055c7e0;
                    uVar23 = 0;
                    goto LAB_0055c868;
                  }
                }
              }
            }
          }
        }
        else {
LAB_0055c7e0:
          if (((uint)pcVar15 & 0x40) == 0) {
            pcVar18 = "        Subject:%c";
            iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar3,"        Subject:%c",uVar2);
            if (0 < iVar12) {
              pcVar18 = (char *)X509_get_subject_name((X509 *)pcVar22);
              iVar4 = X509_NAME_print_ex(pBVar3,(X509_NAME *)pcVar18,iVar4,(ulong)sig);
              if (-1 < iVar4) {
                pcVar17 = "\n";
                iVar4 = (*(code *)PTR_BIO_write_006a7f14)(pBVar3,"\n",1);
                if (iVar4 < 1) {
                  uVar23 = 0;
                  goto LAB_0055c868;
                }
                goto LAB_0055c7ec;
              }
            }
          }
          else {
LAB_0055c7ec:
            pcVar17 = "r";
            if (((uint)pcVar15 & 0x80) != 0) {
LAB_0055c7f8:
              if (((uint)pcVar15 & 0x100) == 0) {
                pcVar17 = "X509v3 extensions";
                (*(code *)PTR_X509V3_extensions_print_006a9e80)
                          (pBVar3,"X509v3 extensions",pXVar14->extensions,pcVar15,8);
              }
              if (((uint)pcVar15 & 0x200) == 0) {
                pcVar17 = *(char **)((int)pcVar22 + 4);
                iVar4 = X509_signature_print
                                  (pBVar3,(X509_ALGOR *)pcVar17,
                                   *(ASN1_BIT_STRING **)((int)pcVar22 + 8));
                if (iVar4 < 1) {
                  uVar23 = 0;
                  goto LAB_0055c868;
                }
              }
              if (((uint)pcVar15 & 0x400) == 0) {
                pcVar17 = *(char **)((uchar *)((int)pcVar22 + 0x58) + 0xc);
                iVar4 = X509_CERT_AUX_print(pBVar3,(X509_CERT_AUX *)pcVar17,0);
                uVar23 = (uint)(iVar4 != 0);
              }
              else {
                uVar23 = 1;
              }
              goto LAB_0055c868;
            }
            pcVar18 = "        Subject Public Key Info:\n";
            iVar4 = (*(code *)PTR_BIO_write_006a7f14)
                              (pBVar3,"        Subject Public Key Info:\n",0x21);
            if (0 < iVar4) {
              pcVar18 = "%12sPublic Key Algorithm: ";
              iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar3,"%12sPublic Key Algorithm: ","");
              if (0 < iVar4) {
                pcVar18 = (char *)pXVar14->key->algor->algorithm;
                iVar4 = i2a_ASN1_OBJECT(pBVar3,(ASN1_OBJECT *)pcVar18);
                if (0 < iVar4) {
                  pcVar18 = "\n";
                  iVar4 = (*(code *)PTR_BIO_puts_006a8058)(pBVar3);
                  if (0 < iVar4) {
                    pEVar10 = X509_get_pubkey((X509 *)pcVar22);
                    if (pEVar10 == (EVP_PKEY *)0x0) {
                      pcVar17 = "%12sUnable to load Public Key\n";
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (pBVar3,"%12sUnable to load Public Key\n","");
                      (*(code *)PTR_ERR_print_errors_006a7f40)(pBVar3);
                    }
                    else {
                      pcVar17 = (char *)pEVar10;
                      EVP_PKEY_print_public(pBVar3,pEVar10,0x10,(ASN1_PCTX *)0x0);
                      EVP_PKEY_free(pEVar10);
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
      uVar23 = 0;
    }
  }
LAB_0055c868:
  (*(code *)PTR_BIO_free_006a7f70)(pBVar3);
LAB_0055c87c:
  if (iStack_84 == *(int *)puVar1) {
    return uVar23;
  }
  iVar4 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcVar15 = X509_NAME_oneline((X509_NAME *)pcVar17,(char *)0x0,0);
  if (*pcVar15 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar15);
    return 1;
  }
  pcVar22 = pcVar15 + 2;
  cVar13 = pcVar15[1];
  pcVar17 = pcVar15 + 1;
  if (cVar13 == '/') goto LAB_0055cffc;
LAB_0055cf50:
  pcVar18 = pcVar17;
  pcVar20 = pcVar22;
  if (cVar13 != '\0') goto LAB_0055cff0;
  while (pcVar17 = pcVar22,
        pcVar22 = (char *)(*(code *)PTR_BIO_write_006a7f14)
                                    (iVar4,pcVar18,pcVar17 + (-1 - (int)pcVar18)),
        pcVar17 + (-1 - (int)pcVar18) == pcVar22) {
    if (pcVar17[-1] == '\0') {
LAB_0055cf88:
      iVar4 = 1;
      goto LAB_0055cf8c;
    }
    iVar12 = (*(code *)PTR_BIO_write_006a7f14)(iVar4,", ",2);
    if (iVar12 != 2) break;
    pcVar20 = pcVar17;
    if (pcVar17[-1] == '\0') goto LAB_0055cf88;
LAB_0055cff0:
    do {
      pcVar22 = pcVar20 + 1;
      cVar13 = *pcVar20;
      if (cVar13 != '/') goto LAB_0055cf50;
LAB_0055cffc:
      pcVar20 = pcVar22;
    } while ((0x19 < (byte)(*pcVar22 + 0xbfU)) ||
            ((pcVar18 = pcVar17, pcVar22[1] != 0x3d &&
             ((0x19 < ((int)pcVar22[1] - 0x41U & 0xff) || (pcVar22[2] != '='))))));
  }
  iVar4 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x75,7,"t_x509.c",0x20c);
LAB_0055cf8c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar15);
  return iVar4;
}

