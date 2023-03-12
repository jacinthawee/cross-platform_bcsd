
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  ASN1_INTEGER *a;
  byte *pbVar4;
  X509 *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  undefined4 uVar6;
  BIO *bp_00;
  int iVar7;
  char *pcVar8;
  ASN1_UTCTIME *pAVar9;
  char *pcVar10;
  ASN1_STRING *sig;
  char *cflag_00;
  X509_CINF *pXVar11;
  ASN1_STRING *pAVar12;
  ASN1_STRING *local_40;
  char *local_3c;
  int local_34;
  undefined auStack_30 [4];
  ASN1_STRING *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(ASN1_STRING **)PTR___stack_chk_guard_006a9ae8;
  local_40 = (ASN1_STRING *)&SUB_00000010;
  if ((nmflag & 0xf0000) == 0x40000) {
    pAVar12 = (ASN1_STRING *)&DAT_0000000a;
    local_40 = (ASN1_STRING *)&SUB_0000000c;
  }
  else {
    pAVar12 = (ASN1_STRING *)&DAT_00000020;
    if (nmflag != 0) {
      local_40 = (ASN1_STRING *)0x0;
    }
  }
  pXVar11 = x->cert_info;
  sig = local_2c;
  cflag_00 = (char *)cflag;
  if ((cflag & 1) == 0) {
    sig = (ASN1_STRING *)&DAT_0000000d;
    pcVar10 = "Certificate:\n";
    iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
    if (0 < iVar7) {
      sig = (ASN1_STRING *)&DAT_0000000a;
      pcVar10 = "    Data:\n";
      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
      if (0 < iVar7) goto LAB_0055824c;
    }
  }
  else {
LAB_0055824c:
    if ((cflag & 2) == 0) {
      lVar3 = ASN1_INTEGER_get(x->cert_info->version);
      cflag_00 = (char *)(lVar3 + 1);
      sig = (ASN1_STRING *)0x638d8c;
      pcVar10 = "%8sVersion: %lu (0x%lx)\n";
      iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
      if (iVar7 < 1) goto LAB_00558308;
    }
    if ((cflag & 4) == 0) {
      sig = (ASN1_STRING *)&DAT_00000016;
      pcVar10 = "        Serial Number:";
      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
      if (0 < iVar7) {
        a = X509_get_serialNumber(x);
        if ((a->length < 4) || ((a->length == 4 && (-1 < (char)*a->data)))) {
          cflag_00 = (char *)ASN1_INTEGER_get(a);
          if (a->type == 0x102) {
            cflag_00 = (char *)-(int)cflag_00;
            sig = (ASN1_STRING *)&DAT_006621f4;
          }
          else {
            sig = (ASN1_STRING *)0x638d8c;
          }
          pcVar8 = " %s%lu (%s0x%lx)\n";
          iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
          if (iVar7 < 1) {
            uVar2 = 0;
            goto LAB_0055830c;
          }
          goto LAB_00558264;
        }
        if (a->type == 0x102) {
          cflag_00 = " (Negative)";
        }
        else {
          cflag_00 = "";
        }
        sig = (ASN1_STRING *)0x638d8c;
        pcVar10 = "\n%12s%s";
        iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
        if (0 < iVar7) {
          pcVar10 = (char *)0x0;
          local_3c = "%02x%c";
          do {
            pcVar8 = (char *)a->length;
            cflag_00 = pcVar8;
            if ((int)pcVar8 <= (int)pcVar10) goto LAB_00558264;
            pbVar4 = a->data + (int)pcVar10;
            pcVar10 = pcVar10 + 1;
            sig = (ASN1_STRING *)(uint)*pbVar4;
            cflag_00 = (char *)0xa;
            if (pcVar8 != pcVar10) {
              cflag_00 = (char *)0x3a;
            }
            pcVar8 = local_3c;
            iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
          } while (0 < iVar7);
          uVar2 = 0;
          goto LAB_0055830c;
        }
      }
    }
    else {
LAB_00558264:
      if ((cflag & 8) == 0) {
        pcVar8 = (char *)pXVar11->signature;
        pcVar10 = "    Signature Algorithm: ";
        iVar7 = (*(code *)PTR_BIO_puts_006a6f58)(bp);
        if (0 < iVar7) {
          pcVar10 = (char *)*(X509_CINF **)pcVar8;
          iVar7 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcVar10);
          if (0 < iVar7) {
            iVar7 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(X509_CINF **)pcVar8);
            if (iVar7 != 0) {
              sig = (ASN1_STRING *)&local_34;
              iVar7 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(iVar7,auStack_30);
              if ((iVar7 != 0) &&
                 (pEVar5 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_34),
                 pEVar5 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
                cflag_00 = (char *)0x9;
                if (*(code **)(pEVar5 + 0x50) != (code *)0x0) {
                  sig = (ASN1_STRING *)0x0;
                  iVar7 = (**(code **)(pEVar5 + 0x50))(bp);
                  if (iVar7 < 1) {
                    uVar2 = 0;
                    goto LAB_0055830c;
                  }
                  goto LAB_0055826c;
                }
              }
            }
            pcVar8 = "\n";
            iVar7 = (*(code *)PTR_BIO_puts_006a6f58)(bp);
            if (iVar7 < 1) {
              uVar2 = 0;
              goto LAB_0055830c;
            }
            goto LAB_0055826c;
          }
        }
      }
      else {
LAB_0055826c:
        if ((cflag & 0x10) == 0) {
          pcVar10 = "        Issuer:%c";
          sig = pAVar12;
          iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
          if (0 < iVar7) {
            pcVar10 = (char *)X509_get_issuer_name(x);
            sig = local_40;
            cflag_00 = (char *)nmflag;
            iVar7 = X509_NAME_print_ex(bp,(X509_NAME *)pcVar10,(int)local_40,nmflag);
            if (-1 < iVar7) {
              sig = (ASN1_STRING *)0x1;
              pcVar8 = "\n";
              iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
              if (iVar7 < 1) {
                uVar2 = 0;
                goto LAB_0055830c;
              }
              goto LAB_00558278;
            }
          }
        }
        else {
LAB_00558278:
          if ((cflag & 0x20) == 0) {
            sig = (ASN1_STRING *)&DAT_00000011;
            pcVar10 = "        Validity\n";
            iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
            if (0 < iVar7) {
              sig = (ASN1_STRING *)&DAT_00000018;
              pcVar10 = "            Not Before: ";
              iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
              if (0 < iVar7) {
                pAVar9 = x->cert_info->validity->notBefore;
                if (pAVar9->type != 0x17) {
                  if (pAVar9->type == 0x18) {
                    iVar7 = ASN1_GENERALIZEDTIME_print(bp,pAVar9);
                    goto LAB_00558800;
                  }
LAB_005585c4:
                  sig = (ASN1_STRING *)&DAT_0000000e;
                  pcVar8 = "Bad time value";
                  (*(code *)PTR_BIO_write_006a6e14)(bp);
                  uVar2 = 0;
                  goto LAB_0055830c;
                }
                iVar7 = ASN1_UTCTIME_print(bp,pAVar9);
LAB_00558800:
                pcVar10 = (char *)(X509 *)0x670000;
                if (iVar7 != 0) {
                  sig = (ASN1_STRING *)&DAT_00000019;
                  pcVar10 = "\n            Not After : ";
                  iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
                  if (0 < iVar7) {
                    pAVar9 = x->cert_info->validity->notAfter;
                    if (pAVar9->type == 0x17) {
                      iVar7 = ASN1_UTCTIME_print(bp,pAVar9);
                    }
                    else {
                      if (pAVar9->type != 0x18) goto LAB_005585c4;
                      iVar7 = ASN1_GENERALIZEDTIME_print(bp,pAVar9);
                    }
                    pcVar10 = "-check_ss_sig";
                    if (iVar7 != 0) {
                      sig = (ASN1_STRING *)0x1;
                      pcVar8 = "\n";
                      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
                      if (iVar7 < 1) {
                        uVar2 = 0;
                        goto LAB_0055830c;
                      }
                      goto LAB_00558284;
                    }
                  }
                }
              }
            }
          }
          else {
LAB_00558284:
            if ((cflag & 0x40) == 0) {
              pcVar10 = "        Subject:%c";
              iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
              sig = pAVar12;
              if (0 < iVar7) {
                pcVar10 = (char *)X509_get_subject_name(x);
                iVar7 = X509_NAME_print_ex(bp,(X509_NAME *)pcVar10,(int)local_40,nmflag);
                sig = local_40;
                cflag_00 = (char *)nmflag;
                if (-1 < iVar7) {
                  sig = (ASN1_STRING *)0x1;
                  pcVar8 = "\n";
                  iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
                  cflag_00 = (char *)nmflag;
                  if (iVar7 < 1) {
                    uVar2 = 0;
                    goto LAB_0055830c;
                  }
                  goto LAB_00558290;
                }
              }
            }
            else {
LAB_00558290:
              pcVar8 = "encrypt";
              if ((cflag & 0x80) != 0) {
LAB_0055829c:
                if ((cflag & 0x100) == 0) {
                  sig = (ASN1_STRING *)pXVar11->extensions;
                  pcVar8 = "X509v3 extensions";
                  cflag_00 = (char *)cflag;
                  (*(code *)PTR_X509V3_extensions_print_006a8d60)(bp);
                }
                if ((cflag & 0x200) == 0) {
                  sig = x->signature;
                  pcVar8 = (char *)x->sig_alg;
                  iVar7 = X509_signature_print(bp,(X509_ALGOR *)pcVar8,sig);
                  if (iVar7 < 1) {
                    uVar2 = 0;
                    goto LAB_0055830c;
                  }
                }
                if ((cflag & 0x400) == 0) {
                  sig = (ASN1_STRING *)0x0;
                  pcVar8 = *(char **)(x->sha1_hash + 0xc);
                  iVar7 = X509_CERT_AUX_print(bp,(X509_CERT_AUX *)pcVar8,0);
                  uVar2 = (uint)(iVar7 != 0);
                }
                else {
                  uVar2 = 1;
                }
                goto LAB_0055830c;
              }
              sig = (ASN1_STRING *)0x21;
              pcVar10 = "        Subject Public Key Info:\n";
              iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp);
              if (0 < iVar7) {
                sig = (ASN1_STRING *)0x638d8c;
                pcVar10 = "%12sPublic Key Algorithm: ";
                iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp);
                if (0 < iVar7) {
                  pcVar10 = (char *)pXVar11->key->algor->algorithm;
                  iVar7 = i2a_ASN1_OBJECT(bp,(ASN1_OBJECT *)pcVar10);
                  if (0 < iVar7) {
                    pcVar10 = "\n";
                    iVar7 = (*(code *)PTR_BIO_puts_006a6f58)(bp);
                    if (0 < iVar7) {
                      pkey = (X509 *)X509_get_pubkey(x);
                      if (pkey == (X509 *)0x0) {
                        sig = (ASN1_STRING *)0x638d8c;
                        pcVar8 = "%12sUnable to load Public Key\n";
                        (*(code *)PTR_BIO_printf_006a6e38)(bp);
                        (*(code *)PTR_ERR_print_errors_006a6e40)(bp);
                      }
                      else {
                        cflag_00 = (char *)0x0;
                        sig = (ASN1_STRING *)&SUB_00000010;
                        pcVar8 = (char *)pkey;
                        EVP_PKEY_print_public(bp,(EVP_PKEY *)pkey,0x10,(ASN1_PCTX *)0x0);
                        EVP_PKEY_free((EVP_PKEY *)pkey);
                      }
                      goto LAB_0055829c;
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
LAB_00558308:
  pcVar8 = pcVar10;
  uVar2 = 0;
LAB_0055830c:
  if (local_2c == *(ASN1_STRING **)puVar1) {
    return uVar2;
  }
  pAVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar6 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar6);
  if (bp_00 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x76,7,"t_x509.c",0x5a);
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,pAVar12);
  iVar7 = X509_print_ex(bp_00,(X509 *)pcVar8,(ulong)sig,(ulong)cflag_00);
  (*(code *)PTR_BIO_free_006a6e70)(bp_00);
  return iVar7;
}

