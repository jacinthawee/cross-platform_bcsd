
void do_body(X509 **param_1,EVP_PKEY *param_2,X509 *param_3,undefined4 param_4,undefined4 param_5,
            _STACK *param_6,int *param_7,BIGNUM *param_8,int param_9,undefined4 param_10,
            undefined4 param_11,X509 *param_12,char *param_13,char *param_14,int param_15,
            ASN1_UTCTIME *param_16,int param_17,X509_REQ *param_18,char *param_19,CONF *param_20,
            uint param_21,ulong param_22,int param_23,undefined4 param_24,int param_25)

{
  char cVar1;
  ASN1_UTCTIME *a;
  int iVar2;
  X509_NAME_ENTRY *pXVar3;
  ASN1_STRING *pAVar4;
  ASN1_OBJECT *pAVar5;
  void *pvVar6;
  int iVar7;
  OPENSSL_STRING *ppcVar8;
  ASN1_INTEGER *pAVar9;
  EVP_PKEY *pEVar10;
  char *pcVar11;
  int iVar12;
  uchar *puVar13;
  X509_NAME *pXVar14;
  X509 *x;
  uchar *puVar15;
  X509 *pXVar16;
  X509_CINF *pXVar17;
  int iVar18;
  char *pcVar19;
  ASN1_TIME *pAVar20;
  ASN1_STRING *b;
  X509 *name;
  int local_c8;
  X509 *local_b8;
  OPENSSL_STRING local_7c;
  void *local_78;
  undefined4 local_74;
  X509 *local_70;
  char *local_6c;
  char *local_68;
  X509V3_CTX XStack_64;
  byte local_48 [28];
  int local_2c;
  
  local_2c = __TMC_END__;
  a = ASN1_UTCTIME_new();
  if (a == (ASN1_UTCTIME *)0x0) {
    BIO_printf(bio_err,"malloc error\n");
    param_16 = a;
    goto LAB_00012796;
  }
  local_7c = (OPENSSL_STRING)0x0;
  local_78 = (void *)0x0;
  local_74 = 0;
  local_70 = (X509 *)0x0;
  local_6c = (char *)0x0;
  local_68 = (char *)0x0;
  if (param_9 == 0) {
LAB_00012290:
    if (param_23 != 0) {
      BIO_printf(bio_err,"The Subject\'s Distinguished Name is as follows\n");
    }
    pXVar14 = param_18->req_info->subject;
    for (iVar18 = 0; iVar2 = X509_NAME_entry_count(pXVar14), iVar18 < iVar2; iVar18 = iVar18 + 1) {
      pXVar3 = X509_NAME_get_entry(pXVar14,iVar18);
      pAVar4 = X509_NAME_ENTRY_get_data(pXVar3);
      pAVar5 = X509_NAME_ENTRY_get_object(pXVar3);
      if (msie_hack != 0) {
        iVar2 = OBJ_obj2nid(pXVar3->object);
        if (pAVar4->type == 0x1c) {
          ASN1_UNIVERSALSTRING_to_string(pAVar4);
        }
        if (pAVar4->type == 0x16) {
          if (iVar2 != 0x30) {
            pAVar4->type = 0x14;
          }
        }
        else if ((iVar2 == 0x30) && (pAVar4->type == 0x13)) {
          pAVar4->type = 0x16;
        }
      }
      iVar2 = OBJ_obj2nid(pAVar5);
      if ((iVar2 != 0x30) || (param_12 != (X509 *)0x0)) {
        iVar2 = OBJ_obj2nid(pAVar5);
        iVar12 = pAVar4->type;
        if ((iVar2 == 0x30) && (iVar12 != 0x16)) {
          pcVar11 = "\nemailAddress type needs to be of type IA5STRING\n";
        }
        else {
          if ((iVar12 == 0xc) || (iVar12 == 0x1e)) {
LAB_000123a8:
            if (param_23 != 0) {
              old_entry_print(bio_err,pAVar5,pAVar4);
            }
            goto LAB_000123ba;
          }
          iVar2 = ASN1_PRINTABLE_type(pAVar4->data,pAVar4->length);
          if (iVar2 == 0x14) {
            if (pAVar4->type == 0x14) goto LAB_000123a8;
          }
          else if ((iVar2 != 0x16) || (pAVar4->type != 0x13)) goto LAB_000123a8;
          pcVar11 = "\nThe string contains characters that are illegal for the ASN.1 type\n";
        }
        x = (X509 *)0x0;
        pXVar16 = (X509 *)0x0;
        name = (X509 *)0x0;
        BIO_printf(bio_err,pcVar11);
        local_b8 = (X509 *)0x0;
        goto LAB_000123a2;
      }
LAB_000123ba:
    }
    local_b8 = (X509 *)X509_NAME_new();
    if (local_b8 == (X509 *)0x0) {
      param_16 = (ASN1_UTCTIME *)0xffffffff;
      BIO_printf(bio_err,"Memory allocation failure\n");
      x = local_b8;
      pXVar16 = local_b8;
      name = local_b8;
    }
    else {
      if (param_25 == 0) {
        name = (X509 *)X509_NAME_dup(param_3->cert_info->subject);
      }
      else {
        name = (X509 *)X509_NAME_dup(pXVar14);
      }
      if (name == (X509 *)0x0) {
        param_16 = (ASN1_UTCTIME *)0xffffffff;
        x = name;
        pXVar16 = name;
      }
      else {
        pAVar4 = (ASN1_STRING *)0x0;
        b = (ASN1_STRING *)0x0;
        for (local_c8 = 0; iVar18 = sk_num(param_6), local_c8 < iVar18; local_c8 = local_c8 + 1) {
          pvVar6 = sk_value(param_6,local_c8);
          x = (X509 *)OBJ_txt2nid(*(char **)((int)pvVar6 + 4));
          if (x == (X509 *)0x0) {
            param_16 = (ASN1_UTCTIME *)0xffffffff;
            BIO_printf(bio_err,"%s:unknown object type in \'policy\' configuration\n",
                       *(undefined4 *)((int)pvVar6 + 4));
            pXVar16 = x;
            goto LAB_00012742;
          }
          pAVar5 = OBJ_nid2obj((int)x);
          iVar18 = -1;
LAB_00012464:
          do {
            iVar2 = X509_NAME_get_index_by_OBJ(pXVar14,pAVar5,iVar18);
            if (iVar2 < 0) {
              if (iVar18 != -1) break;
              x = (X509 *)0x0;
            }
            else {
              x = (X509 *)X509_NAME_get_entry(pXVar14,iVar2);
            }
            pcVar11 = *(char **)((int)pvVar6 + 8);
            iVar12 = strcmp(pcVar11,"optional");
            iVar18 = iVar2;
            pXVar16 = x;
            if (iVar12 == 0) {
              if (x != (X509 *)0x0) goto LAB_000125b0;
            }
            else {
              iVar12 = strcmp(pcVar11,"supplied");
              if (iVar12 == 0) {
                if (x == (X509 *)0x0) {
                  BIO_printf(bio_err,"The %s field needed to be supplied and was missing\n",
                             *(undefined4 *)((int)pvVar6 + 4));
                  param_16 = (ASN1_UTCTIME *)0xffffffff;
                  goto LAB_00012742;
                }
              }
              else {
                iVar2 = strcmp(pcVar11,"match");
                if (iVar2 != 0) {
                  BIO_printf(bio_err,"%s:invalid type in \'policy\' configuration\n",pcVar11);
                  param_16 = (ASN1_UTCTIME *)0xffffffff;
                  x = (X509 *)0x0;
                  pXVar16 = (X509 *)0x0;
                  goto LAB_00012742;
                }
                if (x == (X509 *)0x0) {
                  BIO_printf(bio_err,"The mandatory %s field was missing\n",
                             *(undefined4 *)((int)pvVar6 + 4));
                  param_16 = (ASN1_UTCTIME *)0xffffffff;
                  goto LAB_00012742;
                }
                iVar12 = -1;
                do {
                  iVar2 = X509_NAME_get_index_by_OBJ((X509_NAME *)name,pAVar5,iVar12);
                  if ((iVar12 == -1) && (iVar2 < 0)) {
                    BIO_printf(bio_err,
                               "The %s field does not exist in the CA certificate,\nthe \'policy\' is misconfigured\n"
                               ,*(undefined4 *)((int)pvVar6 + 4));
                    param_16 = (ASN1_UTCTIME *)0xffffffff;
                    x = (X509 *)0x0;
                    pXVar16 = (X509 *)0x0;
                    goto LAB_00012742;
                  }
                  if (iVar2 < 0) {
                    if (b == (ASN1_STRING *)0x0) {
                      puVar13 = "NULL";
                    }
                    else {
                      puVar13 = b->data;
                    }
                    if (pAVar4 == (ASN1_STRING *)0x0) {
                      puVar15 = "NULL";
                    }
                    else {
                      puVar15 = pAVar4->data;
                    }
                    BIO_printf(bio_err,
                               "The %s field needed to be the same in the\nCA certificate (%s) and the request (%s)\n"
                               ,*(undefined4 *)((int)pvVar6 + 4),puVar13,puVar15);
                    param_16 = (ASN1_UTCTIME *)0xffffffff;
                    x = (X509 *)0x0;
                    pXVar16 = (X509 *)0x0;
                    goto LAB_00012742;
                  }
                  pXVar16 = (X509 *)X509_NAME_get_entry((X509_NAME *)name,iVar2);
                  pAVar4 = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY *)x);
                  b = X509_NAME_ENTRY_get_data((X509_NAME_ENTRY *)pXVar16);
                  iVar7 = ASN1_STRING_cmp(pAVar4,b);
                  iVar12 = iVar2;
                } while (iVar7 != 0);
                if (pXVar16 == (X509 *)0x0) goto LAB_00012464;
              }
LAB_000125b0:
              x = (X509 *)X509_NAME_add_entry((X509_NAME *)local_b8,(X509_NAME_ENTRY *)pXVar16,-1,0)
              ;
              if (x == (X509 *)0x0) {
                X509_NAME_ENTRY_free((X509_NAME_ENTRY *)pXVar16);
                BIO_printf(bio_err,"Memory allocation failure\n");
                param_16 = (ASN1_UTCTIME *)0xffffffff;
                pXVar16 = x;
                goto LAB_00012742;
              }
            }
          } while (-1 < iVar2);
        }
        if (preserve != 0) {
          X509_NAME_free((X509_NAME *)local_b8);
          local_b8 = (X509 *)X509_NAME_dup(pXVar14);
          if (local_b8 == (X509 *)0x0) {
            param_16 = (ASN1_UTCTIME *)0xffffffff;
            x = local_b8;
            pXVar16 = local_b8;
            goto LAB_00012742;
          }
        }
        if (param_17 != 0) {
          BIO_printf(bio_err,"The subject name appears to be ok, checking data base for clashes\n");
        }
        pXVar16 = local_b8;
        if (param_12 == (X509 *)0x0) {
          pXVar16 = (X509 *)X509_NAME_dup((X509_NAME *)local_b8);
          if (pXVar16 == (X509 *)0x0) {
            param_16 = (ASN1_UTCTIME *)0xffffffff;
            BIO_printf(bio_err,"Memory allocation failure\n");
            x = param_12;
            goto LAB_00012742;
          }
          while (iVar18 = X509_NAME_get_index_by_NID((X509_NAME *)pXVar16,0x30,-1), -1 < iVar18) {
            pXVar3 = X509_NAME_get_entry((X509_NAME *)pXVar16,iVar18);
            X509_NAME_delete_entry((X509_NAME *)pXVar16,iVar18);
            X509_NAME_ENTRY_free(pXVar3);
          }
        }
        if (param_8->top == 0) {
          local_70 = (X509 *)BUF_strdup("00");
        }
        else {
          local_70 = (X509 *)BN_bn2hex(param_8);
        }
        x = local_70;
        if (local_70 == (X509 *)0x0) {
          param_16 = (ASN1_UTCTIME *)0xffffffff;
          BIO_printf(bio_err,"Memory allocation failure\n");
        }
        else {
          if ((*param_7 == 0) ||
             (ppcVar8 = TXT_DB_get_by_index((TXT_DB *)param_7[1],5,&local_7c),
             ppcVar8 == (OPENSSL_STRING *)0x0)) {
            ppcVar8 = TXT_DB_get_by_index((TXT_DB *)param_7[1],3,&local_7c);
            if (ppcVar8 == (OPENSSL_STRING *)0x0) {
              if (param_17 != 0) {
                BIO_printf(bio_err,
                           "Everything appears to be ok, creating and signing the certificate\n");
              }
              x = X509_new();
              if (x != (X509 *)0x0) {
                pXVar17 = x->cert_info;
                pAVar9 = BN_to_ASN1_INTEGER(param_8,pXVar17->serialNumber);
                if (pAVar9 != (ASN1_INTEGER *)0x0) {
                  if (param_25 == 0) {
                    pXVar14 = X509_get_subject_name(param_3);
                    iVar18 = X509_set_issuer_name(x,pXVar14);
                  }
                  else {
                    iVar18 = X509_set_issuer_name(x,(X509_NAME *)local_b8);
                  }
                  if (iVar18 != 0) {
                    iVar18 = strcmp(param_13,"today");
                    if (iVar18 == 0) {
                      X509_gmtime_adj(x->cert_info->validity->notBefore,0);
                    }
                    else {
                      ASN1_TIME_set_string(x->cert_info->validity->notBefore,param_13);
                    }
                    if (param_14 == (char *)0x0) {
                      X509_time_adj_ex(x->cert_info->validity->notAfter,param_15,0,(time_t *)0x0);
                    }
                    else {
                      ASN1_TIME_set_string(x->cert_info->validity->notAfter,param_14);
                    }
                    iVar18 = X509_set_subject_name(x,(X509_NAME *)local_b8);
                    if (iVar18 != 0) {
                      pEVar10 = X509_REQ_get_pubkey(param_18);
                      iVar18 = X509_set_pubkey(x,pEVar10);
                      EVP_PKEY_free(pEVar10);
                      if (iVar18 != 0) {
                        if (param_19 != (char *)0x0) {
                          if (pXVar17->version == (ASN1_INTEGER *)0x0) {
                            pAVar9 = ASN1_INTEGER_new();
                            pXVar17->version = pAVar9;
                            if (pAVar9 == (ASN1_INTEGER *)0x0) goto LAB_000123a2;
                          }
                          ASN1_INTEGER_set(pXVar17->version,2);
                          if ((_STACK *)pXVar17->extensions != (_STACK *)0x0) {
                            sk_pop_free((_STACK *)pXVar17->extensions,X509_EXTENSION_free + 1);
                          }
                          pXVar17->extensions = (stack_st_X509_EXTENSION *)0x0;
                          if (param_25 == 0) {
                            X509V3_set_ctx(&XStack_64,param_3,x,param_18,(X509_CRL *)0x0,0);
                          }
                          else {
                            X509V3_set_ctx(&XStack_64,x,x,param_18,(X509_CRL *)0x0,0);
                          }
                          if (extconf == (CONF *)0x0) {
                            X509V3_set_nconf(&XStack_64,param_20);
                            iVar18 = X509V3_EXT_add_nconf(param_20,&XStack_64,param_19,x);
                            if (iVar18 == 0) goto LAB_00012a82;
                            if (param_17 != 0) {
                              BIO_printf(bio_err,"Successfully added extensions from config\n");
                            }
                          }
                          else {
                            if (param_17 != 0) {
                              BIO_printf(bio_err,"Extra configuration file found\n");
                            }
                            X509V3_set_nconf(&XStack_64,extconf);
                            iVar18 = X509V3_EXT_add_nconf(extconf,&XStack_64,param_19,x);
                            if (iVar18 == 0) {
LAB_00012a82:
                              BIO_printf(bio_err,"ERROR: adding extensions in section %s\n",param_19
                                        );
                              ERR_print_errors(bio_err);
                              goto LAB_000123a2;
                            }
                            if (param_17 != 0) {
                              BIO_printf(bio_err,"Successfully added extensions from file.\n");
                            }
                          }
                        }
                        iVar18 = copy_extensions(x,param_18,param_24);
                        if (iVar18 == 0) {
                          param_16 = (ASN1_UTCTIME *)0xffffffff;
                          BIO_printf(bio_err,"ERROR: adding extensions from request\n");
                          ERR_print_errors(bio_err);
                          goto LAB_00012742;
                        }
                        if ((param_12 != (X509 *)0x0) ||
                           (iVar18 = X509_set_subject_name(x,(X509_NAME *)pXVar16), iVar18 != 0)) {
                          if (param_23 == 0) {
                            BIO_printf(bio_err,"Certificate Details:\n");
                            X509_print_ex(bio_err,x,param_22,param_21 | 0x208);
                          }
                          BIO_printf(bio_err,"Certificate is to be certified until ");
                          ASN1_TIME_print(bio_err,x->cert_info->validity->notAfter);
                          if (param_15 != 0) {
                            BIO_printf(bio_err," (%ld days)",param_15);
                          }
                          BIO_printf(bio_err,"\n");
                          if (param_16 == (ASN1_UTCTIME *)0x0) {
                            BIO_printf(bio_err,"Sign the certificate? [y/n]:");
                            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
                            local_48[0] = 0;
                            pcVar11 = fgets((char *)local_48,0x18,stdin);
                            if (pcVar11 == (char *)0x0) {
                              BIO_printf(bio_err,"CERTIFICATE WILL NOT BE CERTIFIED: I/O error\n");
                            }
                            else {
                              if ((local_48[0] & 0xdf) == 0x59) goto LAB_00012be0;
                              BIO_printf(bio_err,"CERTIFICATE WILL NOT BE CERTIFIED\n");
                            }
                          }
                          else {
LAB_00012be0:
                            pEVar10 = X509_get_pubkey(x);
                            iVar18 = EVP_PKEY_missing_parameters(pEVar10);
                            if ((iVar18 != 0) &&
                               (iVar18 = EVP_PKEY_missing_parameters(param_2), iVar18 == 0)) {
                              EVP_PKEY_copy_parameters(pEVar10,param_2);
                            }
                            EVP_PKEY_free(pEVar10);
                            iVar18 = do_X509_sign(bio_err,x,param_2,param_4,param_5);
                            if (iVar18 == 0) goto LAB_000123a2;
                            local_7c = (OPENSSL_STRING)CRYPTO_malloc(2,"ca.c",0x881);
                            iVar18 = 0;
                            pAVar20 = x->cert_info->validity->notAfter;
                            local_78 = CRYPTO_malloc(pAVar20->length + 1,"ca.c",0x884);
                            memcpy(local_78,pAVar20->data,pAVar20->length);
                            *(undefined *)((int)local_78 + pAVar20->length) = 0;
                            local_74 = 0;
                            local_6c = (char *)CRYPTO_malloc(8,"ca.c",0x88b);
                            pXVar14 = X509_get_subject_name(x);
                            local_68 = X509_NAME_oneline(pXVar14,(char *)0x0,0);
                            if ((((local_7c == (OPENSSL_STRING)0x0) || (local_78 == (void *)0x0)) ||
                                (local_6c == (char *)0x0)) || (local_68 == (char *)0x0)) {
                              param_16 = (ASN1_UTCTIME *)0xffffffff;
                              BIO_printf(bio_err,"Memory allocation failure\n");
                            }
                            else {
                              BUF_strlcpy(local_6c,"unknown",8);
                              *local_7c = 'V';
                              local_7c[1] = '\0';
                              ppcVar8 = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"ca.c",0x898);
                              if (ppcVar8 == (OPENSSL_STRING *)0x0) {
                                param_16 = (ASN1_UTCTIME *)0xffffffff;
                                BIO_printf(bio_err,"Memory allocation failure\n");
                              }
                              else {
                                do {
                                  *(undefined4 *)((int)ppcVar8 + iVar18) =
                                       *(undefined4 *)((int)&local_7c + iVar18);
                                  *(undefined4 *)((int)&local_7c + iVar18) = 0;
                                  iVar18 = iVar18 + 4;
                                } while (iVar18 != 0x18);
                                ppcVar8[6] = (OPENSSL_STRING)0x0;
                                iVar18 = TXT_DB_insert((TXT_DB *)param_7[1],ppcVar8);
                                if (iVar18 == 0) {
                                  param_16 = (ASN1_UTCTIME *)0xffffffff;
                                  BIO_printf(bio_err,"failed to update database\n");
                                  BIO_printf(bio_err,"TXT_DB error number %ld\n",
                                             *(undefined4 *)(param_7[1] + 0x10));
                                }
                                else {
                                  param_16 = (ASN1_UTCTIME *)0x1;
                                }
                              }
                            }
                          }
                          goto LAB_00012742;
                        }
                      }
                    }
                  }
                }
              }
LAB_000123a2:
              param_16 = (ASN1_UTCTIME *)0xffffffff;
              goto LAB_00012742;
            }
            BIO_printf(bio_err,"ERROR:Serial number %s has already been issued,\n",local_70);
            BIO_printf(bio_err,"      check the database/serial_file for corruption\n");
          }
          else {
            BIO_printf(bio_err,"ERROR:There is already a certificate for %s\n",local_68);
          }
          BIO_printf(bio_err,"The matching entry has the following details\n");
          cVar1 = **ppcVar8;
          if (cVar1 == 'E') {
            pcVar11 = "Expired";
          }
          else if (cVar1 == 'R') {
            pcVar11 = "Revoked";
          }
          else {
            pcVar11 = "Valid";
            if (cVar1 != 'V') {
              pcVar11 = "\ninvalid type, Data base error\n";
            }
          }
          BIO_printf(bio_err,"Type\t  :%s\n",pcVar11);
          if (**ppcVar8 == 'R') {
            pcVar11 = ppcVar8[1];
            if (ppcVar8[1] == (char *)0x0) {
              pcVar11 = "undef";
            }
            BIO_printf(bio_err,"Was revoked on:%s\n",pcVar11);
          }
          pcVar19 = "undef";
          pcVar11 = ppcVar8[1];
          if (ppcVar8[1] == (char *)0x0) {
            pcVar11 = pcVar19;
          }
          param_16 = (ASN1_UTCTIME *)0xffffffff;
          BIO_printf(bio_err,"Expires on    :%s\n",pcVar11);
          pcVar11 = ppcVar8[3];
          if (ppcVar8[3] == (char *)0x0) {
            pcVar11 = pcVar19;
          }
          BIO_printf(bio_err,"Serial Number :%s\n",pcVar11);
          pcVar11 = ppcVar8[4];
          if (ppcVar8[4] == (char *)0x0) {
            pcVar11 = pcVar19;
          }
          BIO_printf(bio_err,"File name     :%s\n",pcVar11);
          pcVar11 = ppcVar8[5];
          if (ppcVar8[5] == (char *)0x0) {
            pcVar11 = pcVar19;
          }
          BIO_printf(bio_err,"Subject Name  :%s\n",pcVar11);
          x = (X509 *)0x0;
        }
      }
    }
  }
  else {
    local_b8 = (X509 *)parse_name(param_9,param_10,param_11);
    if (local_b8 != (X509 *)0x0) {
      X509_REQ_set_subject_name(param_18,(X509_NAME *)local_b8);
      (param_18->req_info->enc).modified = 1;
      X509_NAME_free((X509_NAME *)local_b8);
      goto LAB_00012290;
    }
    ERR_print_errors(bio_err);
    param_16 = (ASN1_UTCTIME *)0xffffffff;
    x = local_b8;
    pXVar16 = local_b8;
    name = local_b8;
  }
LAB_00012742:
  iVar18 = 0;
  do {
    if (*(void **)((int)&local_7c + iVar18) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)&local_7c + iVar18));
    }
    iVar18 = iVar18 + 4;
  } while (iVar18 != 0x18);
  if (name != (X509 *)0x0) {
    X509_NAME_free((X509_NAME *)name);
  }
  if (local_b8 != (X509 *)0x0) {
    X509_NAME_free((X509_NAME *)local_b8);
  }
  if ((pXVar16 != (X509 *)0x0) && (param_12 == (X509 *)0x0)) {
    X509_NAME_free((X509_NAME *)pXVar16);
  }
  ASN1_UTCTIME_free(a);
  if (param_16 == (ASN1_UTCTIME *)0x1) {
    *param_1 = x;
  }
  else if (x != (X509 *)0x0) {
    X509_free(x);
  }
LAB_00012796:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_16);
  }
  return;
}

