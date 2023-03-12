
int __regparm3
do_body(X509 **param_1_00,EVP_PKEY *param_2_00,X509 *param_3_00,undefined4 param_1,
       undefined4 param_2,_STACK *param_3,int *param_4,BIGNUM *param_5,int param_6,
       undefined4 param_7,undefined4 param_8,int param_9,char *param_10,char *param_11,int param_12,
       int param_13,int param_14,X509_REQ *param_15,char *param_16,CONF *param_17,uint param_18,
       ulong param_19,int param_20,undefined4 param_21,int param_22)

{
  char cVar1;
  X509_CINF *pXVar2;
  ASN1_TIME *pAVar3;
  X509_REQ_INFO *a;
  int iVar4;
  X509 *pXVar5;
  X509_REQ_INFO *pXVar6;
  ASN1_UNIVERSALSTRING *s;
  ASN1_OBJECT *obj;
  void *pvVar7;
  X509_NAME *pXVar8;
  OPENSSL_STRING *ppcVar9;
  uchar *puVar10;
  ASN1_INTEGER *pAVar11;
  FILE *pkey;
  uint uVar12;
  EVP_PKEY *pkey_00;
  FILE *pFVar13;
  X509_NAME *pXVar14;
  undefined4 extraout_ECX;
  undefined *extraout_ECX_00;
  X509_NAME *lastpos;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar15;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  FILE *extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_EDX;
  X509_NAME *extraout_EDX_00;
  X509_NAME *extraout_EDX_01;
  uchar *puVar16;
  undefined4 extraout_EDX_02;
  X509 *pXVar17;
  X509_NAME *pXVar18;
  X509_NAME *unaff_ESI;
  int iVar19;
  X509 *unaff_EDI;
  int in_GS_OFFSET;
  byte bVar20;
  char *pcVar21;
  ASN1_OBJECT *pAVar22;
  char *format;
  EVP_PKEY *pEVar23;
  X509_NAME *pXVar24;
  undefined *puVar25;
  FILE *pFVar26;
  X509_NAME *local_d8;
  X509_NAME *local_d4;
  X509_NAME *local_d0;
  ASN1_STRING *local_bc;
  ASN1_STRING *local_b8;
  int local_b4;
  X509V3_CTX local_70;
  OPENSSL_STRING local_54 [3];
  X509_NAME *local_48;
  char *local_44;
  _IO_marker *local_40;
  byte local_39 [25];
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = (X509_REQ_INFO *)ASN1_UTCTIME_new();
  if (a == (X509_REQ_INFO *)0x0) {
    BIO_printf(bio_err,"malloc error\n",extraout_ECX,extraout_ECX);
    iVar4 = 0;
    goto LAB_0804a96c;
  }
  local_54[0] = (OPENSSL_STRING)0x0;
  local_54[1] = (OPENSSL_STRING)0x0;
  local_54[2] = (char *)0x0;
  local_48 = (X509_NAME *)0x0;
  local_44 = (char *)0x0;
  local_40 = (_IO_marker *)0x0;
  pXVar6 = a;
  if (param_6 == 0) {
LAB_0804a1e5:
    if (param_20 != 0) {
      BIO_printf(bio_err,"The Subject\'s Distinguished Name is as follows\n",pXVar6,pXVar6);
    }
    pXVar14 = param_15->req_info->subject;
    for (pXVar17 = (X509 *)0x0; iVar4 = X509_NAME_entry_count(pXVar14), (int)pXVar17 < iVar4;
        pXVar17 = (X509 *)((int)&pXVar17->cert_info + 1)) {
      s = (ASN1_UNIVERSALSTRING *)X509_NAME_get_entry(pXVar14,(int)pXVar17);
      unaff_ESI = (X509_NAME *)X509_NAME_ENTRY_get_data((X509_NAME_ENTRY *)s);
      unaff_EDI = (X509 *)X509_NAME_ENTRY_get_object((X509_NAME_ENTRY *)s);
      if (msie_hack != 0) {
        s = (ASN1_UNIVERSALSTRING *)OBJ_obj2nid((ASN1_OBJECT *)s->length);
        if (unaff_ESI->modified == 0x1c) {
          ASN1_UNIVERSALSTRING_to_string(s);
        }
        if (unaff_ESI->modified == 0x16) {
          if (s != (ASN1_UNIVERSALSTRING *)0x30) {
            unaff_ESI->modified = 0x14;
          }
        }
        else if ((s == (ASN1_UNIVERSALSTRING *)0x30) && (unaff_ESI->modified == 0x13)) {
          unaff_ESI->modified = 0x16;
        }
      }
      iVar4 = OBJ_obj2nid((ASN1_OBJECT *)unaff_EDI);
      if ((param_9 != 0) || (iVar4 != 0x30)) {
        iVar19 = OBJ_obj2nid((ASN1_OBJECT *)unaff_EDI);
        if ((iVar19 == 0x30) && (unaff_ESI->modified != 0x16)) {
          pcVar21 = "\nemailAddress type needs to be of type IA5STRING\n";
        }
        else {
          if ((unaff_ESI->modified == 0x1e) || (unaff_ESI->modified == 0xc)) {
LAB_0804a34b:
            if (param_20 != 0) {
              old_entry_print(bio_err,unaff_EDI,unaff_ESI,s);
            }
            goto LAB_0804a366;
          }
          iVar19 = ASN1_PRINTABLE_type((uchar *)unaff_ESI->bytes,(int)unaff_ESI->entries);
          if (iVar19 == 0x14) {
            if (unaff_ESI->modified == 0x14) goto LAB_0804a34b;
          }
          else if ((iVar19 != 0x16) || (unaff_ESI->modified != 0x13)) goto LAB_0804a34b;
          pcVar21 = "\nThe string contains characters that are illegal for the ASN.1 type\n";
        }
        iVar4 = -1;
        pXVar5 = (X509 *)0x0;
        BIO_printf(bio_err,pcVar21,iVar19,iVar19);
        local_d8 = (X509_NAME *)0x0;
        local_d4 = (X509_NAME *)0x0;
        local_d0 = (X509_NAME *)0x0;
        goto LAB_0804a8cc;
      }
LAB_0804a366:
    }
    local_d4 = X509_NAME_new();
    if (local_d4 == (X509_NAME *)0x0) {
      iVar4 = -1;
      pXVar5 = (X509 *)0x0;
      BIO_printf(bio_err,"Memory allocation failure\n",unaff_EDI,unaff_EDI);
      local_d8 = (X509_NAME *)0x0;
      local_d0 = (X509_NAME *)0x0;
    }
    else {
      if (param_22 == 0) {
        local_d0 = X509_NAME_dup(param_3_00->cert_info->subject);
      }
      else {
        local_d0 = X509_NAME_dup(pXVar14);
      }
      if (local_d0 == (X509_NAME *)0x0) {
LAB_0804a4c6:
        iVar4 = -1;
        pXVar5 = (X509 *)0x0;
        local_d8 = (X509_NAME *)0x0;
      }
      else {
        local_b8 = (ASN1_STRING *)0x0;
        local_bc = (ASN1_STRING *)0x0;
        for (local_b4 = 0; iVar4 = sk_num(param_3), local_b4 < iVar4; local_b4 = local_b4 + 1) {
          pvVar7 = sk_value(param_3,local_b4);
          iVar4 = OBJ_txt2nid(*(char **)((int)pvVar7 + 4));
          if (iVar4 == 0) {
            pcVar21 = "%s:unknown object type in \'policy\' configuration\n";
            unaff_EDI = *(X509 **)((int)pvVar7 + 4);
            puVar25 = extraout_ECX_00;
LAB_0804a4b8:
            BIO_printf(bio_err,pcVar21,unaff_EDI,puVar25);
            goto LAB_0804a4c6;
          }
          obj = OBJ_nid2obj(iVar4);
          pXVar18 = (X509_NAME *)0xffffffff;
LAB_0804a41b:
          do {
            unaff_ESI = (X509_NAME *)X509_NAME_get_index_by_OBJ(pXVar14,obj,(int)pXVar18);
            if ((int)unaff_ESI < 0) {
              pXVar17 = (X509 *)((int)&pXVar18->entries + 1);
              if (pXVar17 != (X509 *)0x0) break;
              pXVar5 = (X509 *)0x0;
            }
            else {
              pXVar5 = (X509 *)X509_NAME_get_entry(pXVar14,(int)unaff_ESI);
            }
            unaff_EDI = *(X509 **)((int)pvVar7 + 8);
            iVar4 = strcmp((char *)unaff_EDI,"optional");
            pXVar17 = pXVar5;
            pXVar18 = unaff_ESI;
            pXVar8 = unaff_ESI;
            if (iVar4 == 0) {
              if (pXVar5 != (X509 *)0x0) goto LAB_0804a5f7;
            }
            else {
              puVar25 = (undefined *)strcmp((char *)unaff_EDI,"supplied");
              if (puVar25 == (undefined *)0x0) {
                if (pXVar5 == (X509 *)0x0) {
                  uVar15 = *(undefined4 *)((int)pvVar7 + 4);
                  pcVar21 = "The %s field needed to be supplied and was missing\n";
LAB_0804a542:
                  iVar4 = -1;
                  BIO_printf(bio_err,pcVar21,uVar15,puVar25);
                  local_d8 = (X509_NAME *)0x0;
                  goto LAB_0804a8cc;
                }
              }
              else {
                puVar25 = (undefined *)strcmp((char *)unaff_EDI,"match");
                if (puVar25 != (undefined *)0x0) {
                  pcVar21 = "%s:invalid type in \'policy\' configuration\n";
                  goto LAB_0804a4b8;
                }
                if (pXVar5 == (X509 *)0x0) {
                  uVar15 = *(undefined4 *)((int)pvVar7 + 4);
                  pcVar21 = "The mandatory %s field was missing\n";
                  goto LAB_0804a542;
                }
                lastpos = (X509_NAME *)0xffffffff;
                pXVar17 = unaff_EDI;
                do {
                  pAVar22 = obj;
                  pXVar24 = lastpos;
                  pXVar8 = (X509_NAME *)X509_NAME_get_index_by_OBJ(local_d0,obj,(int)lastpos);
                  if (((int)pXVar8 < 0) &&
                     (puVar25 = (undefined *)((int)&lastpos->entries + 1),
                     puVar25 == (undefined *)0x0)) {
                    unaff_EDI = *(X509 **)((int)pvVar7 + 4);
                    pcVar21 = 
                    "The %s field does not exist in the CA certificate,\nthe \'policy\' is misconfigured\n"
                    ;
                    goto LAB_0804a4b8;
                  }
                  if ((int)pXVar8 < 0) {
                    puVar10 = "NULL";
                    if (local_bc != (ASN1_STRING *)0x0) {
                      puVar10 = local_bc->data;
                    }
                    puVar16 = "NULL";
                    if (local_b8 != (ASN1_STRING *)0x0) {
                      puVar16 = local_b8->data;
                    }
                    pXVar5 = (X509 *)0x0;
                    iVar4 = -1;
                    BIO_printf(bio_err,
                               "The %s field needed to be the same in the\nCA certificate (%s) and the request (%s)\n"
                               ,*(undefined4 *)((int)pvVar7 + 4),puVar16,puVar10,pAVar22,pXVar24,
                               pXVar17);
                    local_d8 = (X509_NAME *)0x0;
                    goto LAB_0804a8cc;
                  }
                  pXVar17 = (X509 *)X509_NAME_get_entry(local_d0,(int)pXVar8);
                  local_bc = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY *)pXVar5);
                  local_b8 = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY *)pXVar17);
                  iVar4 = ASN1_STRING_cmp(local_bc,local_b8);
                  lastpos = pXVar8;
                } while (iVar4 != 0);
                unaff_EDI = pXVar17;
                if (pXVar17 == (X509 *)0x0) goto LAB_0804a41b;
              }
LAB_0804a5f7:
              puVar25 = (undefined *)0x0;
              pXVar5 = (X509 *)0xffffffff;
              iVar4 = X509_NAME_add_entry(local_d4,(X509_NAME_ENTRY *)pXVar17,-1,0);
              if (iVar4 == 0) {
                X509_NAME_ENTRY_free((X509_NAME_ENTRY *)pXVar17);
                pcVar21 = "Memory allocation failure\n";
                unaff_EDI = pXVar5;
                goto LAB_0804a4b8;
              }
            }
          } while (-1 < (int)pXVar8);
        }
        if (preserve != 0) {
          unaff_ESI = local_d4;
          X509_NAME_free(local_d4);
          local_d4 = X509_NAME_dup(pXVar14);
          if (local_d4 == (X509_NAME *)0x0) {
            local_d8 = (X509_NAME *)0x0;
            iVar4 = -1;
            pXVar5 = (X509 *)0x0;
            goto LAB_0804a8cc;
          }
        }
        if (param_14 != 0) {
          BIO_printf(bio_err,"The subject name appears to be ok, checking data base for clashes\n",
                     pXVar17,pXVar17);
        }
        local_d8 = local_d4;
        if (param_9 == 0) {
          pcVar21 = (char *)X509_NAME_dup(local_d4);
          local_d8 = (X509_NAME *)pcVar21;
          if ((X509_NAME *)pcVar21 != (X509_NAME *)0x0) {
            while (iVar4 = X509_NAME_get_index_by_NID((X509_NAME *)pcVar21,0x30,-1),
                  unaff_ESI = (X509_NAME *)pcVar21, -1 < iVar4) {
              unaff_EDI = (X509 *)X509_NAME_get_entry((X509_NAME *)pcVar21,iVar4);
              X509_NAME_delete_entry((X509_NAME *)pcVar21,iVar4);
              X509_NAME_ENTRY_free((X509_NAME_ENTRY *)unaff_EDI);
            }
            goto LAB_0804a6e1;
          }
LAB_0804a724:
          format = "Memory allocation failure\n";
          pXVar14 = (X509_NAME *)pcVar21;
        }
        else {
LAB_0804a6e1:
          if (param_5->top == 0) {
            pcVar21 = BUF_strdup("00");
          }
          else {
            pcVar21 = BN_bn2hex(param_5);
          }
          local_48 = (X509_NAME *)pcVar21;
          if ((X509_NAME *)pcVar21 == (X509_NAME *)0x0) goto LAB_0804a724;
          if ((*param_4 == 0) ||
             (ppcVar9 = TXT_DB_get_by_index((TXT_DB *)param_4[1],5,local_54),
             ppcVar9 == (OPENSSL_STRING *)0x0)) {
            ppcVar9 = TXT_DB_get_by_index((TXT_DB *)param_4[1],3,local_54);
            if (ppcVar9 == (OPENSSL_STRING *)0x0) {
              if (param_14 != 0) {
                BIO_printf(bio_err,
                           "Everything appears to be ok, creating and signing the certificate\n",0,0
                          );
              }
              pXVar5 = X509_new();
              iVar4 = -1;
              if (pXVar5 != (X509 *)0x0) {
                pXVar2 = pXVar5->cert_info;
                pAVar11 = BN_to_ASN1_INTEGER(param_5,pXVar2->serialNumber);
                if (pAVar11 != (ASN1_INTEGER *)0x0) {
                  if (param_22 == 0) {
                    pXVar14 = X509_get_subject_name(param_3_00);
                    iVar19 = X509_set_issuer_name(pXVar5,pXVar14);
                  }
                  else {
                    iVar19 = X509_set_issuer_name(pXVar5,local_d4);
                  }
                  iVar4 = -1;
                  if (iVar19 != 0) {
                    iVar4 = strcmp(param_10,"today");
                    if (iVar4 == 0) {
                      X509_gmtime_adj(pXVar5->cert_info->validity->notBefore,0);
                    }
                    else {
                      ASN1_TIME_set_string(pXVar5->cert_info->validity->notBefore,param_10);
                    }
                    if (param_11 == (char *)0x0) {
                      X509_time_adj_ex(pXVar5->cert_info->validity->notAfter,param_12,0,
                                       (time_t *)0x0);
                    }
                    else {
                      ASN1_TIME_set_string(pXVar5->cert_info->validity->notAfter,param_11);
                    }
                    iVar4 = -1;
                    iVar19 = X509_set_subject_name(pXVar5,local_d4);
                    if (iVar19 != 0) {
                      pkey = (FILE *)X509_REQ_get_pubkey(param_15);
                      iVar19 = X509_set_pubkey(pXVar5,(EVP_PKEY *)pkey);
                      EVP_PKEY_free((EVP_PKEY *)pkey);
                      if (iVar19 != 0) {
                        if (param_16 == (char *)0x0) goto LAB_0804acab;
                        if (pXVar2->version == (ASN1_INTEGER *)0x0) {
                          pAVar11 = ASN1_INTEGER_new();
                          pXVar2->version = pAVar11;
                          if (pAVar11 != (ASN1_INTEGER *)0x0) goto LAB_0804ab41;
LAB_0804af9b:
                          iVar4 = -1;
                        }
                        else {
LAB_0804ab41:
                          ASN1_INTEGER_set(pXVar2->version,2);
                          if ((_STACK *)pXVar2->extensions != (_STACK *)0x0) {
                            sk_pop_free((_STACK *)pXVar2->extensions,X509_EXTENSION_free);
                          }
                          pXVar2->extensions = (stack_st_X509_EXTENSION *)0x0;
                          if (param_22 == 0) {
                            X509V3_set_ctx(&local_70,param_3_00,pXVar5,param_15,(X509_CRL *)0x0,0);
                            uVar15 = extraout_ECX_03;
                          }
                          else {
                            X509V3_set_ctx(&local_70,pXVar5,pXVar5,param_15,(X509_CRL *)0x0,0);
                            uVar15 = extraout_ECX_02;
                          }
                          if (extconf == (CONF *)0x0) {
                            pkey = (FILE *)&local_70;
                            X509V3_set_nconf((X509V3_CTX *)pkey,param_17);
                            iVar19 = X509V3_EXT_add_nconf
                                               (param_17,(X509V3_CTX *)pkey,param_16,pXVar5);
                            if (iVar19 == 0) goto LAB_0804ac63;
                            if (param_14 != 0) {
                              iVar19 = BIO_printf(bio_err,
                                                  "Successfully added extensions from config\n",
                                                  iVar19,iVar19);
                            }
                          }
                          else {
                            if (param_14 != 0) {
                              BIO_printf(bio_err,"Extra configuration file found\n",uVar15,uVar15);
                            }
                            pkey = (FILE *)&local_70;
                            X509V3_set_nconf((X509V3_CTX *)pkey,extconf);
                            iVar19 = X509V3_EXT_add_nconf
                                               (extconf,(X509V3_CTX *)pkey,param_16,pXVar5);
                            if (iVar19 == 0) {
LAB_0804ac63:
                              BIO_printf(bio_err,"ERROR: adding extensions in section %s\n",param_16
                                         ,iVar19);
                              ERR_print_errors(bio_err);
                              goto LAB_0804af9b;
                            }
                            if (param_14 != 0) {
                              iVar19 = BIO_printf(bio_err,
                                                  "Successfully added extensions from file.\n",
                                                  iVar19,iVar19);
                            }
                          }
LAB_0804acab:
                          iVar4 = copy_extensions(pXVar5,param_15,param_21,iVar19);
                          if (iVar4 == 0) {
                            BIO_printf(bio_err,"ERROR: adding extensions from request\n",pXVar2,
                                       pXVar2);
                            iVar4 = -1;
                            ERR_print_errors(bio_err);
                          }
                          else {
                            uVar15 = extraout_ECX_04;
                            if (param_9 == 0) {
                              iVar4 = -1;
                              iVar19 = X509_set_subject_name(pXVar5,local_d8);
                              uVar15 = extraout_ECX_05;
                              if (iVar19 == 0) goto LAB_0804a8cc;
                            }
                            if (param_20 == 0) {
                              BIO_printf(bio_err,"Certificate Details:\n",uVar15,uVar15);
                              X509_print_ex(bio_err,pXVar5,param_19,param_18 | 0x208);
                            }
                            BIO_printf(bio_err,"Certificate is to be certified until ",0xffffffff,
                                       0xffffffff);
                            ASN1_TIME_print(bio_err,pXVar5->cert_info->validity->notAfter);
                            if (param_12 != 0) {
                              BIO_printf(bio_err," (%ld days)",param_12,pXVar2);
                            }
                            pEVar23 = (EVP_PKEY *)&DAT_081f11d3;
                            pFVar26 = pkey;
                            BIO_printf(bio_err,"\n",pkey,pkey);
                            if (param_13 == 0) {
                              pFVar26 = extraout_ECX_06;
                              BIO_printf(bio_err,"Sign the certificate? [y/n]:",extraout_ECX_06,
                                         extraout_ECX_06);
                              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
                              local_39[0] = 0;
                              pEVar23 = (EVP_PKEY *)0x18;
                              pkey = stdin;
                              pcVar21 = fgets((char *)local_39,0x18,stdin);
                              if (pcVar21 == (char *)0x0) {
                                iVar4 = 0;
                                BIO_printf(bio_err,"CERTIFICATE WILL NOT BE CERTIFIED: I/O error\n",
                                           extraout_EDX_02,extraout_EDX_02);
                              }
                              else {
                                uVar12 = (uint)pcVar21 & 0xffffff00 | local_39[0] & 0xffffffdf;
                                if ((char)(local_39[0] & 0xffffffdf) == 'Y') goto LAB_0804ae56;
                                iVar4 = 0;
                                BIO_printf(bio_err,"CERTIFICATE WILL NOT BE CERTIFIED\n",uVar12,
                                           uVar12);
                              }
                            }
                            else {
LAB_0804ae56:
                              pkey_00 = X509_get_pubkey(pXVar5);
                              iVar4 = EVP_PKEY_missing_parameters(pkey_00);
                              if ((iVar4 != 0) &&
                                 (pFVar13 = (FILE *)EVP_PKEY_missing_parameters(param_2_00),
                                 pFVar13 == (FILE *)0x0)) {
                                pEVar23 = param_2_00;
                                pFVar26 = pFVar13;
                                EVP_PKEY_copy_parameters(pkey_00,param_2_00);
                                pkey = pFVar13;
                              }
                              iVar4 = -1;
                              EVP_PKEY_free(pkey_00);
                              iVar19 = do_X509_sign(bio_err,pXVar5,param_2_00,param_1,param_2,
                                                    pEVar23,pkey,pFVar26);
                              if (iVar19 != 0) {
                                local_54[0] = (OPENSSL_STRING)CRYPTO_malloc(2,"ca.c",0x881);
                                pAVar3 = pXVar5->cert_info->validity->notAfter;
                                local_54[1] = (OPENSSL_STRING)
                                              CRYPTO_malloc(pAVar3->length + 1,"ca.c",0x884);
                                puVar10 = pAVar3->data;
                                puVar16 = (uchar *)local_54[1];
                                for (iVar19 = pAVar3->length; iVar19 != 0; iVar19 = iVar19 + -1) {
                                  *puVar16 = *puVar10;
                                  puVar10 = puVar10 + (uint)bVar20 * -2 + 1;
                                  puVar16 = puVar16 + (uint)bVar20 * -2 + 1;
                                }
                                ((uchar *)local_54[1])[pAVar3->length] = '\0';
                                local_54[2] = (char *)0x0;
                                local_44 = (char *)CRYPTO_malloc(8,"ca.c",0x88b);
                                pXVar14 = X509_get_subject_name(pXVar5);
                                local_40 = (_IO_marker *)X509_NAME_oneline(pXVar14,(char *)0x0,0);
                                if ((((local_54[0] == (OPENSSL_STRING)0x0) ||
                                     ((uchar *)local_54[1] == (uchar *)0x0)) ||
                                    (local_44 == (char *)0x0)) || (local_40 == (_IO_marker *)0x0)) {
                                  BIO_printf(bio_err,"Memory allocation failure\n",local_40,local_40
                                            );
                                  goto LAB_0804af9b;
                                }
                                BUF_strlcpy(local_44,"unknown",8);
                                *local_54[0] = 'V';
                                local_54[0][1] = '\0';
                                ppcVar9 = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"ca.c",0x898);
                                iVar19 = 0;
                                if (ppcVar9 == (OPENSSL_STRING *)0x0) {
                                  BIO_printf(bio_err,"Memory allocation failure\n",puVar16,puVar16);
                                }
                                else {
                                  do {
                                    ppcVar9[iVar19] = local_54[iVar19];
                                    local_54[iVar19] = (OPENSSL_STRING)0x0;
                                    iVar19 = iVar19 + 1;
                                  } while (iVar19 != 6);
                                  ppcVar9[6] = (OPENSSL_STRING)0x0;
                                  iVar4 = 1;
                                  iVar19 = TXT_DB_insert((TXT_DB *)param_4[1],ppcVar9);
                                  if (iVar19 == 0) {
                                    iVar4 = -1;
                                    BIO_printf(bio_err,"failed to update database\n",extraout_ECX_07
                                               ,extraout_ECX_07);
                                    BIO_printf(bio_err,"TXT_DB error number %ld\n",
                                               *(undefined4 *)(param_4[1] + 0x10));
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
              goto LAB_0804a8cc;
            }
            BIO_printf(bio_err,"ERROR:Serial number %s has already been issued,\n",local_48,
                       unaff_EDI);
            iVar4 = BIO_printf(bio_err,"      check the database/serial_file for corruption\n");
          }
          else {
            iVar4 = BIO_printf(bio_err,"ERROR:There is already a certificate for %s\n",local_40,
                               ppcVar9);
          }
          BIO_printf(bio_err,"The matching entry has the following details\n",iVar4,iVar4);
          cVar1 = **ppcVar9;
          pcVar21 = "Expired";
          if (((cVar1 != 'E') && (pcVar21 = "Revoked", cVar1 != 'R')) &&
             (pcVar21 = "Valid", cVar1 != 'V')) {
            pcVar21 = "\ninvalid type, Data base error\n";
          }
          BIO_printf(bio_err,"Type\t  :%s\n",pcVar21,unaff_ESI);
          pXVar14 = extraout_EDX_00;
          if (**ppcVar9 == 'R') {
            pcVar21 = ppcVar9[1];
            if (pcVar21 == (char *)0x0) {
              pcVar21 = "undef";
            }
            BIO_printf(bio_err,"Was revoked on:%s\n",pcVar21,extraout_ECX_01);
            pXVar14 = extraout_EDX_01;
          }
          pcVar21 = ppcVar9[1];
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "undef";
          }
          BIO_printf(bio_err,"Expires on    :%s\n",pcVar21,pXVar14);
          pcVar21 = ppcVar9[3];
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "undef";
          }
          BIO_printf(bio_err,"Serial Number :%s\n",pcVar21,pXVar14);
          pcVar21 = ppcVar9[4];
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "undef";
          }
          BIO_printf(bio_err,"File name     :%s\n",pcVar21,pXVar14);
          pcVar21 = ppcVar9[5];
          if ((X509_NAME *)pcVar21 == (X509_NAME *)0x0) {
            pcVar21 = "undef";
          }
          format = "Subject Name  :%s\n";
        }
        iVar4 = -1;
        pXVar5 = (X509 *)0x0;
        BIO_printf(bio_err,format,pcVar21,pXVar14);
      }
    }
  }
  else {
    pXVar5 = (X509 *)parse_name(param_6,param_7,param_8,extraout_EDX);
    if (pXVar5 != (X509 *)0x0) {
      X509_REQ_set_subject_name(param_15,(X509_NAME *)pXVar5);
      pXVar6 = param_15->req_info;
      *(uchar **)&pXVar6->enc = (uchar *)0x1;
      X509_NAME_free((X509_NAME *)pXVar5);
      goto LAB_0804a1e5;
    }
    iVar4 = -1;
    ERR_print_errors(bio_err);
    local_d8 = (X509_NAME *)0x0;
    local_d4 = (X509_NAME *)0x0;
    local_d0 = (X509_NAME *)0x0;
  }
LAB_0804a8cc:
  iVar19 = 0;
  do {
    if (local_54[iVar19] != (OPENSSL_STRING)0x0) {
      CRYPTO_free(local_54[iVar19]);
    }
    iVar19 = iVar19 + 1;
  } while (iVar19 != 6);
  if (local_d0 != (X509_NAME *)0x0) {
    X509_NAME_free(local_d0);
  }
  if (local_d4 != (X509_NAME *)0x0) {
    X509_NAME_free(local_d4);
  }
  if ((local_d8 != (X509_NAME *)0x0) && (param_9 == 0)) {
    X509_NAME_free(local_d8);
  }
  ASN1_UTCTIME_free((ASN1_UTCTIME *)a);
  if (iVar4 == 1) {
    *param_1_00 = pXVar5;
    iVar4 = 1;
  }
  else if (pXVar5 != (X509 *)0x0) {
    X509_free(pXVar5);
  }
LAB_0804a96c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

