
int X509_print(BIO *bp,X509 *x)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  BIO *pBVar5;
  byte *pbVar6;
  long lVar7;
  ASN1_INTEGER *a;
  uchar *puVar8;
  undefined4 uVar9;
  int iVar10;
  EVP_PKEY *pEVar11;
  EVP_PKEY_ASN1_METHOD *pEVar12;
  char cVar14;
  int iVar13;
  X509_CINF *pXVar15;
  ASN1_UTCTIME *pAVar16;
  char *pcVar17;
  ASN1_STRING *sig;
  char *pcVar18;
  char *pcVar19;
  X509 *unaff_s1;
  char *pcVar20;
  char *pcVar21;
  char *unaff_s4;
  char *unaff_s6;
  ASN1_INTEGER *unaff_s7;
  undefined4 unaff_s8;
  char *pcStack_ec;
  int iStack_e4;
  undefined auStack_e0 [4];
  int iStack_dc;
  BIO *pBStack_d8;
  char *pcStack_d4;
  char *pcStack_d0;
  undefined *puStack_cc;
  char *pcStack_c8;
  X509_CINF *pXStack_c4;
  char *pcStack_c0;
  ASN1_INTEGER *pAStack_bc;
  undefined4 uStack_b8;
  code *pcStack_b4;
  ASN1_STRING *pAStack_a0;
  char *pcStack_9c;
  undefined *puStack_98;
  undefined auStack_8c [8];
  uchar *puStack_84;
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
  char *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  pcStack_d0 = "Certificate:\n";
  local_40 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  pXStack_c4 = x->cert_info;
  iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"Certificate:\n",0xd);
  if (iVar2 < 1) {
LAB_0055bcd8:
    uVar3 = 0;
  }
  else {
    pcStack_d0 = "    Data:\n";
    iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"    Data:\n",10);
    if (iVar2 < 1) goto LAB_0055bcd8;
    unaff_s4 = "s\n";
    local_48 = (char *)ASN1_INTEGER_get(x->cert_info->version);
    pcStack_d0 = "%8sVersion: %lu (0x%lx)\n";
    iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"%8sVersion: %lu (0x%lx)\n","",local_48 + 1);
    if (iVar2 < 1) goto LAB_0055bcd8;
    pcStack_d0 = "        Serial Number:";
    iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"        Serial Number:",0x16);
    if (iVar2 < 1) goto LAB_0055bcd8;
    unaff_s7 = X509_get_serialNumber(x);
    if (4 < unaff_s7->length) {
      if (unaff_s7->type == 0x102) {
        pcVar18 = " (Negative)";
      }
      else {
        pcVar18 = "";
      }
      pcStack_d0 = "\n%12s%s";
      iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"\n%12s%s","",pcVar18);
      if (0 < iVar2) {
        unaff_s1 = (X509 *)0x0;
        unaff_s8 = 0x3a;
        unaff_s6 = "%02x%c";
        do {
          if ((int)(X509 *)unaff_s7->length <= (int)unaff_s1) goto LAB_0055bb30;
          puVar8 = unaff_s7->data + (int)unaff_s1;
          unaff_s1 = (X509 *)((int)&unaff_s1->cert_info + 1);
          uVar4 = 10;
          if (unaff_s1 != (X509 *)unaff_s7->length) {
            uVar4 = 0x3a;
          }
          pcStack_d0 = unaff_s6;
          iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"%02x%c",*puVar8,uVar4);
        } while (0 < iVar2);
      }
      goto LAB_0055bcd8;
    }
    local_44 = ASN1_INTEGER_get(unaff_s7);
    if (unaff_s7->type == 0x102) {
      local_44 = -local_44;
      local_48 = "-";
    }
    else {
      local_48 = "";
    }
    pcStack_d0 = " %s%lu (%s0x%lx)\n";
    iVar2 = (**(code **)(local_40 + -0x7fa8))(bp," %s%lu (%s0x%lx)\n",local_48,local_44);
    if (iVar2 < 1) goto LAB_0055bcd8;
LAB_0055bb30:
    unaff_s1 = (X509 *)x->sig_alg;
    pcStack_d0 = "    Signature Algorithm: ";
    iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
    if (iVar2 < 1) goto LAB_0055bcd8;
    pcStack_d0 = (char *)unaff_s1->cert_info;
    iVar2 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcStack_d0);
    if (iVar2 < 1) goto LAB_0055bcd8;
    iVar2 = (**(code **)(local_40 + -0x7cb4))(unaff_s1->cert_info);
    if ((((iVar2 == 0) ||
         (iVar2 = (**(code **)(local_40 + -0x6a78))(iVar2,auStack_30,&local_34), iVar2 == 0)) ||
        (pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34),
        pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0)) || (*(code **)(pEVar12 + 0x50) == (code *)0x0)) {
      pcStack_d0 = "\n";
      iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
      if (0 < iVar2) goto LAB_0055bb98;
      goto LAB_0055bcd8;
    }
    local_48 = (char *)0x0;
    pcStack_d0 = (char *)unaff_s1;
    iVar2 = (**(code **)(pEVar12 + 0x50))(bp,unaff_s1,0,9);
    if (0 < iVar2) {
LAB_0055bb98:
      pcStack_d0 = "        Issuer:%c";
      iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"        Issuer:%c",0x20);
      if (0 < iVar2) {
        pcStack_d0 = (char *)X509_get_issuer_name(x);
        iVar2 = X509_NAME_print_ex(bp,(X509_NAME *)pcStack_d0,0x10,0);
        if (-1 < iVar2) {
          unaff_s1 = (X509 *)0x640000;
          pcStack_d0 = "\n";
          iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
          if (0 < iVar2) {
            pcStack_d0 = "        Validity\n";
            iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"        Validity\n",0x11);
            if (0 < iVar2) {
              pcStack_d0 = "            Not Before: ";
              iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"            Not Before: ",0x18);
              if (0 < iVar2) {
                pAVar16 = x->cert_info->validity->notBefore;
                if (pAVar16->type != 0x17) {
                  if (pAVar16->type == 0x18) {
                    iVar2 = ASN1_GENERALIZEDTIME_print(bp,pAVar16);
                    goto LAB_0055bd24;
                  }
LAB_0055bc6c:
                  pcStack_d0 = "Bad time value";
                  (**(code **)(local_40 + -0x7fcc))(bp,"Bad time value",0xe);
                  uVar3 = 0;
                  goto LAB_0055bcdc;
                }
                iVar2 = ASN1_UTCTIME_print(bp,pAVar16);
LAB_0055bd24:
                pcStack_d0 = "7 datafinal";
                if (iVar2 != 0) {
                  pcStack_d0 = "\n            Not After : ";
                  iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n            Not After : ",0x19);
                  if (0 < iVar2) {
                    pcStack_d0 = (char *)x->cert_info->validity->notAfter;
                    if (*(X509_ALGOR **)((int)pcStack_d0 + 4) == (X509_ALGOR *)&DAT_00000017) {
                      iVar2 = ASN1_UTCTIME_print(bp,(ASN1_UTCTIME *)pcStack_d0);
                    }
                    else {
                      if (*(X509_ALGOR **)((int)pcStack_d0 + 4) != (X509_ALGOR *)&DAT_00000018)
                      goto LAB_0055bc6c;
                      iVar2 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)pcStack_d0);
                    }
                    if (iVar2 != 0) {
                      pcStack_d0 = "\n";
                      iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
                      unaff_s1 = (X509 *)0x640000;
                      if (0 < iVar2) {
                        pcStack_d0 = "        Subject:%c";
                        iVar2 = (**(code **)(local_40 + -0x7fa8))(bp,"        Subject:%c",0x20);
                        if (0 < iVar2) {
                          pcStack_d0 = (char *)X509_get_subject_name(x);
                          iVar2 = X509_NAME_print_ex(bp,(X509_NAME *)pcStack_d0,0x10,0);
                          if (-1 < iVar2) {
                            pcStack_d0 = "\n";
                            iVar2 = (**(code **)(local_40 + -0x7fcc))(bp,"\n",1);
                            if (0 < iVar2) {
                              pcStack_d0 = "        Subject Public Key Info:\n";
                              iVar2 = (**(code **)(local_40 + -0x7fcc))
                                                (bp,"        Subject Public Key Info:\n",0x21);
                              if (0 < iVar2) {
                                pcStack_d0 = "%12sPublic Key Algorithm: ";
                                iVar2 = (**(code **)(local_40 + -0x7fa8))
                                                  (bp,"%12sPublic Key Algorithm: ","");
                                if (0 < iVar2) {
                                  pcStack_d0 = (char *)pXStack_c4->key->algor->algorithm;
                                  iVar2 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcStack_d0);
                                  if (0 < iVar2) {
                                    pcStack_d0 = "\n";
                                    iVar2 = (**(code **)(local_40 + -0x7e88))(bp);
                                    if (0 < iVar2) {
                                      unaff_s1 = (X509 *)X509_get_pubkey(x);
                                      if (unaff_s1 == (X509 *)0x0) {
                                        (**(code **)(local_40 + -0x7fa8))
                                                  (bp,"%12sUnable to load Public Key\n","");
                                        (**(code **)(local_40 + -0x7fa0))(bp);
                                      }
                                      else {
                                        EVP_PKEY_print_public
                                                  (bp,(EVP_PKEY *)unaff_s1,0x10,(ASN1_PCTX *)0x0);
                                        EVP_PKEY_free((EVP_PKEY *)unaff_s1);
                                      }
                                      local_48 = (char *)0x8;
                                      (**(code **)(local_40 + -0x6060))
                                                (bp,"X509v3 extensions",pXStack_c4->extensions,0);
                                      pcStack_d0 = (char *)x->sig_alg;
                                      iVar2 = X509_signature_print
                                                        (bp,(X509_ALGOR *)pcStack_d0,x->signature);
                                      if (0 < iVar2) {
                                        pcStack_d0 = *(char **)(x->sha1_hash + 0xc);
                                        iVar2 = X509_CERT_AUX_print(bp,(X509_CERT_AUX *)pcStack_d0,0
                                                                   );
                                        uVar3 = (uint)(iVar2 != 0);
                                        goto LAB_0055bcdc;
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
      goto LAB_0055bcd8;
    }
    uVar3 = 0;
  }
LAB_0055bcdc:
  if (local_2c == *(char **)puStack_74) {
    return uVar3;
  }
  pcStack_5c = X509_print_fp;
  pcStack_d4 = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  puStack_98 = &_gp;
  puStack_84 = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pBStack_80 = bp;
  pXStack_7c = unaff_s1;
  pXStack_78 = x;
  pcStack_70 = unaff_s4;
  pXStack_6c = pXStack_c4;
  pcStack_68 = unaff_s6;
  pAStack_64 = unaff_s7;
  uStack_60 = unaff_s8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar5 = (BIO *)(**(code **)(puStack_98 + -0x7f3c))(uVar4);
  if (pBVar5 == (BIO *)0x0) {
    sig = (ASN1_STRING *)&DAT_00000007;
    pcVar18 = "t_x509.c";
    pAStack_a0 = (ASN1_STRING *)&DAT_0000005a;
    pcVar21 = &DAT_00000076;
    (**(code **)(puStack_98 + -0x6eb0))(0xb);
    pcVar20 = (char *)0x0;
  }
  else {
    (**(code **)(puStack_98 + -0x7fc8))(pBVar5,0x6a,0);
    sig = (ASN1_STRING *)&DAT_0000000d;
    pXStack_c4 = *(X509_CINF **)pcStack_d0;
    pcVar18 = "Certificate:\n";
    iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
    if (iVar2 < 1) {
LAB_0055c380:
      pcVar21 = pcVar18;
      pcVar20 = (char *)0x0;
    }
    else {
      sig = (ASN1_STRING *)&DAT_0000000a;
      pcVar18 = "    Data:\n";
      iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
      if (iVar2 < 1) goto LAB_0055c380;
      unaff_s4 = "s\n";
      pAStack_a0 = (ASN1_STRING *)ASN1_INTEGER_get((*(X509_CINF **)pcStack_d0)->version);
      pcStack_d4 = (char *)((int)&pAStack_a0->length + 1);
      sig = (ASN1_STRING *)0x6395d0;
      pcVar18 = "%8sVersion: %lu (0x%lx)\n";
      iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
      if (iVar2 < 1) goto LAB_0055c380;
      sig = (ASN1_STRING *)&DAT_00000016;
      pcVar18 = "        Serial Number:";
      iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
      if (iVar2 < 1) goto LAB_0055c380;
      unaff_s7 = X509_get_serialNumber((X509 *)pcStack_d0);
      if (4 < unaff_s7->length) {
        if (unaff_s7->type == 0x102) {
          pcStack_d4 = " (Negative)";
        }
        else {
          pcStack_d4 = "";
        }
        sig = (ASN1_STRING *)0x6395d0;
        pcVar18 = "\n%12s%s";
        iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
        if (0 < iVar2) {
          pcVar20 = (char *)0x0;
          unaff_s8 = 0x3a;
          unaff_s6 = "%02x%c";
          do {
            pcVar18 = (char *)unaff_s7->length;
            pcStack_d4 = pcVar18;
            if ((int)pcVar18 <= (int)pcVar20) goto LAB_0055c1d8;
            pbVar6 = unaff_s7->data + (int)pcVar20;
            pcVar20 = pcVar20 + 1;
            sig = (ASN1_STRING *)(uint)*pbVar6;
            pcStack_d4 = &DAT_0000000a;
            if (pcVar20 != pcVar18) {
              pcStack_d4 = &DAT_0000003a;
            }
            pcVar18 = unaff_s6;
            iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
          } while (0 < iVar2);
        }
        goto LAB_0055c380;
      }
      pcStack_d4 = (char *)ASN1_INTEGER_get(unaff_s7);
      if (unaff_s7->type == 0x102) {
        pcStack_d4 = (char *)-(int)pcStack_d4;
        sig = (ASN1_STRING *)&DAT_00662b94;
      }
      else {
        sig = (ASN1_STRING *)0x6395d0;
      }
      pcVar18 = " %s%lu (%s0x%lx)\n";
      pAStack_a0 = sig;
      pcStack_9c = pcStack_d4;
      iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
      if (iVar2 < 1) goto LAB_0055c380;
LAB_0055c1d8:
      pcVar21 = *(char **)((int)pcStack_d0 + 4);
      pcVar18 = "    Signature Algorithm: ";
      iVar2 = (**(code **)(puStack_98 + -0x7e88))(pBVar5);
      if (iVar2 < 1) goto LAB_0055c380;
      pcVar18 = (char *)*(X509_CINF **)pcVar21;
      iVar2 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar18);
      if (iVar2 < 1) goto LAB_0055c380;
      iVar2 = (**(code **)(puStack_98 + -0x7cb4))(*(X509_CINF **)pcVar21);
      if (iVar2 == 0) {
LAB_0055c224:
        pcVar18 = "\n";
        iVar2 = (**(code **)(puStack_98 + -0x7e88))(pBVar5);
        if (0 < iVar2) {
LAB_0055c240:
          sig = (ASN1_STRING *)&DAT_00000020;
          pcVar18 = "        Issuer:%c";
          iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
          if (0 < iVar2) {
            pcVar18 = (char *)X509_get_issuer_name((X509 *)pcStack_d0);
            pcStack_d4 = (char *)0x0;
            sig = (ASN1_STRING *)&SUB_00000010;
            iVar2 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar18,0x10,0);
            if (-1 < iVar2) {
              sig = (ASN1_STRING *)0x1;
              pcVar18 = "\n";
              iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
              if (0 < iVar2) {
                sig = (ASN1_STRING *)&DAT_00000011;
                pcVar18 = "        Validity\n";
                iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                if (0 < iVar2) {
                  sig = (ASN1_STRING *)&DAT_00000018;
                  pcVar18 = "            Not Before: ";
                  iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                  if (0 < iVar2) {
                    pAVar16 = (*(X509_CINF **)pcStack_d0)->validity->notBefore;
                    if (pAVar16->type != 0x17) {
                      if (pAVar16->type == 0x18) {
                        iVar2 = ASN1_GENERALIZEDTIME_print(pBVar5,pAVar16);
                        goto LAB_0055c474;
                      }
LAB_0055c314:
                      sig = (ASN1_STRING *)&DAT_0000000e;
                      pcVar21 = "Bad time value";
                      (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                      pcVar20 = (char *)0x0;
                      goto LAB_0055c384;
                    }
                    iVar2 = ASN1_UTCTIME_print(pBVar5,pAVar16);
LAB_0055c474:
                    pcVar18 = (char *)(X509 *)0x670000;
                    if (iVar2 != 0) {
                      sig = (ASN1_STRING *)&DAT_00000019;
                      pcVar18 = "\n            Not After : ";
                      iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                      if (0 < iVar2) {
                        pcVar18 = (char *)(*(X509_CINF **)pcStack_d0)->validity->notAfter;
                        if (*(X509_ALGOR **)((int)pcVar18 + 4) == (X509_ALGOR *)&DAT_00000017) {
                          iVar2 = ASN1_UTCTIME_print(pBVar5,(ASN1_UTCTIME *)pcVar18);
                        }
                        else {
                          if (*(X509_ALGOR **)((int)pcVar18 + 4) != (X509_ALGOR *)&DAT_00000018)
                          goto LAB_0055c314;
                          iVar2 = ASN1_GENERALIZEDTIME_print(pBVar5,(ASN1_GENERALIZEDTIME *)pcVar18)
                          ;
                        }
                        if (iVar2 != 0) {
                          pcVar18 = "\n";
                          sig = (ASN1_STRING *)0x1;
                          iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                          if (0 < iVar2) {
                            sig = (ASN1_STRING *)&DAT_00000020;
                            pcVar18 = "        Subject:%c";
                            iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
                            if (0 < iVar2) {
                              pcVar18 = (char *)X509_get_subject_name((X509 *)pcStack_d0);
                              pcStack_d4 = (char *)0x0;
                              sig = (ASN1_STRING *)&SUB_00000010;
                              iVar2 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar18,0x10,0);
                              if (-1 < iVar2) {
                                sig = (ASN1_STRING *)0x1;
                                pcVar18 = "\n";
                                iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                                if (0 < iVar2) {
                                  sig = (ASN1_STRING *)0x21;
                                  pcVar18 = "        Subject Public Key Info:\n";
                                  iVar2 = (**(code **)(puStack_98 + -0x7fcc))(pBVar5);
                                  if (0 < iVar2) {
                                    sig = (ASN1_STRING *)0x6395d0;
                                    pcVar18 = "%12sPublic Key Algorithm: ";
                                    iVar2 = (**(code **)(puStack_98 + -0x7fa8))(pBVar5);
                                    if (0 < iVar2) {
                                      pcVar18 = (char *)pXStack_c4->key->algor->algorithm;
                                      iVar2 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar18);
                                      if (0 < iVar2) {
                                        pcVar18 = "\n";
                                        iVar2 = (**(code **)(puStack_98 + -0x7e88))(pBVar5);
                                        if (0 < iVar2) {
                                          pEVar11 = X509_get_pubkey((X509 *)pcStack_d0);
                                          if (pEVar11 == (EVP_PKEY *)0x0) {
                                            (**(code **)(puStack_98 + -0x7fa8))
                                                      (pBVar5,"%12sUnable to load Public Key\n","");
                                            (**(code **)(puStack_98 + -0x7fa0))(pBVar5);
                                          }
                                          else {
                                            EVP_PKEY_print_public
                                                      (pBVar5,pEVar11,0x10,(ASN1_PCTX *)0x0);
                                            EVP_PKEY_free(pEVar11);
                                          }
                                          pcStack_d4 = (char *)0x0;
                                          pAStack_a0 = (ASN1_STRING *)&DAT_00000008;
                                          (**(code **)(puStack_98 + -0x6060))
                                                    (pBVar5,"X509v3 extensions",
                                                     pXStack_c4->extensions);
                                          sig = *(ASN1_BIT_STRING **)((int)pcStack_d0 + 8);
                                          pcVar18 = *(char **)((int)pcStack_d0 + 4);
                                          iVar2 = X509_signature_print
                                                            (pBVar5,(X509_ALGOR *)pcVar18,sig);
                                          if (0 < iVar2) {
                                            sig = (ASN1_STRING *)0x0;
                                            pcVar21 = *(char **)((uchar *)((int)pcStack_d0 + 0x58) +
                                                                0xc);
                                            iVar2 = X509_CERT_AUX_print(pBVar5,(X509_CERT_AUX *)
                                                                               pcVar21,0);
                                            pcVar20 = (char *)(uint)(iVar2 != 0);
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
      sig = (ASN1_STRING *)auStack_8c;
      iVar2 = (**(code **)(puStack_98 + -0x6a78))(iVar2,auStack_8c + 4);
      if ((iVar2 == 0) ||
         (pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,auStack_8c._0_4_),
         pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0)) goto LAB_0055c224;
      pcStack_d4 = &DAT_00000009;
      if (*(code **)(pEVar12 + 0x50) == (code *)0x0) goto LAB_0055c224;
      pAStack_a0 = (ASN1_STRING *)0x0;
      sig = (ASN1_STRING *)0x0;
      iVar2 = (**(code **)(pEVar12 + 0x50))(pBVar5);
      if (0 < iVar2) goto LAB_0055c240;
      pcVar20 = (char *)0x0;
    }
LAB_0055c384:
    (**(code **)(puStack_98 + -0x7f70))(pBVar5);
    pcVar18 = pcStack_d4;
    bp = pBVar5;
    pcStack_d4 = pcVar20;
  }
  if (puStack_84 == *(uchar **)puStack_cc) {
    return (int)pcVar20;
  }
  pcStack_b4 = X509_print_ex_fp;
  puVar8 = puStack_84;
  (**(code **)(puStack_98 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_d8 = bp;
  pcStack_c8 = unaff_s4;
  pcStack_c0 = unaff_s6;
  pAStack_bc = unaff_s7;
  uStack_b8 = unaff_s8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar5 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (pBVar5 == (BIO *)0x0) {
    pcVar20 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar3 = 0;
    goto LAB_0055c87c;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x6a,0,puVar8);
  if (((uint)sig & 0xf0000) == 0x40000) {
    iVar2 = 0xc;
    uVar4 = 10;
  }
  else {
    iVar2 = 0x10;
    uVar4 = 0x20;
    if (sig != (ASN1_STRING *)0x0) {
      iVar2 = 0;
    }
  }
  pXVar15 = *(X509_CINF **)pcVar21;
  if (((uint)pcVar18 & 1) == 0) {
    pcVar17 = "Certificate:\n";
    iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"Certificate:\n",0xd);
    if (0 < iVar13) {
      pcVar17 = "    Data:\n";
      iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"    Data:\n",10);
      if (0 < iVar13) goto LAB_0055c7a8;
    }
LAB_0055c864:
    pcVar20 = pcVar17;
    uVar3 = 0;
  }
  else {
LAB_0055c7a8:
    if (((uint)pcVar18 & 2) == 0) {
      lVar7 = ASN1_INTEGER_get((*(X509_CINF **)pcVar21)->version);
      pcVar17 = "%8sVersion: %lu (0x%lx)\n";
      iVar13 = (*(code *)PTR_BIO_printf_006a7f38)
                         (pBVar5,"%8sVersion: %lu (0x%lx)\n","",lVar7 + 1,lVar7);
      if (iVar13 < 1) goto LAB_0055c864;
    }
    if (((uint)pcVar18 & 4) == 0) {
      pcVar17 = "        Serial Number:";
      iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"        Serial Number:",0x16);
      if (0 < iVar13) {
        a = X509_get_serialNumber((X509 *)pcVar21);
        if (a->length < 5) {
          iVar13 = ASN1_INTEGER_get(a);
          if (a->type == 0x102) {
            iVar13 = -iVar13;
            pcVar17 = "-";
          }
          else {
            pcVar17 = "";
          }
          pcVar20 = " %s%lu (%s0x%lx)\n";
          iVar13 = (*(code *)PTR_BIO_printf_006a7f38)
                             (pBVar5," %s%lu (%s0x%lx)\n",pcVar17,iVar13,pcVar17,iVar13);
          if (0 < iVar13) goto LAB_0055c7c0;
          uVar3 = 0;
        }
        else {
          if (a->type == 0x102) {
            pcVar20 = " (Negative)";
          }
          else {
            pcVar20 = "";
          }
          pcVar17 = "\n%12s%s";
          iVar13 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"\n%12s%s","",pcVar20);
          if (iVar13 < 1) goto LAB_0055c864;
          iVar13 = 0;
          pcStack_ec = "%02x%c";
          do {
            if (a->length <= iVar13) goto LAB_0055c7c0;
            puVar8 = a->data + iVar13;
            iVar13 = iVar13 + 1;
            uVar9 = 10;
            if (iVar13 != a->length) {
              uVar9 = 0x3a;
            }
            pcVar20 = pcStack_ec;
            iVar10 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"%02x%c",*puVar8,uVar9);
          } while (0 < iVar10);
          uVar3 = 0;
        }
        goto LAB_0055c868;
      }
      goto LAB_0055c864;
    }
LAB_0055c7c0:
    if (((uint)pcVar18 & 8) != 0) goto LAB_0055c7c8;
    pcVar20 = *(char **)((int)pcVar21 + 4);
    pcVar17 = "    Signature Algorithm: ";
    iVar13 = (*(code *)PTR_BIO_puts_006a8058)(pBVar5);
    if (iVar13 < 1) goto LAB_0055c864;
    pcVar17 = (char *)*(stack_st_X509_NAME_ENTRY **)pcVar20;
    iVar13 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar17);
    if (iVar13 < 1) goto LAB_0055c864;
    iVar13 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(stack_st_X509_NAME_ENTRY **)pcVar20);
    if (((iVar13 == 0) ||
        (iVar13 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(iVar13,auStack_e0,&iStack_e4),
        iVar13 == 0)) ||
       ((pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,iStack_e4),
        pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0 || (*(code **)(pEVar12 + 0x50) == (code *)0x0)))) {
      pcVar20 = "\n";
      iVar13 = (*(code *)PTR_BIO_puts_006a8058)(pBVar5);
      if (0 < iVar13) goto LAB_0055c7c8;
      uVar3 = 0;
    }
    else {
      iVar13 = (**(code **)(pEVar12 + 0x50))(pBVar5,pcVar20,0,9,0);
      if (0 < iVar13) {
LAB_0055c7c8:
        if (((uint)pcVar18 & 0x10) == 0) {
          pcVar17 = "        Issuer:%c";
          iVar13 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"        Issuer:%c",uVar4);
          if (0 < iVar13) {
            pcVar17 = (char *)X509_get_issuer_name((X509 *)pcVar21);
            iVar13 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar17,iVar2,(ulong)sig);
            if (-1 < iVar13) {
              pcVar20 = "\n";
              iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n",1);
              if (iVar13 < 1) {
                uVar3 = 0;
                goto LAB_0055c868;
              }
              goto LAB_0055c7d4;
            }
          }
          goto LAB_0055c864;
        }
LAB_0055c7d4:
        if (((uint)pcVar18 & 0x20) == 0) {
          pcVar17 = "        Validity\n";
          iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"        Validity\n",0x11);
          if (0 < iVar13) {
            pcVar17 = "            Not Before: ";
            iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"            Not Before: ",0x18);
            if (0 < iVar13) {
              pAVar16 = (*(X509_CINF **)pcVar21)->validity->notBefore;
              if (pAVar16->type != 0x17) {
                if (pAVar16->type == 0x18) {
                  iVar13 = ASN1_GENERALIZEDTIME_print(pBVar5,pAVar16);
                  goto LAB_0055cd88;
                }
LAB_0055cbec:
                pcVar20 = "Bad time value";
                (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"Bad time value",0xe);
                uVar3 = 0;
                goto LAB_0055c868;
              }
              iVar13 = ASN1_UTCTIME_print(pBVar5,pAVar16);
LAB_0055cd88:
              pcVar17 = (char *)(EVP_PKEY *)0x670000;
              if (iVar13 != 0) {
                pcVar17 = "\n            Not After : ";
                iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n            Not After : ",0x19)
                ;
                if (0 < iVar13) {
                  pAVar16 = (*(X509_CINF **)pcVar21)->validity->notAfter;
                  if (pAVar16->type == 0x17) {
                    iVar13 = ASN1_UTCTIME_print(pBVar5,pAVar16);
                  }
                  else {
                    if (pAVar16->type != 0x18) goto LAB_0055cbec;
                    iVar13 = ASN1_GENERALIZEDTIME_print(pBVar5,pAVar16);
                  }
                  pcVar17 = (char *)(EVP_PKEY *)0x640000;
                  if (iVar13 != 0) {
                    pcVar20 = "\n";
                    iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n",1);
                    if (0 < iVar13) goto LAB_0055c7e0;
                    uVar3 = 0;
                    goto LAB_0055c868;
                  }
                }
              }
            }
          }
        }
        else {
LAB_0055c7e0:
          if (((uint)pcVar18 & 0x40) == 0) {
            pcVar17 = "        Subject:%c";
            iVar13 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"        Subject:%c",uVar4);
            if (0 < iVar13) {
              pcVar17 = (char *)X509_get_subject_name((X509 *)pcVar21);
              iVar2 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar17,iVar2,(ulong)sig);
              if (-1 < iVar2) {
                pcVar20 = "\n";
                iVar2 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n",1);
                if (iVar2 < 1) {
                  uVar3 = 0;
                  goto LAB_0055c868;
                }
                goto LAB_0055c7ec;
              }
            }
          }
          else {
LAB_0055c7ec:
            pcVar20 = "7 datafinal";
            if (((uint)pcVar18 & 0x80) != 0) {
LAB_0055c7f8:
              if (((uint)pcVar18 & 0x100) == 0) {
                pcVar20 = "X509v3 extensions";
                (*(code *)PTR_X509V3_extensions_print_006a9e80)
                          (pBVar5,"X509v3 extensions",pXVar15->extensions,pcVar18,8);
              }
              if (((uint)pcVar18 & 0x200) == 0) {
                pcVar20 = *(char **)((int)pcVar21 + 4);
                iVar2 = X509_signature_print
                                  (pBVar5,(X509_ALGOR *)pcVar20,
                                   *(ASN1_BIT_STRING **)((int)pcVar21 + 8));
                if (iVar2 < 1) {
                  uVar3 = 0;
                  goto LAB_0055c868;
                }
              }
              if (((uint)pcVar18 & 0x400) == 0) {
                pcVar20 = *(char **)((uchar *)((int)pcVar21 + 0x58) + 0xc);
                iVar2 = X509_CERT_AUX_print(pBVar5,(X509_CERT_AUX *)pcVar20,0);
                uVar3 = (uint)(iVar2 != 0);
              }
              else {
                uVar3 = 1;
              }
              goto LAB_0055c868;
            }
            pcVar17 = "        Subject Public Key Info:\n";
            iVar2 = (*(code *)PTR_BIO_write_006a7f14)
                              (pBVar5,"        Subject Public Key Info:\n",0x21);
            if (0 < iVar2) {
              pcVar17 = "%12sPublic Key Algorithm: ";
              iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"%12sPublic Key Algorithm: ","");
              if (0 < iVar2) {
                pcVar17 = (char *)pXVar15->key->algor->algorithm;
                iVar2 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar17);
                if (0 < iVar2) {
                  pcVar17 = "\n";
                  iVar2 = (*(code *)PTR_BIO_puts_006a8058)(pBVar5);
                  if (0 < iVar2) {
                    pEVar11 = X509_get_pubkey((X509 *)pcVar21);
                    if (pEVar11 == (EVP_PKEY *)0x0) {
                      pcVar20 = "%12sUnable to load Public Key\n";
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (pBVar5,"%12sUnable to load Public Key\n","");
                      (*(code *)PTR_ERR_print_errors_006a7f40)(pBVar5);
                    }
                    else {
                      pcVar20 = (char *)pEVar11;
                      EVP_PKEY_print_public(pBVar5,pEVar11,0x10,(ASN1_PCTX *)0x0);
                      EVP_PKEY_free(pEVar11);
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
      uVar3 = 0;
    }
  }
LAB_0055c868:
  (*(code *)PTR_BIO_free_006a7f70)(pBVar5);
LAB_0055c87c:
  if (iStack_dc == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = iStack_dc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcVar18 = X509_NAME_oneline((X509_NAME *)pcVar20,(char *)0x0,0);
  if (*pcVar18 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar18);
    return 1;
  }
  pcVar20 = pcVar18 + 2;
  cVar14 = pcVar18[1];
  pcVar21 = pcVar18 + 1;
  if (cVar14 == '/') goto LAB_0055cffc;
LAB_0055cf50:
  pcVar17 = pcVar21;
  pcVar19 = pcVar20;
  if (cVar14 != '\0') goto LAB_0055cff0;
  while (pcVar21 = pcVar20,
        pcVar20 = (char *)(*(code *)PTR_BIO_write_006a7f14)
                                    (iVar2,pcVar17,pcVar21 + (-1 - (int)pcVar17)),
        pcVar21 + (-1 - (int)pcVar17) == pcVar20) {
    if (pcVar21[-1] == '\0') {
LAB_0055cf88:
      iVar2 = 1;
      goto LAB_0055cf8c;
    }
    iVar13 = (*(code *)PTR_BIO_write_006a7f14)(iVar2,", ",2);
    if (iVar13 != 2) break;
    pcVar19 = pcVar21;
    if (pcVar21[-1] == '\0') goto LAB_0055cf88;
LAB_0055cff0:
    do {
      pcVar20 = pcVar19 + 1;
      cVar14 = *pcVar19;
      if (cVar14 != '/') goto LAB_0055cf50;
LAB_0055cffc:
      pcVar19 = pcVar20;
    } while ((0x19 < (byte)(*pcVar20 + 0xbfU)) ||
            ((pcVar17 = pcVar21, pcVar20[1] != 0x3d &&
             ((0x19 < ((int)pcVar20[1] - 0x41U & 0xff) || (pcVar20[2] != '='))))));
  }
  iVar2 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x75,7,"t_x509.c",0x20c);
LAB_0055cf8c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar18);
  return iVar2;
}

