
uint __regparm3 do_cmd(_LHASH *param_1,int param_2,char **param_3)

{
  char **ppcVar1;
  void *pvVar2;
  EVP_MD *pEVar3;
  code *pcVar4;
  EVP_CIPHER *pEVar5;
  BIO *pBVar6;
  int iVar7;
  EVP_PKEY_ASN1_METHOD *ameth;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  int in_GS_OFFSET;
  bool bVar14;
  byte bVar15;
  char *pcVar16;
  int local_40;
  int local_3c;
  byte local_38;
  char *local_34;
  char *local_30;
  undefined4 local_2c;
  char *local_28;
  code *local_24;
  int local_20;
  
  bVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 < 1) {
    uVar12 = 0;
    goto LAB_0804be1d;
  }
  uVar12 = 0;
  if (*param_3 == (char *)0x0) goto LAB_0804be1d;
  local_28 = *param_3;
  pvVar2 = lh_retrieve(param_1,&local_2c);
  if (pvVar2 == (void *)0x0) {
    pEVar3 = EVP_get_digestbyname(*param_3);
    if (pEVar3 == (EVP_MD *)0x0) {
      pEVar5 = EVP_get_cipherbyname(*param_3);
      bVar14 = pEVar5 == (EVP_CIPHER *)0x0;
      if (bVar14) {
        pcVar8 = *param_3;
        iVar10 = 3;
        pcVar16 = pcVar8;
        pcVar9 = "no-";
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          bVar14 = *pcVar16 == *pcVar9;
          pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        if (bVar14) {
          pBVar6 = BIO_new_fp(stdout,0);
          local_28 = *param_3 + 3;
          pvVar2 = lh_retrieve(param_1,&local_2c);
          uVar12 = (uint)(pvVar2 != (void *)0x0);
          if (pvVar2 == (void *)0x0) {
            BIO_printf(pBVar6,"%s\n",*param_3);
          }
          else {
            BIO_printf(pBVar6,"%s\n",*param_3 + 3);
          }
          BIO_free_all(pBVar6);
          goto LAB_0804be1d;
        }
        iVar10 = 5;
        pcVar16 = pcVar8;
        pcVar9 = "quit";
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          bVar14 = *pcVar16 == *pcVar9;
          pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        if (!bVar14) {
          bVar14 = *pcVar8 == 'q';
          if (bVar14) {
            bVar14 = pcVar8[1] == '\0';
            if (!bVar14) {
              iVar10 = 5;
              pcVar16 = pcVar8;
              pcVar9 = "exit";
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar14 = *pcVar16 == *pcVar9;
                pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
              } while (bVar14);
              if (!bVar14) goto LAB_0804bef4;
            }
          }
          else {
            iVar10 = 5;
            pcVar16 = pcVar8;
            pcVar9 = "exit";
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar14 = *pcVar16 == *pcVar9;
              pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
              pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
            } while (bVar14);
            if (!bVar14) {
              bVar14 = *pcVar8 == 'b';
              if (((bVar14) && (bVar14 = pcVar8[1] == 'y', bVar14)) &&
                 (bVar14 = pcVar8[2] == 'e', bVar14)) {
                bVar14 = pcVar8[3] == '\0';
                uVar12 = 0xffffffff;
                if (bVar14) goto LAB_0804be1d;
              }
LAB_0804bef4:
              iVar10 = 0x17;
              pcVar16 = pcVar8;
              pcVar9 = "list-standard-commands";
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar14 = *pcVar16 == *pcVar9;
                pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
              } while (bVar14);
              if (bVar14) {
                pBVar6 = BIO_new_fp(stdout,0);
                iVar10 = 1;
                iVar7 = load_config(bio_err,0);
joined_r0x0804c04b:
                if (iVar7 == 0) {
LAB_0804bfc8:
                  uVar12 = 1;
                  goto LAB_0804be1d;
                }
LAB_0804c051:
                if (functions._4_4_ != (char *)0x0) {
                  pcVar8 = functions._4_4_;
                  piVar11 = (int *)functions;
                  do {
                    if (*piVar11 == iVar10) {
                      BIO_printf(pBVar6,"%s\n",pcVar8);
                    }
                    pcVar8 = (char *)piVar11[4];
                    piVar11 = piVar11 + 3;
                  } while (pcVar8 != (char *)0x0);
                }
              }
              else {
                iVar10 = 0x1d;
                pcVar16 = pcVar8;
                pcVar9 = "list-message-digest-commands";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar14 = *pcVar16 == *pcVar9;
                  pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                } while (bVar14);
                if (bVar14) {
                  iVar10 = 2;
                  pBVar6 = BIO_new_fp(stdout,0);
                  iVar7 = load_config(bio_err,0);
                  goto joined_r0x0804c04b;
                }
                iVar10 = 0x1f;
                pcVar16 = pcVar8;
                pcVar9 = "list-message-digest-algorithms";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar14 = *pcVar16 == *pcVar9;
                  pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                } while (bVar14);
                if (bVar14) {
                  pBVar6 = BIO_new_fp(stdout,0);
                  iVar10 = load_config(bio_err,0);
                  if (iVar10 == 0) goto LAB_0804bfc8;
                  iVar10 = 5;
                  EVP_MD_do_all_sorted(list_md_fn,pBVar6);
                  goto LAB_0804c051;
                }
                iVar10 = 0x15;
                pcVar16 = pcVar8;
                pcVar9 = "list-cipher-commands";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar14 = *pcVar16 == *pcVar9;
                  pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                } while (bVar14);
                if (!bVar14) {
                  iVar10 = 0x17;
                  pcVar16 = pcVar8;
                  pcVar9 = "list-cipher-algorithms";
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar14 = *pcVar16 == *pcVar9;
                    pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                    pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                  } while (bVar14);
                  if (!bVar14) {
                    iVar10 = 0x1b;
                    pcVar16 = pcVar8;
                    pcVar9 = "list-public-key-algorithms";
                    do {
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      bVar14 = *pcVar16 == *pcVar9;
                      pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                      pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                    } while (bVar14);
                    if (!bVar14) {
                      BIO_printf(bio_err,"openssl:Error: \'%s\' is an invalid command.\n",pcVar8);
                      iVar10 = 0;
                      BIO_printf(bio_err,"\nStandard commands");
                      piVar11 = (int *)functions;
                      uVar12 = 0;
                      pcVar16 = functions._4_4_;
                      while (pcVar9 = pcVar16, pcVar9 != (char *)0x0) {
                        uVar13 = uVar12 + 1;
                        if ((uVar12 & 3) == 0) {
                          BIO_printf(bio_err,"\n",pcVar8);
                          iVar7 = *piVar11;
                          if (iVar7 == iVar10) {
LAB_0804c3e9:
                            pcVar9 = (char *)piVar11[1];
                          }
                          else {
LAB_0804c3df:
                            iVar10 = iVar7;
                            if (iVar7 == 2) {
                              pcVar16 = 
                              "\nMessage Digest commands (see the `dgst\' command for more details)\n"
                              ;
                            }
                            else {
                              if (iVar7 != 3) goto LAB_0804c3e9;
                              pcVar16 = 
                              "\nCipher commands (see the `enc\' command for more details)\n";
                            }
                            uVar13 = 1;
                            BIO_printf(bio_err,pcVar16,pcVar8);
                            pcVar9 = (char *)piVar11[1];
                          }
                        }
                        else {
                          iVar7 = *piVar11;
                          if (iVar7 != iVar10) {
                            BIO_printf(bio_err,"\n",pcVar8);
                            goto LAB_0804c3df;
                          }
                        }
                        BIO_printf(bio_err,"%-18s",pcVar9);
                        ppcVar1 = (char **)(piVar11 + 4);
                        piVar11 = piVar11 + 3;
                        uVar12 = uVar13;
                        pcVar8 = pcVar9;
                        pcVar16 = *ppcVar1;
                      }
                      uVar12 = 0;
                      BIO_printf(bio_err,"\n\n",pcVar8);
                      goto LAB_0804be1d;
                    }
                  }
                }
                iVar10 = 0x1b;
                pcVar16 = pcVar8;
                pcVar9 = "list-public-key-algorithms";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar14 = *pcVar16 == *pcVar9;
                  pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar15 * -2 + 1;
                } while (bVar14);
                if (bVar14) {
                  pBVar6 = BIO_new_fp(stdout,0);
                  iVar10 = load_config(bio_err,0);
                  if (iVar10 != 0) {
                    for (iVar10 = 0; iVar7 = EVP_PKEY_asn1_get_count(), iVar10 < iVar7;
                        iVar10 = iVar10 + 1) {
                      ameth = EVP_PKEY_asn1_get0(iVar10);
                      EVP_PKEY_asn1_get0_info
                                (&local_40,&local_3c,(int *)&local_38,&local_34,&local_30,ameth);
                      if ((local_38 & 1) == 0) {
                        BIO_printf(pBVar6,"Name: %s\n",local_34);
                        pcVar8 = "Builtin";
                        if ((local_38 & 2) != 0) {
                          pcVar8 = "External";
                        }
                        BIO_printf(pBVar6,"\tType: %s Algorithm\n",pcVar8);
                        pcVar8 = OBJ_nid2ln(local_40);
                        BIO_printf(pBVar6,"\tOID: %s\n",pcVar8);
                        if (local_30 == (char *)0x0) {
                          local_30 = "(none)";
                        }
                        BIO_printf(pBVar6,"\tPEM string: %s\n",local_30);
                      }
                      else {
                        pcVar8 = OBJ_nid2ln(local_40);
                        BIO_printf(pBVar6,"Name: %s\n",pcVar8);
                        pcVar8 = OBJ_nid2ln(local_3c);
                        BIO_printf(pBVar6,"\tType: Alias to %s\n",pcVar8);
                      }
                    }
                    iVar10 = 4;
                    goto LAB_0804c051;
                  }
                  goto LAB_0804bfc8;
                }
                iVar10 = 0x17;
                pcVar16 = "list-cipher-algorithms";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar14 = *pcVar8 == *pcVar16;
                  pcVar8 = pcVar8 + (uint)bVar15 * -2 + 1;
                  pcVar16 = pcVar16 + (uint)bVar15 * -2 + 1;
                } while (bVar14);
                if (!bVar14) {
                  pBVar6 = BIO_new_fp(stdout,0);
                  iVar10 = load_config(bio_err,0);
                  if (iVar10 != 0) {
                    iVar10 = 3;
                    goto LAB_0804c051;
                  }
                  goto LAB_0804bfc8;
                }
                pBVar6 = BIO_new_fp(stdout,0);
                iVar10 = load_config(bio_err,0);
                if (iVar10 == 0) goto LAB_0804bfc8;
                EVP_CIPHER_do_all_sorted(list_cipher_fn,pBVar6);
              }
              uVar12 = 0;
              BIO_free_all(pBVar6);
              goto LAB_0804be1d;
            }
          }
        }
        uVar12 = 0xffffffff;
        goto LAB_0804be1d;
      }
      local_2c = 3;
      local_24 = enc_main;
      pcVar4 = enc_main;
    }
    else {
      local_2c = 2;
      local_24 = dgst_main;
      pcVar4 = dgst_main;
    }
  }
  else {
    pcVar4 = *(code **)((int)pvVar2 + 8);
  }
  uVar12 = (*pcVar4)(param_2,param_3);
LAB_0804be1d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

