
void * do_cmd(_LHASH *param_1,int param_2,char **param_3)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  EVP_MD *pEVar4;
  EVP_CIPHER *pEVar5;
  int iVar6;
  BIO *pBVar7;
  int iVar8;
  EVP_PKEY_ASN1_METHOD *ameth;
  undefined *puVar9;
  code *pcVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  uint uVar14;
  int local_38;
  int local_34;
  uint local_30;
  char *local_2c;
  char *local_28;
  undefined4 local_24;
  char *local_20;
  undefined4 local_1c;
  
  if (param_2 < 1) {
    return (void *)0x0;
  }
  local_20 = *param_3;
  if (local_20 == (char *)0x0) {
    return (void *)0x0;
  }
  pvVar3 = lh_retrieve(param_1,&local_24);
  if (pvVar3 != (void *)0x0) {
    pcVar10 = *(code **)((int)pvVar3 + 8);
LAB_000137f4:
    pvVar3 = (void *)(*pcVar10)(param_2,param_3);
    return pvVar3;
  }
  pEVar4 = EVP_get_digestbyname(*param_3);
  if (pEVar4 != (EVP_MD *)0x0) {
    pcVar10 = dgst_main + 1;
    local_24 = 2;
    local_1c = 0x171c9;
    goto LAB_000137f4;
  }
  pEVar5 = EVP_get_cipherbyname(*param_3);
  if (pEVar5 != (EVP_CIPHER *)0x0) {
    pcVar10 = enc_main + 1;
    local_24 = 3;
    local_1c = 0x18fb5;
    goto LAB_000137f4;
  }
  pcVar12 = *param_3;
  iVar6 = strncmp(pcVar12,"no-",3);
  if (iVar6 == 0) {
    pBVar7 = BIO_new_fp(stdout,0);
    local_20 = *param_3 + 3;
    pvVar3 = lh_retrieve(param_1,&local_24);
    if (pvVar3 != (void *)0x0) {
      pvVar3 = (void *)0x1;
    }
    if (pvVar3 == (void *)0x0) {
      BIO_printf(pBVar7,"%s\n",*param_3);
    }
    else {
      BIO_printf(pBVar7,"%s\n",*param_3 + 3);
    }
    BIO_free_all(pBVar7);
    return pvVar3;
  }
  iVar6 = strcmp(pcVar12,"quit");
  if (iVar6 == 0) {
    return (void *)0xffffffff;
  }
  cVar2 = *pcVar12;
  if (cVar2 == 'q') {
    if (pcVar12[1] == '\0') {
      return (void *)0xffffffff;
    }
    iVar6 = strcmp(pcVar12,"exit");
    if (iVar6 == 0) {
      return (void *)0xffffffff;
    }
  }
  else {
    iVar6 = strcmp(pcVar12,"exit");
    if (iVar6 == 0) {
      return (void *)0xffffffff;
    }
    if ((((cVar2 == 'b') && (pcVar12[1] == 'y')) && (pcVar12[2] == 'e')) && (pcVar12[3] == '\0')) {
      return (void *)0xffffffff;
    }
  }
  iVar6 = strcmp(pcVar12,"list-standard-commands");
  if (iVar6 == 0) {
    iVar6 = 1;
LAB_000139ba:
    pBVar7 = BIO_new_fp(stdout,0);
    iVar8 = load_config(bio_err,0);
    if (iVar8 == 0) {
      return (void *)0x1;
    }
  }
  else {
    iVar6 = strcmp(pcVar12,"list-message-digest-commands");
    if (iVar6 == 0) {
      iVar6 = 2;
      goto LAB_000139ba;
    }
    iVar6 = strcmp(pcVar12,"list-message-digest-algorithms");
    if (iVar6 == 0) {
      pBVar7 = BIO_new_fp(stdout,0);
      iVar6 = load_config(bio_err,0);
      if (iVar6 == 0) {
        return (void *)0x1;
      }
      iVar6 = 5;
      EVP_MD_do_all_sorted(list_md_fn + 1,pBVar7);
    }
    else {
      iVar6 = strcmp(pcVar12,"list-cipher-commands");
      if ((iVar6 == 0) || (iVar6 = strcmp(pcVar12,"list-cipher-algorithms"), iVar6 == 0)) {
        iVar6 = strcmp(pcVar12,"list-public-key-algorithms");
        if (iVar6 != 0) {
          iVar6 = 3;
          iVar8 = strcmp(pcVar12,"list-cipher-algorithms");
          if (iVar8 == 0) {
            pBVar7 = BIO_new_fp(stdout,0);
            iVar6 = load_config(bio_err,0);
            if (iVar6 == 0) {
              return (void *)0x1;
            }
            EVP_CIPHER_do_all_sorted(list_cipher_fn + 1,pBVar7);
            goto LAB_000139ae;
          }
          goto LAB_000139ba;
        }
      }
      else {
        iVar6 = strcmp(pcVar12,"list-public-key-algorithms");
        if (iVar6 != 0) {
          BIO_printf(bio_err,"openssl:Error: \'%s\' is an invalid command.\n",pcVar12);
          BIO_printf(bio_err,"\nStandard commands");
          if (PTR_s_verify_00189214 != (undefined *)0x0) {
            iVar6 = 0;
            uVar11 = 0;
            puVar13 = &DAT_0018921c;
            do {
              uVar14 = uVar11 + 1;
              if ((uVar11 & 3) == 0) {
                BIO_printf(bio_err,"\n");
                iVar8 = puVar13[-3];
                uVar11 = uVar14;
                if (iVar8 != iVar6) {
LAB_00013bc2:
                  iVar6 = iVar8;
                  if (iVar8 == 2) {
                    BIO_printf(bio_err,
                               "\nMessage Digest commands (see the `dgst\' command for more details)\n"
                              );
                    uVar11 = 1;
                  }
                  else {
                    uVar11 = uVar14;
                    if (iVar8 == 3) {
                      BIO_printf(bio_err,
                                 "\nCipher commands (see the `enc\' command for more details)\n");
                      uVar11 = 1;
                    }
                  }
                }
              }
              else {
                iVar8 = puVar13[-3];
                uVar11 = uVar14;
                if (iVar8 != iVar6) {
                  BIO_printf(bio_err,"\n");
                  goto LAB_00013bc2;
                }
              }
              BIO_printf(bio_err,"%-18s",puVar13[-2]);
              piVar1 = puVar13 + 1;
              puVar13 = puVar13 + 3;
            } while (*piVar1 != 0);
          }
          BIO_printf(bio_err,"\n\n");
          return (void *)0x0;
        }
      }
      pBVar7 = BIO_new_fp(stdout,0);
      iVar6 = load_config(bio_err,0);
      if (iVar6 == 0) {
        return (void *)0x1;
      }
      for (iVar6 = 0; iVar8 = EVP_PKEY_asn1_get_count(), iVar6 < iVar8; iVar6 = iVar6 + 1) {
        ameth = EVP_PKEY_asn1_get0(iVar6);
        EVP_PKEY_asn1_get0_info(&local_38,&local_34,(int *)&local_30,&local_2c,&local_28,ameth);
        if ((int)(local_30 << 0x1f) < 0) {
          pcVar12 = OBJ_nid2ln(local_38);
          BIO_printf(pBVar7,"Name: %s\n",pcVar12);
          pcVar12 = OBJ_nid2ln(local_34);
          BIO_printf(pBVar7,"\tType: Alias to %s\n",pcVar12);
        }
        else {
          BIO_printf(pBVar7,"Name: %s\n",local_2c);
          BIO_printf(pBVar7,"\tType: %s Algorithm\n");
          pcVar12 = OBJ_nid2ln(local_38);
          BIO_printf(pBVar7,"\tOID: %s\n",pcVar12);
          if (local_28 == (char *)0x0) {
            local_28 = "(none)";
          }
          BIO_printf(pBVar7,"\tPEM string: %s\n",local_28);
        }
      }
      iVar6 = 4;
    }
  }
  puVar13 = &DAT_0018921c;
  puVar9 = PTR_s_verify_00189214;
  while (puVar9 != (undefined *)0x0) {
    if (puVar13[-3] == iVar6) {
      BIO_printf(pBVar7,"%s\n");
    }
    puVar9 = (undefined *)puVar13[1];
    puVar13 = puVar13 + 3;
  }
LAB_000139ae:
  BIO_free_all(pBVar7);
  return (void *)0x0;
}

