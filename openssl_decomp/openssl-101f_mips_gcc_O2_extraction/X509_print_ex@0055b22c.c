
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
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
  char *pcVar20;
  char *pcVar21;
  ASN1_INTEGER *unaff_s7;
  X509 *unaff_s8;
  char *pcStack_14c;
  int iStack_144;
  undefined auStack_140 [4];
  int iStack_13c;
  BIO *pBStack_138;
  char *pcStack_134;
  char *pcStack_130;
  undefined *puStack_12c;
  char *pcStack_128;
  X509_CINF *pXStack_124;
  char *pcStack_120;
  ASN1_INTEGER *pAStack_11c;
  X509 *pXStack_118;
  code *pcStack_114;
  ASN1_STRING *pAStack_100;
  char *pcStack_fc;
  undefined *puStack_f8;
  undefined auStack_ec [8];
  uchar *puStack_e4;
  BIO *pBStack_e0;
  X509 *pXStack_dc;
  char *pcStack_d8;
  undefined *puStack_d4;
  char *pcStack_d0;
  X509_CINF *pXStack_cc;
  char *pcStack_c8;
  ASN1_INTEGER *pAStack_c4;
  X509 *pXStack_c0;
  code *pcStack_bc;
  char *pcStack_a8;
  int iStack_a4;
  undefined *puStack_a0;
  int iStack_94;
  undefined auStack_90 [4];
  char *pcStack_8c;
  ulong uStack_88;
  BIO *pBStack_84;
  X509 *pXStack_80;
  undefined *puStack_7c;
  char *pcStack_78;
  X509 *pXStack_74;
  char *pcStack_70;
  ASN1_INTEGER *pAStack_6c;
  X509 *pXStack_68;
  code *pcStack_64;
  char *local_50;
  int local_4c;
  undefined *local_48;
  X509_CINF *local_40;
  char *local_3c;
  int local_34;
  undefined auStack_30 [4];
  BIO *local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  local_48 = &_gp;
  local_2c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  pXStack_74 = (X509 *)&SUB_0000000c;
  if ((nmflag & 0xf0000) == 0x40000) {
    pcStack_120 = &DAT_0000000a;
  }
  else {
    pXStack_74 = (X509 *)&SUB_00000010;
    pcStack_120 = &DAT_00000020;
    if (nmflag != 0) {
      pXStack_74 = (X509 *)0x0;
    }
  }
  local_40 = x->cert_info;
  if ((cflag & 1) == 0) {
    pcStack_d8 = "Certificate:\n";
    iVar3 = (*(code *)PTR_BIO_write_006a7f14)(bp,"Certificate:\n",0xd);
    if (0 < iVar3) {
      pcStack_d8 = "    Data:\n";
      iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"    Data:\n",10);
      if (0 < iVar3) goto LAB_0055b2b0;
    }
LAB_0055b36c:
    uVar2 = 0;
  }
  else {
LAB_0055b2b0:
    if ((cflag & 2) == 0) {
      local_50 = (char *)ASN1_INTEGER_get(x->cert_info->version);
      pcStack_d8 = "%8sVersion: %lu (0x%lx)\n";
      iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,"%8sVersion: %lu (0x%lx)\n","",local_50 + 1);
      if (iVar3 < 1) goto LAB_0055b36c;
    }
    if ((cflag & 4) == 0) {
      pcStack_d8 = "        Serial Number:";
      iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"        Serial Number:",0x16);
      if (0 < iVar3) {
        unaff_s7 = X509_get_serialNumber(x);
        if (unaff_s7->length < 5) {
          local_4c = ASN1_INTEGER_get(unaff_s7);
          if (unaff_s7->type == 0x102) {
            local_4c = -local_4c;
            local_50 = "-";
          }
          else {
            local_50 = "";
          }
          pcStack_d8 = " %s%lu (%s0x%lx)\n";
          iVar3 = (**(code **)(local_48 + -0x7fa8))(bp," %s%lu (%s0x%lx)\n",local_50,local_4c);
          if (0 < iVar3) goto LAB_0055b2c8;
          uVar2 = 0;
        }
        else {
          if (unaff_s7->type == 0x102) {
            pcVar18 = " (Negative)";
          }
          else {
            pcVar18 = "";
          }
          pcStack_d8 = "\n%12s%s";
          iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,"\n%12s%s","",pcVar18);
          if (iVar3 < 1) goto LAB_0055b36c;
          unaff_s8 = (X509 *)0x0;
          local_3c = "%02x%c";
          do {
            if ((int)(X509 *)unaff_s7->length <= (int)unaff_s8) goto LAB_0055b2c8;
            puVar8 = unaff_s7->data + (int)unaff_s8;
            unaff_s8 = (X509 *)((int)&unaff_s8->cert_info + 1);
            uVar4 = 10;
            if ((X509 *)unaff_s7->length != unaff_s8) {
              uVar4 = 0x3a;
            }
            pcStack_d8 = local_3c;
            iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,local_3c,*puVar8,uVar4);
          } while (0 < iVar3);
          uVar2 = 0;
        }
        goto LAB_0055b370;
      }
      goto LAB_0055b36c;
    }
LAB_0055b2c8:
    if ((cflag & 8) != 0) goto LAB_0055b2d0;
    unaff_s8 = (X509 *)x->sig_alg;
    pcStack_d8 = "    Signature Algorithm: ";
    iVar3 = (**(code **)(local_48 + -0x7e88))(bp);
    if (iVar3 < 1) goto LAB_0055b36c;
    pcStack_d8 = (char *)unaff_s8->cert_info;
    iVar3 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcStack_d8);
    if (iVar3 < 1) goto LAB_0055b36c;
    iVar3 = (**(code **)(local_48 + -0x7cb4))(unaff_s8->cert_info);
    if ((((iVar3 == 0) ||
         (iVar3 = (**(code **)(local_48 + -0x6a78))(iVar3,auStack_30,&local_34), iVar3 == 0)) ||
        (pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34),
        pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0)) || (*(code **)(pEVar12 + 0x50) == (code *)0x0)) {
      pcStack_d8 = "\n";
      iVar3 = (**(code **)(local_48 + -0x7e88))(bp);
      if (0 < iVar3) goto LAB_0055b2d0;
      uVar2 = 0;
    }
    else {
      local_50 = (char *)0x0;
      pcStack_d8 = (char *)unaff_s8;
      iVar3 = (**(code **)(pEVar12 + 0x50))(bp,unaff_s8,0,9);
      if (0 < iVar3) {
LAB_0055b2d0:
        if ((cflag & 0x10) == 0) {
          pcStack_d8 = "        Issuer:%c";
          iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,"        Issuer:%c",pcStack_120);
          if (0 < iVar3) {
            pcStack_d8 = (char *)X509_get_issuer_name(x);
            iVar3 = X509_NAME_print_ex(bp,(X509_NAME *)pcStack_d8,(int)pXStack_74,nmflag);
            if (-1 < iVar3) {
              pcStack_d8 = "\n";
              iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"\n",1);
              if (iVar3 < 1) {
                uVar2 = 0;
                goto LAB_0055b370;
              }
              goto LAB_0055b2dc;
            }
          }
          goto LAB_0055b36c;
        }
LAB_0055b2dc:
        if ((cflag & 0x20) == 0) {
          pcStack_d8 = "        Validity\n";
          iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"        Validity\n",0x11);
          if (0 < iVar3) {
            pcStack_d8 = "            Not Before: ";
            iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"            Not Before: ",0x18);
            if (0 < iVar3) {
              pAVar16 = x->cert_info->validity->notBefore;
              if (pAVar16->type != 0x17) {
                if (pAVar16->type == 0x18) {
                  iVar3 = ASN1_GENERALIZEDTIME_print(bp,pAVar16);
                  goto LAB_0055b7e4;
                }
LAB_0055b678:
                pcStack_d8 = "Bad time value";
                (**(code **)(local_48 + -0x7fcc))(bp,"Bad time value",0xe);
                uVar2 = 0;
                goto LAB_0055b370;
              }
              iVar3 = ASN1_UTCTIME_print(bp,pAVar16);
LAB_0055b7e4:
              pcStack_d8 = "7 datafinal";
              if (iVar3 != 0) {
                pcStack_d8 = "\n            Not After : ";
                iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"\n            Not After : ",0x19);
                if (0 < iVar3) {
                  pAVar16 = x->cert_info->validity->notAfter;
                  if (pAVar16->type == 0x17) {
                    iVar3 = ASN1_UTCTIME_print(bp,pAVar16);
                  }
                  else {
                    if (pAVar16->type != 0x18) goto LAB_0055b678;
                    iVar3 = ASN1_GENERALIZEDTIME_print(bp,pAVar16);
                  }
                  pcStack_d8 = "s\n";
                  if (iVar3 != 0) {
                    pcStack_d8 = "\n";
                    iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"\n",1);
                    if (0 < iVar3) goto LAB_0055b2e8;
                    uVar2 = 0;
                    goto LAB_0055b370;
                  }
                }
              }
            }
          }
        }
        else {
LAB_0055b2e8:
          if ((cflag & 0x40) == 0) {
            pcStack_d8 = "        Subject:%c";
            iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,"        Subject:%c",pcStack_120);
            if (0 < iVar3) {
              pcStack_d8 = (char *)X509_get_subject_name(x);
              iVar3 = X509_NAME_print_ex(bp,(X509_NAME *)pcStack_d8,(int)pXStack_74,nmflag);
              if (-1 < iVar3) {
                pcStack_d8 = "\n";
                iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"\n",1);
                if (iVar3 < 1) {
                  uVar2 = 0;
                  goto LAB_0055b370;
                }
                goto LAB_0055b2f4;
              }
            }
          }
          else {
LAB_0055b2f4:
            pcStack_d8 = "7 datafinal";
            if ((cflag & 0x80) != 0) {
LAB_0055b300:
              if ((cflag & 0x100) == 0) {
                pcStack_d8 = "X509v3 extensions";
                local_50 = (char *)0x8;
                (**(code **)(local_48 + -0x6060))(bp,"X509v3 extensions",local_40->extensions,cflag)
                ;
              }
              if ((cflag & 0x200) == 0) {
                pcStack_d8 = (char *)x->sig_alg;
                iVar3 = X509_signature_print(bp,(X509_ALGOR *)pcStack_d8,x->signature);
                if (iVar3 < 1) {
                  uVar2 = 0;
                  goto LAB_0055b370;
                }
              }
              cflag = cflag & 0x400;
              if (cflag == 0) {
                pcStack_d8 = *(char **)(x->sha1_hash + 0xc);
                iVar3 = X509_CERT_AUX_print(bp,(X509_CERT_AUX *)pcStack_d8,0);
                uVar2 = (uint)(iVar3 != 0);
              }
              else {
                uVar2 = 1;
              }
              goto LAB_0055b370;
            }
            pcStack_d8 = "        Subject Public Key Info:\n";
            iVar3 = (**(code **)(local_48 + -0x7fcc))(bp,"        Subject Public Key Info:\n",0x21);
            if (0 < iVar3) {
              nmflag = 0x640000;
              pcStack_d8 = "%12sPublic Key Algorithm: ";
              iVar3 = (**(code **)(local_48 + -0x7fa8))(bp,"%12sPublic Key Algorithm: ","");
              if (0 < iVar3) {
                pcStack_d8 = (char *)local_40->key->algor->algorithm;
                iVar3 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcStack_d8);
                if (0 < iVar3) {
                  pcStack_d8 = "\n";
                  iVar3 = (**(code **)(local_48 + -0x7e88))(bp);
                  if (0 < iVar3) {
                    pXStack_74 = (X509 *)X509_get_pubkey(x);
                    if (pXStack_74 == (X509 *)0x0) {
                      pcStack_d8 = "%12sUnable to load Public Key\n";
                      (**(code **)(local_48 + -0x7fa8))(bp,"%12sUnable to load Public Key\n","");
                      (**(code **)(local_48 + -0x7fa0))(bp);
                    }
                    else {
                      pcStack_d8 = (char *)pXStack_74;
                      EVP_PKEY_print_public(bp,(EVP_PKEY *)pXStack_74,0x10,(ASN1_PCTX *)0x0);
                      EVP_PKEY_free((EVP_PKEY *)pXStack_74);
                    }
                    goto LAB_0055b300;
                  }
                }
              }
            }
          }
        }
        goto LAB_0055b36c;
      }
      uVar2 = 0;
    }
  }
LAB_0055b370:
  if (local_2c == *(BIO **)puStack_7c) {
    return uVar2;
  }
  pcStack_64 = X509_print;
  pBStack_138 = local_2c;
  (**(code **)(local_48 + -0x5328))();
  puStack_d4 = PTR___stack_chk_guard_006aabf0;
  pcStack_130 = "Certificate:\n";
  puStack_a0 = &_gp;
  pcStack_8c = *(char **)PTR___stack_chk_guard_006aabf0;
  pXStack_124 = *(X509_CINF **)pcStack_d8;
  uStack_88 = cflag;
  pBStack_84 = bp;
  pXStack_80 = x;
  pcStack_78 = (char *)nmflag;
  pcStack_70 = pcStack_120;
  pAStack_6c = unaff_s7;
  pXStack_68 = unaff_s8;
  iVar3 = (*(code *)PTR_BIO_write_006a7f14)();
  if (iVar3 < 1) {
LAB_0055bcd8:
    uVar2 = 0;
  }
  else {
    pcStack_130 = "    Data:\n";
    iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"    Data:\n",10);
    if (iVar3 < 1) goto LAB_0055bcd8;
    nmflag = 0x640000;
    pcStack_a8 = (char *)ASN1_INTEGER_get((*(X509_CINF **)pcStack_d8)->version);
    pcStack_130 = "%8sVersion: %lu (0x%lx)\n";
    iVar3 = (**(code **)(puStack_a0 + -0x7fa8))
                      (pBStack_138,"%8sVersion: %lu (0x%lx)\n","",pcStack_a8 + 1);
    if (iVar3 < 1) goto LAB_0055bcd8;
    pcStack_130 = "        Serial Number:";
    iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"        Serial Number:",0x16);
    if (iVar3 < 1) goto LAB_0055bcd8;
    unaff_s7 = X509_get_serialNumber((X509 *)pcStack_d8);
    if (4 < unaff_s7->length) {
      if (unaff_s7->type == 0x102) {
        pcVar18 = " (Negative)";
      }
      else {
        pcVar18 = "";
      }
      pcStack_130 = "\n%12s%s";
      iVar3 = (**(code **)(puStack_a0 + -0x7fa8))(pBStack_138,"\n%12s%s","",pcVar18);
      if (0 < iVar3) {
        bp = (BIO *)0x0;
        unaff_s8 = (X509 *)&DAT_0000003a;
        pcStack_120 = "%02x%c";
        do {
          if ((int)(X509 *)unaff_s7->length <= (int)bp) goto LAB_0055bb30;
          puVar8 = unaff_s7->data + (int)bp;
          bp = (BIO *)((int)&((X509 *)bp)->cert_info + 1);
          uVar4 = 10;
          if ((X509 *)bp != (X509 *)unaff_s7->length) {
            uVar4 = 0x3a;
          }
          pcStack_130 = pcStack_120;
          iVar3 = (**(code **)(puStack_a0 + -0x7fa8))(pBStack_138,"%02x%c",*puVar8,uVar4);
        } while (0 < iVar3);
      }
      goto LAB_0055bcd8;
    }
    iStack_a4 = ASN1_INTEGER_get(unaff_s7);
    if (unaff_s7->type == 0x102) {
      iStack_a4 = -iStack_a4;
      pcStack_a8 = "-";
    }
    else {
      pcStack_a8 = "";
    }
    pcStack_130 = " %s%lu (%s0x%lx)\n";
    iVar3 = (**(code **)(puStack_a0 + -0x7fa8))
                      (pBStack_138," %s%lu (%s0x%lx)\n",pcStack_a8,iStack_a4);
    if (iVar3 < 1) goto LAB_0055bcd8;
LAB_0055bb30:
    bp = *(BIO **)((int)pcStack_d8 + 4);
    pcStack_130 = "    Signature Algorithm: ";
    iVar3 = (**(code **)(puStack_a0 + -0x7e88))(pBStack_138);
    if (iVar3 < 1) goto LAB_0055bcd8;
    pcStack_130 = (char *)((X509 *)bp)->cert_info;
    iVar3 = i2a_ASN1_OBJECT(pBStack_138,(ASN1_OBJECT *)pcStack_130);
    if (iVar3 < 1) goto LAB_0055bcd8;
    iVar3 = (**(code **)(puStack_a0 + -0x7cb4))(((X509 *)bp)->cert_info);
    if (((iVar3 == 0) ||
        (iVar3 = (**(code **)(puStack_a0 + -0x6a78))(iVar3,auStack_90,&iStack_94), iVar3 == 0)) ||
       ((pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,iStack_94),
        pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0 || (*(code **)(pEVar12 + 0x50) == (code *)0x0)))) {
      pcStack_130 = "\n";
      iVar3 = (**(code **)(puStack_a0 + -0x7e88))(pBStack_138);
      if (0 < iVar3) goto LAB_0055bb98;
      goto LAB_0055bcd8;
    }
    pcStack_a8 = (char *)0x0;
    pcStack_130 = (char *)bp;
    iVar3 = (**(code **)(pEVar12 + 0x50))(pBStack_138,bp,0,9);
    if (0 < iVar3) {
LAB_0055bb98:
      pcStack_130 = "        Issuer:%c";
      iVar3 = (**(code **)(puStack_a0 + -0x7fa8))(pBStack_138,"        Issuer:%c",0x20);
      if (0 < iVar3) {
        pcStack_130 = (char *)X509_get_issuer_name((X509 *)pcStack_d8);
        iVar3 = X509_NAME_print_ex(pBStack_138,(X509_NAME *)pcStack_130,0x10,0);
        if (-1 < iVar3) {
          bp = (BIO *)0x640000;
          pcStack_130 = "\n";
          iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"\n",1);
          if (0 < iVar3) {
            pcStack_130 = "        Validity\n";
            iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"        Validity\n",0x11);
            if (0 < iVar3) {
              pcStack_130 = "            Not Before: ";
              iVar3 = (**(code **)(puStack_a0 + -0x7fcc))
                                (pBStack_138,"            Not Before: ",0x18);
              if (0 < iVar3) {
                pAVar16 = (*(X509_CINF **)pcStack_d8)->validity->notBefore;
                if (pAVar16->type != 0x17) {
                  if (pAVar16->type == 0x18) {
                    iVar3 = ASN1_GENERALIZEDTIME_print(pBStack_138,pAVar16);
                    goto LAB_0055bd24;
                  }
LAB_0055bc6c:
                  pcStack_130 = "Bad time value";
                  (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"Bad time value",0xe);
                  uVar2 = 0;
                  goto LAB_0055bcdc;
                }
                iVar3 = ASN1_UTCTIME_print(pBStack_138,pAVar16);
LAB_0055bd24:
                pcStack_130 = "7 datafinal";
                if (iVar3 != 0) {
                  pcStack_130 = "\n            Not After : ";
                  iVar3 = (**(code **)(puStack_a0 + -0x7fcc))
                                    (pBStack_138,"\n            Not After : ",0x19);
                  if (0 < iVar3) {
                    pcStack_130 = (char *)(*(X509_CINF **)pcStack_d8)->validity->notAfter;
                    if (*(X509_ALGOR **)((int)pcStack_130 + 4) == (X509_ALGOR *)&DAT_00000017) {
                      iVar3 = ASN1_UTCTIME_print(pBStack_138,(ASN1_UTCTIME *)pcStack_130);
                    }
                    else {
                      if (*(X509_ALGOR **)((int)pcStack_130 + 4) != (X509_ALGOR *)&DAT_00000018)
                      goto LAB_0055bc6c;
                      iVar3 = ASN1_GENERALIZEDTIME_print
                                        (pBStack_138,(ASN1_GENERALIZEDTIME *)pcStack_130);
                    }
                    if (iVar3 != 0) {
                      pcStack_130 = "\n";
                      iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"\n",1);
                      bp = (BIO *)0x640000;
                      if (0 < iVar3) {
                        pcStack_130 = "        Subject:%c";
                        iVar3 = (**(code **)(puStack_a0 + -0x7fa8))
                                          (pBStack_138,"        Subject:%c",0x20);
                        if (0 < iVar3) {
                          pcStack_130 = (char *)X509_get_subject_name((X509 *)pcStack_d8);
                          iVar3 = X509_NAME_print_ex(pBStack_138,(X509_NAME *)pcStack_130,0x10,0);
                          if (-1 < iVar3) {
                            pcStack_130 = "\n";
                            iVar3 = (**(code **)(puStack_a0 + -0x7fcc))(pBStack_138,"\n",1);
                            if (0 < iVar3) {
                              pcStack_130 = "        Subject Public Key Info:\n";
                              iVar3 = (**(code **)(puStack_a0 + -0x7fcc))
                                                (pBStack_138,"        Subject Public Key Info:\n",
                                                 0x21);
                              if (0 < iVar3) {
                                pcStack_130 = "%12sPublic Key Algorithm: ";
                                iVar3 = (**(code **)(puStack_a0 + -0x7fa8))
                                                  (pBStack_138,"%12sPublic Key Algorithm: ","");
                                if (0 < iVar3) {
                                  pcStack_130 = (char *)pXStack_124->key->algor->algorithm;
                                  iVar3 = i2a_ASN1_OBJECT(pBStack_138,(ASN1_OBJECT *)pcStack_130);
                                  if (0 < iVar3) {
                                    pcStack_130 = "\n";
                                    iVar3 = (**(code **)(puStack_a0 + -0x7e88))(pBStack_138);
                                    if (0 < iVar3) {
                                      bp = (BIO *)X509_get_pubkey((X509 *)pcStack_d8);
                                      if ((X509 *)bp == (X509 *)0x0) {
                                        (**(code **)(puStack_a0 + -0x7fa8))
                                                  (pBStack_138,"%12sUnable to load Public Key\n","")
                                        ;
                                        (**(code **)(puStack_a0 + -0x7fa0))(pBStack_138);
                                      }
                                      else {
                                        EVP_PKEY_print_public
                                                  (pBStack_138,(EVP_PKEY *)bp,0x10,(ASN1_PCTX *)0x0)
                                        ;
                                        EVP_PKEY_free((EVP_PKEY *)bp);
                                      }
                                      pcStack_a8 = (char *)0x8;
                                      (**(code **)(puStack_a0 + -0x6060))
                                                (pBStack_138,"X509v3 extensions",
                                                 pXStack_124->extensions,0);
                                      pcStack_130 = *(char **)((int)pcStack_d8 + 4);
                                      iVar3 = X509_signature_print
                                                        (pBStack_138,(X509_ALGOR *)pcStack_130,
                                                         *(ASN1_BIT_STRING **)((int)pcStack_d8 + 8))
                                      ;
                                      if (0 < iVar3) {
                                        pcStack_130 = *(char **)((uchar *)((int)pcStack_d8 + 0x58) +
                                                                0xc);
                                        iVar3 = X509_CERT_AUX_print(pBStack_138,
                                                                    (X509_CERT_AUX *)pcStack_130,0);
                                        uVar2 = (uint)(iVar3 != 0);
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
    uVar2 = 0;
  }
LAB_0055bcdc:
  if (pcStack_8c == *(char **)puStack_d4) {
    return uVar2;
  }
  pcStack_bc = X509_print_fp;
  pcStack_134 = pcStack_8c;
  (**(code **)(puStack_a0 + -0x5328))();
  puStack_12c = PTR___stack_chk_guard_006aabf0;
  puStack_f8 = &_gp;
  puStack_e4 = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pBStack_e0 = pBStack_138;
  pXStack_dc = (X509 *)bp;
  pcStack_d0 = (char *)nmflag;
  pXStack_cc = pXStack_124;
  pcStack_c8 = pcStack_120;
  pAStack_c4 = unaff_s7;
  pXStack_c0 = unaff_s8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar5 = (BIO *)(**(code **)(puStack_f8 + -0x7f3c))(uVar4);
  if (pBVar5 == (BIO *)0x0) {
    sig = (ASN1_STRING *)&DAT_00000007;
    pcVar18 = "t_x509.c";
    pAStack_100 = (ASN1_STRING *)&DAT_0000005a;
    pcVar21 = &DAT_00000076;
    (**(code **)(puStack_f8 + -0x6eb0))(0xb);
    pcVar20 = (char *)0x0;
  }
  else {
    (**(code **)(puStack_f8 + -0x7fc8))(pBVar5,0x6a,0);
    sig = (ASN1_STRING *)&DAT_0000000d;
    pXStack_124 = *(X509_CINF **)pcStack_130;
    pcVar18 = "Certificate:\n";
    iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
    if (iVar3 < 1) {
LAB_0055c380:
      pcVar21 = pcVar18;
      pcVar20 = (char *)0x0;
    }
    else {
      sig = (ASN1_STRING *)&DAT_0000000a;
      pcVar18 = "    Data:\n";
      iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
      if (iVar3 < 1) goto LAB_0055c380;
      nmflag = 0x640000;
      pAStack_100 = (ASN1_STRING *)ASN1_INTEGER_get((*(X509_CINF **)pcStack_130)->version);
      pcStack_134 = (char *)((int)&pAStack_100->length + 1);
      sig = (ASN1_STRING *)0x6395d0;
      pcVar18 = "%8sVersion: %lu (0x%lx)\n";
      iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
      if (iVar3 < 1) goto LAB_0055c380;
      sig = (ASN1_STRING *)&DAT_00000016;
      pcVar18 = "        Serial Number:";
      iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
      if (iVar3 < 1) goto LAB_0055c380;
      unaff_s7 = X509_get_serialNumber((X509 *)pcStack_130);
      if (4 < unaff_s7->length) {
        if (unaff_s7->type == 0x102) {
          pcStack_134 = " (Negative)";
        }
        else {
          pcStack_134 = "";
        }
        sig = (ASN1_STRING *)0x6395d0;
        pcVar18 = "\n%12s%s";
        iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
        if (0 < iVar3) {
          pcVar20 = (char *)0x0;
          unaff_s8 = (X509 *)&DAT_0000003a;
          pcStack_120 = "%02x%c";
          do {
            pcVar18 = (char *)unaff_s7->length;
            pcStack_134 = pcVar18;
            if ((int)pcVar18 <= (int)pcVar20) goto LAB_0055c1d8;
            pbVar6 = unaff_s7->data + (int)pcVar20;
            pcVar20 = pcVar20 + 1;
            sig = (ASN1_STRING *)(uint)*pbVar6;
            pcStack_134 = &DAT_0000000a;
            if (pcVar20 != pcVar18) {
              pcStack_134 = &DAT_0000003a;
            }
            pcVar18 = pcStack_120;
            iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
          } while (0 < iVar3);
        }
        goto LAB_0055c380;
      }
      pcStack_134 = (char *)ASN1_INTEGER_get(unaff_s7);
      if (unaff_s7->type == 0x102) {
        pcStack_134 = (char *)-(int)pcStack_134;
        sig = (ASN1_STRING *)&DAT_00662b94;
      }
      else {
        sig = (ASN1_STRING *)0x6395d0;
      }
      pcVar18 = " %s%lu (%s0x%lx)\n";
      pAStack_100 = sig;
      pcStack_fc = pcStack_134;
      iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
      if (iVar3 < 1) goto LAB_0055c380;
LAB_0055c1d8:
      pcVar21 = *(char **)((int)pcStack_130 + 4);
      pcVar18 = "    Signature Algorithm: ";
      iVar3 = (**(code **)(puStack_f8 + -0x7e88))(pBVar5);
      if (iVar3 < 1) goto LAB_0055c380;
      pcVar18 = (char *)*(X509_CINF **)pcVar21;
      iVar3 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar18);
      if (iVar3 < 1) goto LAB_0055c380;
      iVar3 = (**(code **)(puStack_f8 + -0x7cb4))(*(X509_CINF **)pcVar21);
      if (iVar3 == 0) {
LAB_0055c224:
        pcVar18 = "\n";
        iVar3 = (**(code **)(puStack_f8 + -0x7e88))(pBVar5);
        if (0 < iVar3) {
LAB_0055c240:
          sig = (ASN1_STRING *)&DAT_00000020;
          pcVar18 = "        Issuer:%c";
          iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
          if (0 < iVar3) {
            pcVar18 = (char *)X509_get_issuer_name((X509 *)pcStack_130);
            pcStack_134 = (char *)0x0;
            sig = (ASN1_STRING *)&SUB_00000010;
            iVar3 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar18,0x10,0);
            if (-1 < iVar3) {
              sig = (ASN1_STRING *)0x1;
              pcVar18 = "\n";
              iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
              if (0 < iVar3) {
                sig = (ASN1_STRING *)&DAT_00000011;
                pcVar18 = "        Validity\n";
                iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                if (0 < iVar3) {
                  sig = (ASN1_STRING *)&DAT_00000018;
                  pcVar18 = "            Not Before: ";
                  iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                  if (0 < iVar3) {
                    pAVar16 = (*(X509_CINF **)pcStack_130)->validity->notBefore;
                    if (pAVar16->type != 0x17) {
                      if (pAVar16->type == 0x18) {
                        iVar3 = ASN1_GENERALIZEDTIME_print(pBVar5,pAVar16);
                        goto LAB_0055c474;
                      }
LAB_0055c314:
                      sig = (ASN1_STRING *)&DAT_0000000e;
                      pcVar21 = "Bad time value";
                      (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                      pcVar20 = (char *)0x0;
                      goto LAB_0055c384;
                    }
                    iVar3 = ASN1_UTCTIME_print(pBVar5,pAVar16);
LAB_0055c474:
                    pcVar18 = (char *)(X509 *)0x670000;
                    if (iVar3 != 0) {
                      sig = (ASN1_STRING *)&DAT_00000019;
                      pcVar18 = "\n            Not After : ";
                      iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                      if (0 < iVar3) {
                        pcVar18 = (char *)(*(X509_CINF **)pcStack_130)->validity->notAfter;
                        if (*(X509_ALGOR **)((int)pcVar18 + 4) == (X509_ALGOR *)&DAT_00000017) {
                          iVar3 = ASN1_UTCTIME_print(pBVar5,(ASN1_UTCTIME *)pcVar18);
                        }
                        else {
                          if (*(X509_ALGOR **)((int)pcVar18 + 4) != (X509_ALGOR *)&DAT_00000018)
                          goto LAB_0055c314;
                          iVar3 = ASN1_GENERALIZEDTIME_print(pBVar5,(ASN1_GENERALIZEDTIME *)pcVar18)
                          ;
                        }
                        if (iVar3 != 0) {
                          pcVar18 = "\n";
                          sig = (ASN1_STRING *)0x1;
                          iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                          if (0 < iVar3) {
                            sig = (ASN1_STRING *)&DAT_00000020;
                            pcVar18 = "        Subject:%c";
                            iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
                            if (0 < iVar3) {
                              pcVar18 = (char *)X509_get_subject_name((X509 *)pcStack_130);
                              pcStack_134 = (char *)0x0;
                              sig = (ASN1_STRING *)&SUB_00000010;
                              iVar3 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar18,0x10,0);
                              if (-1 < iVar3) {
                                sig = (ASN1_STRING *)0x1;
                                pcVar18 = "\n";
                                iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                                if (0 < iVar3) {
                                  sig = (ASN1_STRING *)0x21;
                                  pcVar18 = "        Subject Public Key Info:\n";
                                  iVar3 = (**(code **)(puStack_f8 + -0x7fcc))(pBVar5);
                                  if (0 < iVar3) {
                                    sig = (ASN1_STRING *)0x6395d0;
                                    pcVar18 = "%12sPublic Key Algorithm: ";
                                    iVar3 = (**(code **)(puStack_f8 + -0x7fa8))(pBVar5);
                                    if (0 < iVar3) {
                                      pcVar18 = (char *)pXStack_124->key->algor->algorithm;
                                      iVar3 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar18);
                                      if (0 < iVar3) {
                                        pcVar18 = "\n";
                                        iVar3 = (**(code **)(puStack_f8 + -0x7e88))(pBVar5);
                                        if (0 < iVar3) {
                                          pEVar11 = X509_get_pubkey((X509 *)pcStack_130);
                                          if (pEVar11 == (EVP_PKEY *)0x0) {
                                            (**(code **)(puStack_f8 + -0x7fa8))
                                                      (pBVar5,"%12sUnable to load Public Key\n","");
                                            (**(code **)(puStack_f8 + -0x7fa0))(pBVar5);
                                          }
                                          else {
                                            EVP_PKEY_print_public
                                                      (pBVar5,pEVar11,0x10,(ASN1_PCTX *)0x0);
                                            EVP_PKEY_free(pEVar11);
                                          }
                                          pcStack_134 = (char *)0x0;
                                          pAStack_100 = (ASN1_STRING *)&DAT_00000008;
                                          (**(code **)(puStack_f8 + -0x6060))
                                                    (pBVar5,"X509v3 extensions",
                                                     pXStack_124->extensions);
                                          sig = *(ASN1_BIT_STRING **)((int)pcStack_130 + 8);
                                          pcVar18 = *(char **)((int)pcStack_130 + 4);
                                          iVar3 = X509_signature_print
                                                            (pBVar5,(X509_ALGOR *)pcVar18,sig);
                                          if (0 < iVar3) {
                                            sig = (ASN1_STRING *)0x0;
                                            pcVar21 = *(char **)((uchar *)((int)pcStack_130 + 0x58)
                                                                + 0xc);
                                            iVar3 = X509_CERT_AUX_print(pBVar5,(X509_CERT_AUX *)
                                                                               pcVar21,0);
                                            pcVar20 = (char *)(uint)(iVar3 != 0);
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
      sig = (ASN1_STRING *)auStack_ec;
      iVar3 = (**(code **)(puStack_f8 + -0x6a78))(iVar3,auStack_ec + 4);
      if ((iVar3 == 0) ||
         (pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,auStack_ec._0_4_),
         pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0)) goto LAB_0055c224;
      pcStack_134 = &DAT_00000009;
      if (*(code **)(pEVar12 + 0x50) == (code *)0x0) goto LAB_0055c224;
      pAStack_100 = (ASN1_STRING *)0x0;
      sig = (ASN1_STRING *)0x0;
      iVar3 = (**(code **)(pEVar12 + 0x50))(pBVar5);
      if (0 < iVar3) goto LAB_0055c240;
      pcVar20 = (char *)0x0;
    }
LAB_0055c384:
    (**(code **)(puStack_f8 + -0x7f70))(pBVar5);
    pcVar18 = pcStack_134;
    pBStack_138 = pBVar5;
    pcStack_134 = pcVar20;
  }
  if (puStack_e4 == *(uchar **)puStack_12c) {
    return (int)pcVar20;
  }
  pcStack_114 = X509_print_ex_fp;
  puVar8 = puStack_e4;
  (**(code **)(puStack_f8 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_13c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_128 = (char *)nmflag;
  pAStack_11c = unaff_s7;
  pXStack_118 = unaff_s8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pBVar5 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (pBVar5 == (BIO *)0x0) {
    pcVar20 = &DAT_00000076;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x76,7,"t_x509.c",0x5a);
    uVar2 = 0;
    goto LAB_0055c87c;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x6a,0,puVar8);
  if (((uint)sig & 0xf0000) == 0x40000) {
    iVar3 = 0xc;
    uVar4 = 10;
  }
  else {
    iVar3 = 0x10;
    uVar4 = 0x20;
    if (sig != (ASN1_STRING *)0x0) {
      iVar3 = 0;
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
    uVar2 = 0;
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
          uVar2 = 0;
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
          pcStack_14c = "%02x%c";
          do {
            if (a->length <= iVar13) goto LAB_0055c7c0;
            puVar8 = a->data + iVar13;
            iVar13 = iVar13 + 1;
            uVar9 = 10;
            if (iVar13 != a->length) {
              uVar9 = 0x3a;
            }
            pcVar20 = pcStack_14c;
            iVar10 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"%02x%c",*puVar8,uVar9);
          } while (0 < iVar10);
          uVar2 = 0;
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
    if ((((iVar13 == 0) ||
         (iVar13 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(iVar13,auStack_140,&iStack_144),
         iVar13 == 0)) ||
        (pEVar12 = EVP_PKEY_asn1_find((ENGINE **)0x0,iStack_144),
        pEVar12 == (EVP_PKEY_ASN1_METHOD *)0x0)) || (*(code **)(pEVar12 + 0x50) == (code *)0x0)) {
      pcVar20 = "\n";
      iVar13 = (*(code *)PTR_BIO_puts_006a8058)(pBVar5);
      if (0 < iVar13) goto LAB_0055c7c8;
      uVar2 = 0;
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
            iVar13 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar17,iVar3,(ulong)sig);
            if (-1 < iVar13) {
              pcVar20 = "\n";
              iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n",1);
              if (iVar13 < 1) {
                uVar2 = 0;
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
                uVar2 = 0;
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
                    uVar2 = 0;
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
              iVar3 = X509_NAME_print_ex(pBVar5,(X509_NAME *)pcVar17,iVar3,(ulong)sig);
              if (-1 < iVar3) {
                pcVar20 = "\n";
                iVar3 = (*(code *)PTR_BIO_write_006a7f14)(pBVar5,"\n",1);
                if (iVar3 < 1) {
                  uVar2 = 0;
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
                iVar3 = X509_signature_print
                                  (pBVar5,(X509_ALGOR *)pcVar20,
                                   *(ASN1_BIT_STRING **)((int)pcVar21 + 8));
                if (iVar3 < 1) {
                  uVar2 = 0;
                  goto LAB_0055c868;
                }
              }
              if (((uint)pcVar18 & 0x400) == 0) {
                pcVar20 = *(char **)((uchar *)((int)pcVar21 + 0x58) + 0xc);
                iVar3 = X509_CERT_AUX_print(pBVar5,(X509_CERT_AUX *)pcVar20,0);
                uVar2 = (uint)(iVar3 != 0);
              }
              else {
                uVar2 = 1;
              }
              goto LAB_0055c868;
            }
            pcVar17 = "        Subject Public Key Info:\n";
            iVar3 = (*(code *)PTR_BIO_write_006a7f14)
                              (pBVar5,"        Subject Public Key Info:\n",0x21);
            if (0 < iVar3) {
              pcVar17 = "%12sPublic Key Algorithm: ";
              iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(pBVar5,"%12sPublic Key Algorithm: ","");
              if (0 < iVar3) {
                pcVar17 = (char *)pXVar15->key->algor->algorithm;
                iVar3 = i2a_ASN1_OBJECT(pBVar5,(ASN1_OBJECT *)pcVar17);
                if (0 < iVar3) {
                  pcVar17 = "\n";
                  iVar3 = (*(code *)PTR_BIO_puts_006a8058)(pBVar5);
                  if (0 < iVar3) {
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
      uVar2 = 0;
    }
  }
LAB_0055c868:
  (*(code *)PTR_BIO_free_006a7f70)(pBVar5);
LAB_0055c87c:
  if (iStack_13c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = iStack_13c;
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
                                    (iVar3,pcVar17,pcVar21 + (-1 - (int)pcVar17)),
        pcVar21 + (-1 - (int)pcVar17) == pcVar20) {
    if (pcVar21[-1] == '\0') {
LAB_0055cf88:
      iVar3 = 1;
      goto LAB_0055cf8c;
    }
    iVar13 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,", ",2);
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
  iVar3 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x75,7,"t_x509.c",0x20c);
LAB_0055cf8c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar18);
  return iVar3;
}

