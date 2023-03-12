
SSL_SESSION * d2i_SSL_SESSION(SSL_SESSION **a,uchar **pp,long length)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  SSL_SESSION *ses;
  ASN1_INTEGER *pAVar4;
  long lVar5;
  ASN1_OCTET_STRING *pAVar6;
  size_t __n;
  time_t tVar7;
  X509 *pXVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int in_GS_OFFSET;
  ASN1_INTEGER *local_80;
  ASN1_OCTET_STRING *local_7c;
  int local_78;
  int local_74;
  byte *local_70;
  ASN1_INTEGER local_6c;
  ASN1_OCTET_STRING local_5c;
  ASN1_const_CTX local_4c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c.error = 0x3a;
  pbVar2 = *pp;
  local_4c.pp = pp;
  local_4c.q = pbVar2;
  if ((a == (SSL_SESSION **)0x0) || (ses = *a, ses == (SSL_SESSION *)0x0)) {
    ses = SSL_SESSION_new();
    if (ses == (SSL_SESSION *)0x0) {
      local_4c.line = 0x182;
      ERR_put_error(0xd,0x67,local_4c.error,"ssl_asn1.c",0x182);
      asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
      ses = (SSL_SESSION *)0x0;
      goto LAB_080cdb84;
    }
    pbVar2 = *pp;
  }
  local_80 = &local_6c;
  local_7c = &local_5c;
  local_4c.max = pbVar2 + length;
  if (length == 0) {
    local_4c.max = (byte *)0x0;
  }
  local_4c.p = pbVar2;
  iVar3 = asn1_GetSequence(&local_4c,&length);
  if (iVar3 == 0) {
    local_4c.line = 0x188;
  }
  else {
    local_6c.data = (uchar *)0x0;
    local_6c.length = 0;
    local_4c.q = local_4c.p;
    pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,local_4c.slen);
    if (pAVar4 == (ASN1_INTEGER *)0x0) {
      local_4c.line = 0x18b;
    }
    else {
      local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
      if (local_6c.data != (uchar *)0x0) {
        CRYPTO_free(local_6c.data);
        local_6c.data = (uchar *)0x0;
        local_6c.length = 0;
      }
      local_4c.q = local_4c.p;
      pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,local_4c.slen);
      if (pAVar4 == (ASN1_INTEGER *)0x0) {
        local_4c.line = 399;
      }
      else {
        local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
        lVar5 = ASN1_INTEGER_get(local_80);
        ses->ssl_version = lVar5;
        if (local_6c.data != (uchar *)0x0) {
          CRYPTO_free(local_6c.data);
          local_6c.data = (uchar *)0x0;
          local_6c.length = 0;
        }
        local_5c.data = (uchar *)0x0;
        local_5c.length = 0;
        local_4c.q = local_4c.p;
        pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
        if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
          local_4c.line = 0x195;
        }
        else {
          local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
          if (lVar5 == 2) {
            if (local_5c.length != 3) goto LAB_080cdd04;
            uVar11 = (uint)*(byte *)((int)local_5c.data + 1) << 8 |
                     (uint)*local_5c.data << 0x10 | *(byte *)((int)local_5c.data + 2) | 0x2000000;
LAB_080cdde4:
            local_4c.q = local_4c.p;
            *(undefined4 *)(ses->krb5_client_princ + 0x24) = 0;
            *(uint *)(ses->krb5_client_princ + 0x28) = uVar11;
            pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
            if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
              local_4c.line = 0x1b6;
            }
            else {
              local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
              if (0x20 < local_5c.length) {
                local_5c.length = 0x20;
              }
              ses->session_id_length = local_5c.length;
              if ((uint)local_5c.length < 4) {
                if ((local_5c.length != 0) &&
                   (ses->session_id[0] = *local_5c.data, (local_5c.length & 2U) != 0)) {
                  *(undefined2 *)(ses->session_id + (local_5c.length - 2)) =
                       *(undefined2 *)((int)local_5c.data + (local_5c.length - 2U));
                }
              }
              else {
                *(undefined4 *)ses->session_id = *(undefined4 *)local_5c.data;
                *(undefined4 *)(ses->session_id + (local_5c.length - 4)) =
                     *(undefined4 *)((int)local_5c.data + (local_5c.length - 4U));
                uVar11 = (uint)(ses->session_id + 4) & 0xfffffffc;
                iVar3 = (int)ses->session_id - uVar11;
                uVar12 = iVar3 + local_5c.length & 0xfffffffc;
                if (3 < uVar12) {
                  uVar9 = 0;
                  do {
                    *(undefined4 *)(uVar11 + uVar9) =
                         *(undefined4 *)((int)local_5c.data + (uVar9 - iVar3));
                    uVar9 = uVar9 + 4;
                  } while (uVar9 < uVar12);
                }
              }
              local_4c.q = local_4c.p;
              pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
              if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
                local_4c.line = 0x1c5;
              }
              else {
                local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                uVar11 = 0x30;
                if (local_5c.length < 0x31) {
                  uVar11 = local_5c.length;
                }
                ses->master_key_length = uVar11;
                if (uVar11 < 4) {
                  if ((uVar11 != 0) && (ses->master_key[0] = *local_5c.data, (uVar11 & 2) != 0)) {
                    *(undefined2 *)(ses->master_key + (uVar11 - 2)) =
                         *(undefined2 *)((int)local_5c.data + (uVar11 - 2));
                  }
                }
                else {
                  *(undefined4 *)ses->master_key = *(undefined4 *)local_5c.data;
                  *(undefined4 *)(ses->master_key + (uVar11 - 4)) =
                       *(undefined4 *)((int)local_5c.data + (uVar11 - 4));
                  uVar12 = (uint)(ses->master_key + 4) & 0xfffffffc;
                  iVar3 = (int)ses->master_key - uVar12;
                  uVar11 = iVar3 + uVar11 & 0xfffffffc;
                  if (3 < uVar11) {
                    uVar9 = 0;
                    do {
                      *(undefined4 *)(uVar12 + uVar9) =
                           *(undefined4 *)((int)local_5c.data + (uVar9 - iVar3));
                      uVar9 = uVar9 + 4;
                    } while (uVar9 < uVar11);
                  }
                }
                local_5c.length = 0;
                if ((byte *)local_4c.slen == (byte *)0x0) {
                  __n = 0;
                }
                else {
                  bVar1 = *local_4c.p;
                  __n = 0;
                  if ((bVar1 & 0xdf) == 0x80) {
                    *local_4c.p = bVar1 & 0x20 | 4;
                    local_4c.q = local_4c.p;
                    pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
                    if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
                      local_4c.line = 0x1e0;
                      *local_4c.q = bVar1;
                      goto LAB_080cdb3f;
                    }
                    local_4c.slen = (long)(local_4c.q + (local_4c.slen - (int)local_4c.p));
                    *local_4c.q = bVar1;
                    __n = local_5c.length;
                    if (8 < local_5c.length) {
                      __n = 8;
                    }
                  }
                }
                ses->key_arg_length = __n;
                memcpy(ses->key_arg,local_5c.data,__n);
                if ((undefined4 *)local_5c.data != (undefined4 *)0x0) {
                  CRYPTO_free(local_5c.data);
                }
                local_6c.length = 0;
                if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa1)) {
LAB_080cdf7b:
                  if (local_6c.data == (uchar *)0x0) {
                    tVar7 = time((time_t *)0x0);
                    *(time_t *)(ses->krb5_client_princ + 0x1c) = tVar7;
                  }
                  else {
                    lVar5 = ASN1_INTEGER_get(local_80);
                    *(long *)(ses->krb5_client_princ + 0x1c) = lVar5;
                    CRYPTO_free(local_6c.data);
                    local_6c.data = (uchar *)0x0;
                  }
                  local_6c.length = 0;
                  if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa2)) {
LAB_080cdfcb:
                    if (local_6c.data == (uchar *)0x0) {
                      *(undefined4 *)(ses->krb5_client_princ + 0x18) = 3;
                    }
                    else {
                      lVar5 = ASN1_INTEGER_get(local_80);
                      *(long *)(ses->krb5_client_princ + 0x18) = lVar5;
                      CRYPTO_free(local_6c.data);
                      local_6c.data = (uchar *)0x0;
                      local_6c.length = 0;
                    }
                    if (*(X509 **)(ses->krb5_client_princ + 0xc) != (X509 *)0x0) {
                      X509_free(*(X509 **)(ses->krb5_client_princ + 0xc));
                      *(undefined4 *)(ses->krb5_client_princ + 0xc) = 0;
                    }
                    if ((byte *)local_4c.slen == (byte *)0x0) {
                      local_5c.length = 0;
                      local_5c.data = (uchar *)0x0;
LAB_080ce058:
                      ses->sid_ctx_length = 0;
LAB_080ce05f:
                      local_6c.length = 0;
                      if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa5)) {
LAB_080ce078:
                        if (local_6c.data == (uchar *)0x0) {
                          *(undefined4 *)(ses->krb5_client_princ + 0x10) = 0;
                        }
                        else {
                          lVar5 = ASN1_INTEGER_get(local_80);
                          *(long *)(ses->krb5_client_princ + 0x10) = lVar5;
                          CRYPTO_free(local_6c.data);
                          local_6c.data = (uchar *)0x0;
                          local_6c.length = 0;
                        }
                        local_5c.length = 0;
                        local_5c.data = (uchar *)0x0;
                        if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa6)) {
LAB_080ce0cf:
                          *(undefined4 *)(ses->krb5_client_princ + 0x40) = 0;
LAB_080ce0d9:
                          local_5c.length = 0;
                          local_5c.data = (uchar *)0x0;
                          if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa7)) {
LAB_080ce0f1:
                            ses->krb5_client_princ_len = 0;
LAB_080ce0fb:
                            local_5c.length = 0;
                            local_5c.data = (uchar *)0x0;
                            if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa8)) {
LAB_080ce113:
                              *(undefined4 *)ses->krb5_client_princ = 0;
LAB_080ce11d:
                              local_6c.length = 0;
                              if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa9)) {
LAB_080ce136:
                                if (local_6c.data == (uchar *)0x0) {
                                  if ((*(int *)(ses->krb5_client_princ + 0x58) == 0) ||
                                     (ses->session_id_length == 0)) {
                                    *(undefined4 *)(ses->krb5_client_princ + 0x5c) = 0;
                                  }
                                  else {
                                    *(undefined4 *)(ses->krb5_client_princ + 0x5c) = 0xffffffff;
                                  }
                                }
                                else {
                                  lVar5 = ASN1_INTEGER_get(local_80);
                                  *(long *)(ses->krb5_client_princ + 0x5c) = lVar5;
                                  CRYPTO_free(local_6c.data);
                                  local_6c.data = (uchar *)0x0;
                                  local_6c.length = 0;
                                }
                                local_5c.length = 0;
                                local_5c.data = (uchar *)0x0;
                                if ((byte *)local_4c.slen == (byte *)0x0) {
                                  *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
                                  local_5c.length = 0;
                                  local_5c.data = (uchar *)0x0;
LAB_080ce1d6:
                                  *(undefined4 *)(ses->krb5_client_princ + 0x60) = 0;
LAB_080ce1e0:
                                  iVar3 = asn1_const_Finish(&local_4c);
                                  if (iVar3 != 0) {
                                    *pp = local_4c.p;
                                    if (a != (SSL_SESSION **)0x0) {
                                      *a = ses;
                                    }
                                    goto LAB_080cdb84;
                                  }
                                  local_4c.line = 0x281;
                                }
                                else if (*local_4c.p == 0xaa) {
                                  local_4c.q = local_4c.p;
                                  uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                           &local_74,local_4c.slen);
                                  if ((uVar11 & 0x80) == 0) {
                                    if (uVar11 == 0x21) {
                                      local_70 = (byte *)(local_4c.slen +
                                                         (-2 - ((int)local_4c.p - (int)local_4c.q)))
                                      ;
                                      pAVar6 = d2i_ASN1_OCTET_STRING
                                                         (&local_7c,&local_4c.p,(long)local_70);
                                      if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                        local_70 = (byte *)(local_4c.slen +
                                                           -((int)local_4c.p - (int)local_4c.q));
                                        iVar3 = ASN1_const_check_infinite_end
                                                          (&local_4c.p,(long)local_70);
                                        if (iVar3 != 0) goto LAB_080ceb30;
                                        local_4c.error = 0x3f;
                                      }
                                    }
                                    else {
                                      pAVar6 = d2i_ASN1_OCTET_STRING
                                                         (&local_7c,&local_4c.p,(long)local_70);
                                      if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080ceb30:
                                        local_4c.slen =
                                             local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                        if ((undefined4 *)local_5c.data != (undefined4 *)0x0) {
                                          *(int *)(ses->krb5_client_princ + 0x58) = local_5c.length;
                                        }
                                        *(uchar **)(ses->krb5_client_princ + 0x54) = local_5c.data;
                                        if ((byte *)local_4c.slen == (byte *)0x0) {
                                          local_5c.length = 0;
                                          local_5c.data = (uchar *)0x0;
                                          goto LAB_080ce1d6;
                                        }
                                        goto LAB_080ce1b4;
                                      }
                                    }
                                  }
                                  else {
                                    local_4c.error = 0x3b;
                                  }
                                  local_4c.line = 0x25b;
                                }
                                else {
                                  *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
LAB_080ce1b4:
                                  local_5c.data = (uchar *)0x0;
                                  local_5c.length = 0;
                                  if (*local_4c.p == 0xab) {
                                    local_4c.q = local_4c.p;
                                    uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78
                                                             ,&local_74,local_4c.slen);
                                    if ((uVar11 & 0x80) == 0) {
                                      if (uVar11 == 0x21) {
                                        local_70 = (byte *)(local_4c.slen +
                                                           (-2 - ((int)local_4c.p - (int)local_4c.q)
                                                           ));
                                        pAVar6 = d2i_ASN1_OCTET_STRING
                                                           (&local_7c,&local_4c.p,(long)local_70);
                                        if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                          local_70 = (byte *)(local_4c.slen +
                                                             -((int)local_4c.p - (int)local_4c.q));
                                          iVar3 = ASN1_const_check_infinite_end
                                                            (&local_4c.p,(long)local_70);
                                          if (iVar3 != 0) goto LAB_080cee5f;
                                          local_4c.error = 0x3f;
                                        }
                                      }
                                      else {
                                        pAVar6 = d2i_ASN1_OCTET_STRING
                                                           (&local_7c,&local_4c.p,(long)local_70);
                                        if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cee5f:
                                          local_4c.slen =
                                               local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                          if ((undefined4 *)local_5c.data != (undefined4 *)0x0) {
                                            *(uint *)(ses->krb5_client_princ + 0x20) =
                                                 (uint)*local_5c.data;
                                            CRYPTO_free(local_5c.data);
                                          }
                                          local_5c.length = 0;
                                          local_5c.data = (uchar *)0x0;
                                          if ((byte *)local_4c.slen == (byte *)0x0)
                                          goto LAB_080ce1d6;
                                          goto LAB_080ce1cd;
                                        }
                                      }
                                    }
                                    else {
                                      local_4c.error = 0x3b;
                                    }
                                    local_4c.line = 0x269;
                                  }
                                  else {
LAB_080ce1cd:
                                    local_5c.data = (uchar *)0x0;
                                    local_5c.length = 0;
                                    if (*local_4c.p != 0xac) goto LAB_080ce1d6;
                                    local_4c.q = local_4c.p;
                                    uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78
                                                             ,&local_74,local_4c.slen);
                                    if ((uVar11 & 0x80) == 0) {
                                      if (uVar11 == 0x21) {
                                        local_70 = (byte *)(local_4c.slen +
                                                           (-2 - ((int)local_4c.p - (int)local_4c.q)
                                                           ));
                                        pAVar6 = d2i_ASN1_OCTET_STRING
                                                           (&local_7c,&local_4c.p,(long)local_70);
                                        if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                          local_70 = (byte *)(local_4c.slen +
                                                             -((int)local_4c.p - (int)local_4c.q));
                                          iVar3 = ASN1_const_check_infinite_end
                                                            (&local_4c.p,(long)local_70);
                                          if (iVar3 != 0) goto LAB_080cedeb;
                                          local_4c.error = 0x3f;
                                        }
                                      }
                                      else {
                                        pAVar6 = d2i_ASN1_OCTET_STRING
                                                           (&local_7c,&local_4c.p,(long)local_70);
                                        if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cedeb:
                                          local_4c.slen =
                                               local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                          if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                          goto LAB_080ce1d6;
                                          pcVar10 = BUF_strndup((char *)local_5c.data,
                                                                local_5c.length);
                                          *(char **)(ses->krb5_client_princ + 0x60) = pcVar10;
                                          CRYPTO_free(local_5c.data);
                                          local_5c.data = (uchar *)0x0;
                                          local_5c.length = 0;
                                          goto LAB_080ce1e0;
                                        }
                                      }
                                    }
                                    else {
                                      local_4c.error = 0x3b;
                                    }
                                    local_4c.line = 0x275;
                                  }
                                }
                              }
                              else {
                                local_4c.q = local_4c.p;
                                uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                         &local_74,local_4c.slen);
                                if ((uVar11 & 0x80) == 0) {
                                  if (uVar11 == 0x21) {
                                    local_70 = (byte *)(local_4c.slen +
                                                       (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                    pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                                    if (pAVar4 != (ASN1_INTEGER *)0x0) {
                                      local_70 = (byte *)(local_4c.slen +
                                                         -((int)local_4c.p - (int)local_4c.q));
                                      iVar3 = ASN1_const_check_infinite_end
                                                        (&local_4c.p,(long)local_70);
                                      if (iVar3 != 0) goto LAB_080ceaf8;
                                      local_4c.error = 0x3f;
                                    }
                                  }
                                  else {
                                    pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                                    if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080ceaf8:
                                      local_4c.slen =
                                           local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                      goto LAB_080ce136;
                                    }
                                  }
                                }
                                else {
                                  local_4c.error = 0x3b;
                                }
                                local_4c.line = 0x24f;
                              }
                            }
                            else {
                              local_4c.q = local_4c.p;
                              uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                       &local_74,local_4c.slen);
                              if ((uVar11 & 0x80) == 0) {
                                if (uVar11 == 0x21) {
                                  local_70 = (byte *)(local_4c.slen +
                                                     (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                  pAVar6 = d2i_ASN1_OCTET_STRING
                                                     (&local_7c,&local_4c.p,(long)local_70);
                                  if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                    local_70 = (byte *)(local_4c.slen +
                                                       -((int)local_4c.p - (int)local_4c.q));
                                    iVar3 = ASN1_const_check_infinite_end
                                                      (&local_4c.p,(long)local_70);
                                    if (iVar3 != 0) goto LAB_080cecf5;
                                    local_4c.error = 0x3f;
                                  }
                                }
                                else {
                                  pAVar6 = d2i_ASN1_OCTET_STRING
                                                     (&local_7c,&local_4c.p,(long)local_70);
                                  if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cecf5:
                                    local_4c.slen =
                                         local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                    if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                    goto LAB_080ce113;
                                    pcVar10 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                    *(char **)ses->krb5_client_princ = pcVar10;
                                    CRYPTO_free(local_5c.data);
                                    local_5c.data = (uchar *)0x0;
                                    local_5c.length = 0;
                                    goto LAB_080ce11d;
                                  }
                                }
                              }
                              else {
                                local_4c.error = 0x3b;
                              }
                              local_4c.line = 0x241;
                            }
                          }
                          else {
                            local_4c.q = local_4c.p;
                            uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                     &local_74,local_4c.slen);
                            if ((uVar11 & 0x80) == 0) {
                              if (uVar11 == 0x21) {
                                local_70 = (byte *)(local_4c.slen +
                                                   (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70)
                                ;
                                if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                  local_70 = (byte *)(local_4c.slen +
                                                     -((int)local_4c.p - (int)local_4c.q));
                                  iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                                  if (iVar3 != 0) goto LAB_080ced78;
                                  local_4c.error = 0x3f;
                                }
                              }
                              else {
                                pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70)
                                ;
                                if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080ced78:
                                  local_4c.slen =
                                       local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                  if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                  goto LAB_080ce0f1;
                                  pcVar10 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                  ses->krb5_client_princ_len = (uint)pcVar10;
                                  CRYPTO_free(local_5c.data);
                                  goto LAB_080ce0fb;
                                }
                              }
                            }
                            else {
                              local_4c.error = 0x3b;
                            }
                            local_4c.line = 0x234;
                          }
                        }
                        else {
                          local_4c.q = local_4c.p;
                          uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74
                                                   ,local_4c.slen);
                          if ((uVar11 & 0x80) == 0) {
                            if (uVar11 == 0x21) {
                              local_70 = (byte *)(local_4c.slen +
                                                 (-2 - ((int)local_4c.p - (int)local_4c.q)));
                              pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                              if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                local_70 = (byte *)(local_4c.slen +
                                                   -((int)local_4c.p - (int)local_4c.q));
                                iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                                if (iVar3 != 0) goto LAB_080cebba;
                                local_4c.error = 0x3f;
                              }
                            }
                            else {
                              pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                              if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cebba:
                                local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q)
                                ;
                                if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                goto LAB_080ce0cf;
                                pcVar10 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                *(char **)(ses->krb5_client_princ + 0x40) = pcVar10;
                                CRYPTO_free(local_5c.data);
                                goto LAB_080ce0d9;
                              }
                            }
                          }
                          else {
                            local_4c.error = 0x3b;
                          }
                          local_4c.line = 0x225;
                        }
                      }
                      else {
                        local_4c.q = local_4c.p;
                        uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                                 local_4c.slen);
                        if ((uVar11 & 0x80) == 0) {
                          if (uVar11 == 0x21) {
                            local_70 = (byte *)(local_4c.slen +
                                               (-2 - ((int)local_4c.p - (int)local_4c.q)));
                            pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                            if (pAVar4 != (ASN1_INTEGER *)0x0) {
                              local_70 = (byte *)(local_4c.slen +
                                                 -((int)local_4c.p - (int)local_4c.q));
                              iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                              if (iVar3 != 0) goto LAB_080ceac0;
                              local_4c.error = 0x3f;
                            }
                          }
                          else {
                            pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                            if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080ceac0:
                              local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                              goto LAB_080ce078;
                            }
                          }
                        }
                        else {
                          local_4c.error = 0x3b;
                        }
                        local_4c.line = 0x219;
                      }
                    }
                    else if (*local_4c.p == 0xa3) {
                      local_4c.q = local_4c.p;
                      uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                               local_4c.slen);
                      if ((uVar11 & 0x80) == 0) {
                        if (uVar11 == 0x21) {
                          local_70 = (byte *)(local_4c.slen +
                                             (-2 - ((int)local_4c.p - (int)local_4c.q)));
                          pXVar8 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_4c.p,
                                            (long)local_70);
                          if (pXVar8 != (X509 *)0x0) {
                            local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q)
                                               );
                            iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                            if (iVar3 != 0) goto LAB_080ce79a;
                            local_4c.error = 0x3f;
                          }
                        }
                        else {
                          pXVar8 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_4c.p,
                                            (long)local_70);
                          if (pXVar8 != (X509 *)0x0) {
LAB_080ce79a:
                            local_5c.length = 0;
                            local_5c.data = (uchar *)0x0;
                            local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                            if ((byte *)local_4c.slen == (byte *)0x0) goto LAB_080ce058;
                            goto LAB_080ce04f;
                          }
                        }
                      }
                      else {
                        local_4c.error = 0x3b;
                      }
                      local_4c.line = 0x201;
                    }
                    else {
LAB_080ce04f:
                      local_5c.data = (uchar *)0x0;
                      local_5c.length = 0;
                      if (*local_4c.p != 0xa4) goto LAB_080ce058;
                      local_4c.q = local_4c.p;
                      uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                               local_4c.slen);
                      if ((uVar11 & 0x80) == 0) {
                        if (uVar11 == 0x21) {
                          local_70 = (byte *)(local_4c.slen +
                                             (-2 - ((int)local_4c.p - (int)local_4c.q)));
                          pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                            local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q)
                                               );
                            iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                            if (iVar3 != 0) goto LAB_080ce7f4;
                            local_4c.error = 0x3f;
                          }
                        }
                        else {
                          pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080ce7f4:
                            local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                            if ((undefined4 *)local_5c.data == (undefined4 *)0x0) goto LAB_080ce058;
                            if (0x20 < local_5c.length) {
                              local_4c.error = 0x10f;
                              goto LAB_080cdb3f;
                            }
                            ses->sid_ctx_length = local_5c.length;
                            if ((uint)local_5c.length < 4) {
                              if ((local_5c.length != 0) &&
                                 (ses->sid_ctx[0] = *local_5c.data, (local_5c.length & 2U) != 0)) {
                                *(undefined2 *)(ses->sid_ctx + (local_5c.length - 2)) =
                                     *(undefined2 *)((int)local_5c.data + (local_5c.length - 2U));
                              }
                            }
                            else {
                              *(undefined4 *)ses->sid_ctx = *(undefined4 *)local_5c.data;
                              *(undefined4 *)(ses->sid_ctx + (local_5c.length - 4)) =
                                   *(undefined4 *)((int)local_5c.data + (local_5c.length - 4U));
                              uVar11 = (uint)(ses->sid_ctx + 4) & 0xfffffffc;
                              iVar3 = (int)ses->sid_ctx - uVar11;
                              uVar12 = iVar3 + local_5c.length & 0xfffffffc;
                              if (3 < uVar12) {
                                uVar9 = 0;
                                do {
                                  *(undefined4 *)(uVar11 + uVar9) =
                                       *(undefined4 *)((int)local_5c.data + (uVar9 - iVar3));
                                  uVar9 = uVar9 + 4;
                                } while (uVar9 < uVar12);
                              }
                            }
                            CRYPTO_free(local_5c.data);
                            local_5c.data = (uchar *)0x0;
                            local_5c.length = 0;
                            goto LAB_080ce05f;
                          }
                        }
                      }
                      else {
                        local_4c.error = 0x3b;
                      }
                      local_4c.line = 0x205;
                    }
                  }
                  else {
                    local_4c.q = local_4c.p;
                    uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                             local_4c.slen);
                    if ((uVar11 & 0x80) == 0) {
                      if (uVar11 == 0x21) {
                        local_70 = (byte *)(local_4c.slen +
                                           (-2 - ((int)local_4c.p - (int)local_4c.q)));
                        pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                        if (pAVar4 != (ASN1_INTEGER *)0x0) {
                          local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q));
                          iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                          if (iVar3 != 0) goto LAB_080ce760;
                          local_4c.error = 0x3f;
                        }
                      }
                      else {
                        pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                        if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080ce760:
                          local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                          goto LAB_080cdfcb;
                        }
                      }
                    }
                    else {
                      local_4c.error = 0x3b;
                    }
                    local_4c.line = 499;
                  }
                }
                else {
                  local_4c.q = local_4c.p;
                  uVar11 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                           local_4c.slen);
                  if ((uVar11 & 0x80) == 0) {
                    if (uVar11 == 0x21) {
                      local_70 = (byte *)(local_4c.slen + (-2 - ((int)local_4c.p - (int)local_4c.q))
                                         );
                      pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                      if (pAVar4 != (ASN1_INTEGER *)0x0) {
                        local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q));
                        iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                        if (iVar3 != 0) goto LAB_080ce728;
                        local_4c.error = 0x3f;
                      }
                    }
                    else {
                      pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                      if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080ce728:
                        local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                        goto LAB_080cdf7b;
                      }
                    }
                  }
                  else {
                    local_4c.error = 0x3b;
                  }
                  local_4c.line = 0x1e9;
                }
              }
            }
          }
          else if (lVar5 < 0x300) {
            local_4c.error = 0xfe;
          }
          else {
            if (local_5c.length == 2) {
              uVar11 = *(byte *)((int)local_5c.data + 1) | 0x3000000 | (uint)*local_5c.data << 8;
              goto LAB_080cdde4;
            }
LAB_080cdd04:
            local_4c.error = 0x89;
          }
        }
      }
    }
  }
LAB_080cdb3f:
  ERR_put_error(0xd,0x67,local_4c.error,"ssl_asn1.c",local_4c.line);
  asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
  if ((a == (SSL_SESSION **)0x0) || (ses != *a)) {
    SSL_SESSION_free(ses);
    ses = (SSL_SESSION *)0x0;
  }
  else {
    ses = (SSL_SESSION *)0x0;
  }
LAB_080cdb84:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ses;
}

