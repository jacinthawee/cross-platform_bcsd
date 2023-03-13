
SSL_SESSION * d2i_SSL_SESSION(SSL_SESSION **a,uchar **pp,long length)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  SSL_SESSION *ses;
  ASN1_INTEGER *pAVar4;
  long lVar5;
  ASN1_OCTET_STRING *pAVar6;
  uint uVar7;
  size_t __n;
  time_t tVar8;
  X509 *pXVar9;
  uint uVar10;
  char *pcVar11;
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
      local_4c.line = 0x184;
      ERR_put_error(0xd,0x67,local_4c.error,"ssl_asn1.c",0x184);
      asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
      ses = (SSL_SESSION *)0x0;
      goto LAB_080cb484;
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
    local_4c.line = 0x18a;
  }
  else {
    local_6c.data = (uchar *)0x0;
    local_6c.length = 0;
    local_4c.q = local_4c.p;
    pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,local_4c.slen);
    if (pAVar4 == (ASN1_INTEGER *)0x0) {
      local_4c.line = 0x18e;
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
        local_4c.line = 0x196;
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
          local_4c.line = 0x1a1;
        }
        else {
          local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
          if (lVar5 == 2) {
            if (local_5c.length == 3) {
              uVar7 = (uint)*(byte *)((int)local_5c.data + 1) << 8 |
                      *(byte *)((int)local_5c.data + 2) | 0x2000000 | (uint)*local_5c.data << 0x10;
LAB_080cb713:
              local_4c.q = local_4c.p;
              *(uint *)(ses->krb5_client_princ + 0x28) = uVar7;
              *(undefined4 *)(ses->krb5_client_princ + 0x24) = 0;
              pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
              if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
                local_4c.line = 0x1be;
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
                  uVar7 = (uint)(ses->session_id + 4) & 0xfffffffc;
                  iVar3 = (int)ses->session_id - uVar7;
                  uVar12 = iVar3 + local_5c.length & 0xfffffffc;
                  if (3 < uVar12) {
                    uVar10 = 0;
                    do {
                      *(undefined4 *)(uVar7 + uVar10) =
                           *(undefined4 *)((int)local_5c.data + (uVar10 - iVar3));
                      uVar10 = uVar10 + 4;
                    } while (uVar10 < uVar12);
                  }
                }
                local_4c.q = local_4c.p;
                pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,local_4c.slen);
                if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
                  local_4c.line = 0x1cd;
                }
                else {
                  local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                  uVar7 = 0x30;
                  if (local_5c.length < 0x31) {
                    uVar7 = local_5c.length;
                  }
                  ses->master_key_length = uVar7;
                  if (uVar7 < 4) {
                    if ((uVar7 != 0) && (ses->master_key[0] = *local_5c.data, (uVar7 & 2) != 0)) {
                      *(undefined2 *)(ses->master_key + (uVar7 - 2)) =
                           *(undefined2 *)((int)local_5c.data + (uVar7 - 2));
                    }
                  }
                  else {
                    *(undefined4 *)ses->master_key = *(undefined4 *)local_5c.data;
                    *(undefined4 *)(ses->master_key + (uVar7 - 4)) =
                         *(undefined4 *)((int)local_5c.data + (uVar7 - 4));
                    uVar12 = (uint)(ses->master_key + 4) & 0xfffffffc;
                    iVar3 = (int)ses->master_key - uVar12;
                    uVar7 = iVar3 + uVar7 & 0xfffffffc;
                    if (3 < uVar7) {
                      uVar10 = 0;
                      do {
                        *(undefined4 *)(uVar12 + uVar10) =
                             *(undefined4 *)((int)local_5c.data + (uVar10 - iVar3));
                        uVar10 = uVar10 + 4;
                      } while (uVar10 < uVar7);
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
                        local_4c.line = 0x1e7;
                        *local_4c.q = bVar1;
                        goto LAB_080cb43f;
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
LAB_080cb8aa:
                    if (local_6c.data == (uchar *)0x0) {
                      tVar8 = time((time_t *)0x0);
                      *(time_t *)(ses->krb5_client_princ + 0x1c) = tVar8;
                    }
                    else {
                      lVar5 = ASN1_INTEGER_get(local_80);
                      *(long *)(ses->krb5_client_princ + 0x1c) = lVar5;
                      CRYPTO_free(local_6c.data);
                      local_6c.data = (uchar *)0x0;
                    }
                    local_6c.length = 0;
                    if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa2)) {
LAB_080cb8fa:
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
LAB_080cb987:
                        ses->sid_ctx_length = 0;
LAB_080cb98e:
                        local_6c.length = 0;
                        if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa5)) {
LAB_080cb9a7:
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
LAB_080cb9fe:
                            *(undefined4 *)(ses->krb5_client_princ + 0x40) = 0;
LAB_080cba08:
                            local_5c.length = 0;
                            local_5c.data = (uchar *)0x0;
                            if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa7)) {
LAB_080cba20:
                              ses->krb5_client_princ_len = 0;
LAB_080cba2a:
                              local_5c.length = 0;
                              local_5c.data = (uchar *)0x0;
                              if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa8)) {
LAB_080cba42:
                                *(undefined4 *)ses->krb5_client_princ = 0;
LAB_080cba4c:
                                local_6c.length = 0;
                                if (((byte *)local_4c.slen == (byte *)0x0) || (*local_4c.p != 0xa9))
                                {
LAB_080cba65:
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
LAB_080cbb05:
                                    *(undefined4 *)(ses->krb5_client_princ + 0x60) = 0;
LAB_080cbb0f:
                                    iVar3 = asn1_const_Finish(&local_4c);
                                    if (iVar3 != 0) {
                                      *pp = local_4c.p;
                                      if (a != (SSL_SESSION **)0x0) {
                                        *a = ses;
                                      }
                                      goto LAB_080cb484;
                                    }
                                    local_4c.line = 0x27b;
                                  }
                                  else if (*local_4c.p == 0xaa) {
                                    local_4c.q = local_4c.p;
                                    uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                            &local_74,local_4c.slen);
                                    if ((uVar7 & 0x80) == 0) {
                                      if (uVar7 == 0x21) {
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
                                          if (iVar3 != 0) goto LAB_080cc508;
                                          local_4c.error = 0x3f;
                                        }
                                      }
                                      else {
                                        pAVar6 = d2i_ASN1_OCTET_STRING
                                                           (&local_7c,&local_4c.p,(long)local_70);
                                        if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc508:
                                          local_4c.slen =
                                               local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                          if ((undefined4 *)local_5c.data != (undefined4 *)0x0) {
                                            *(int *)(ses->krb5_client_princ + 0x58) =
                                                 local_5c.length;
                                          }
                                          *(uchar **)(ses->krb5_client_princ + 0x54) = local_5c.data
                                          ;
                                          if ((byte *)local_4c.slen == (byte *)0x0) {
                                            local_5c.length = 0;
                                            local_5c.data = (uchar *)0x0;
                                            goto LAB_080cbb05;
                                          }
                                          goto LAB_080cbae3;
                                        }
                                      }
                                    }
                                    else {
                                      local_4c.error = 0x3b;
                                    }
                                    local_4c.line = 0x25a;
                                  }
                                  else {
                                    *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
LAB_080cbae3:
                                    local_5c.data = (uchar *)0x0;
                                    local_5c.length = 0;
                                    if (*local_4c.p == 0xab) {
                                      local_4c.q = local_4c.p;
                                      uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,
                                                              &local_78,&local_74,local_4c.slen);
                                      if ((uVar7 & 0x80) == 0) {
                                        if (uVar7 == 0x21) {
                                          local_70 = (byte *)(local_4c.slen +
                                                             (-2 - ((int)local_4c.p -
                                                                   (int)local_4c.q)));
                                          pAVar6 = d2i_ASN1_OCTET_STRING
                                                             (&local_7c,&local_4c.p,(long)local_70);
                                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                            local_70 = (byte *)(local_4c.slen +
                                                               -((int)local_4c.p - (int)local_4c.q))
                                            ;
                                            iVar3 = ASN1_const_check_infinite_end
                                                              (&local_4c.p,(long)local_70);
                                            if (iVar3 != 0) goto LAB_080cc7a4;
                                            local_4c.error = 0x3f;
                                          }
                                        }
                                        else {
                                          pAVar6 = d2i_ASN1_OCTET_STRING
                                                             (&local_7c,&local_4c.p,(long)local_70);
                                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc7a4:
                                            local_4c.slen =
                                                 local_4c.slen +
                                                 -((int)local_4c.p - (int)local_4c.q);
                                            if ((undefined4 *)local_5c.data != (undefined4 *)0x0) {
                                              *(uint *)(ses->krb5_client_princ + 0x20) =
                                                   (uint)*local_5c.data;
                                              CRYPTO_free(local_5c.data);
                                            }
                                            local_5c.length = 0;
                                            local_5c.data = (uchar *)0x0;
                                            if ((byte *)local_4c.slen == (byte *)0x0)
                                            goto LAB_080cbb05;
                                            goto LAB_080cbafc;
                                          }
                                        }
                                      }
                                      else {
                                        local_4c.error = 0x3b;
                                      }
                                      local_4c.line = 0x266;
                                    }
                                    else {
LAB_080cbafc:
                                      local_5c.data = (uchar *)0x0;
                                      local_5c.length = 0;
                                      if (*local_4c.p != 0xac) goto LAB_080cbb05;
                                      local_4c.q = local_4c.p;
                                      uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,
                                                              &local_78,&local_74,local_4c.slen);
                                      if ((uVar7 & 0x80) == 0) {
                                        if (uVar7 == 0x21) {
                                          local_70 = (byte *)(local_4c.slen +
                                                             (-2 - ((int)local_4c.p -
                                                                   (int)local_4c.q)));
                                          pAVar6 = d2i_ASN1_OCTET_STRING
                                                             (&local_7c,&local_4c.p,(long)local_70);
                                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                            local_70 = (byte *)(local_4c.slen +
                                                               -((int)local_4c.p - (int)local_4c.q))
                                            ;
                                            iVar3 = ASN1_const_check_infinite_end
                                                              (&local_4c.p,(long)local_70);
                                            if (iVar3 != 0) goto LAB_080cc60e;
                                            local_4c.error = 0x3f;
                                          }
                                        }
                                        else {
                                          pAVar6 = d2i_ASN1_OCTET_STRING
                                                             (&local_7c,&local_4c.p,(long)local_70);
                                          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc60e:
                                            local_4c.slen =
                                                 local_4c.slen +
                                                 -((int)local_4c.p - (int)local_4c.q);
                                            if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                            goto LAB_080cbb05;
                                            pcVar11 = BUF_strndup((char *)local_5c.data,
                                                                  local_5c.length);
                                            *(char **)(ses->krb5_client_princ + 0x60) = pcVar11;
                                            CRYPTO_free(local_5c.data);
                                            local_5c.data = (uchar *)0x0;
                                            local_5c.length = 0;
                                            goto LAB_080cbb0f;
                                          }
                                        }
                                      }
                                      else {
                                        local_4c.error = 0x3b;
                                      }
                                      local_4c.line = 0x271;
                                    }
                                  }
                                }
                                else {
                                  local_4c.q = local_4c.p;
                                  uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                          &local_74,local_4c.slen);
                                  if ((uVar7 & 0x80) == 0) {
                                    if (uVar7 == 0x21) {
                                      local_70 = (byte *)(local_4c.slen +
                                                         (-2 - ((int)local_4c.p - (int)local_4c.q)))
                                      ;
                                      pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70
                                                               );
                                      if (pAVar4 != (ASN1_INTEGER *)0x0) {
                                        local_70 = (byte *)(local_4c.slen +
                                                           -((int)local_4c.p - (int)local_4c.q));
                                        iVar3 = ASN1_const_check_infinite_end
                                                          (&local_4c.p,(long)local_70);
                                        if (iVar3 != 0) goto LAB_080cc76c;
                                        local_4c.error = 0x3f;
                                      }
                                    }
                                    else {
                                      pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70
                                                               );
                                      if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080cc76c:
                                        local_4c.slen =
                                             local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                        goto LAB_080cba65;
                                      }
                                    }
                                  }
                                  else {
                                    local_4c.error = 0x3b;
                                  }
                                  local_4c.line = 0x24e;
                                }
                              }
                              else {
                                local_4c.q = local_4c.p;
                                uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                        &local_74,local_4c.slen);
                                if ((uVar7 & 0x80) == 0) {
                                  if (uVar7 == 0x21) {
                                    local_70 = (byte *)(local_4c.slen +
                                                       (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                    pAVar6 = d2i_ASN1_OCTET_STRING
                                                       (&local_7c,&local_4c.p,(long)local_70);
                                    if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                      local_70 = (byte *)(local_4c.slen +
                                                         -((int)local_4c.p - (int)local_4c.q));
                                      iVar3 = ASN1_const_check_infinite_end
                                                        (&local_4c.p,(long)local_70);
                                      if (iVar3 != 0) goto LAB_080cc822;
                                      local_4c.error = 0x3f;
                                    }
                                  }
                                  else {
                                    pAVar6 = d2i_ASN1_OCTET_STRING
                                                       (&local_7c,&local_4c.p,(long)local_70);
                                    if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc822:
                                      local_4c.slen =
                                           local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                      if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                      goto LAB_080cba42;
                                      pcVar11 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                      *(char **)ses->krb5_client_princ = pcVar11;
                                      CRYPTO_free(local_5c.data);
                                      local_5c.data = (uchar *)0x0;
                                      local_5c.length = 0;
                                      goto LAB_080cba4c;
                                    }
                                  }
                                }
                                else {
                                  local_4c.error = 0x3b;
                                }
                                local_4c.line = 0x242;
                              }
                            }
                            else {
                              local_4c.q = local_4c.p;
                              uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                      &local_74,local_4c.slen);
                              if ((uVar7 & 0x80) == 0) {
                                if (uVar7 == 0x21) {
                                  local_70 = (byte *)(local_4c.slen +
                                                     (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                  pAVar6 = d2i_ASN1_OCTET_STRING
                                                     (&local_7c,&local_4c.p,(long)local_70);
                                  if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                    local_70 = (byte *)(local_4c.slen +
                                                       -((int)local_4c.p - (int)local_4c.q));
                                    iVar3 = ASN1_const_check_infinite_end
                                                      (&local_4c.p,(long)local_70);
                                    if (iVar3 != 0) goto LAB_080cc422;
                                    local_4c.error = 0x3f;
                                  }
                                }
                                else {
                                  pAVar6 = d2i_ASN1_OCTET_STRING
                                                     (&local_7c,&local_4c.p,(long)local_70);
                                  if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc422:
                                    local_4c.slen =
                                         local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                    if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                    goto LAB_080cba20;
                                    pcVar11 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                    ses->krb5_client_princ_len = (uint)pcVar11;
                                    CRYPTO_free(local_5c.data);
                                    goto LAB_080cba2a;
                                  }
                                }
                              }
                              else {
                                local_4c.error = 0x3b;
                              }
                              local_4c.line = 0x237;
                            }
                          }
                          else {
                            local_4c.q = local_4c.p;
                            uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,
                                                    &local_74,local_4c.slen);
                            if ((uVar7 & 0x80) == 0) {
                              if (uVar7 == 0x21) {
                                local_70 = (byte *)(local_4c.slen +
                                                   (-2 - ((int)local_4c.p - (int)local_4c.q)));
                                pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70)
                                ;
                                if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                                  local_70 = (byte *)(local_4c.slen +
                                                     -((int)local_4c.p - (int)local_4c.q));
                                  iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                                  if (iVar3 != 0) goto LAB_080cc495;
                                  local_4c.error = 0x3f;
                                }
                              }
                              else {
                                pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70)
                                ;
                                if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc495:
                                  local_4c.slen =
                                       local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                                  if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                                  goto LAB_080cb9fe;
                                  pcVar11 = BUF_strndup((char *)local_5c.data,local_5c.length);
                                  *(char **)(ses->krb5_client_princ + 0x40) = pcVar11;
                                  CRYPTO_free(local_5c.data);
                                  goto LAB_080cba08;
                                }
                              }
                            }
                            else {
                              local_4c.error = 0x3b;
                            }
                            local_4c.line = 0x22a;
                          }
                        }
                        else {
                          local_4c.q = local_4c.p;
                          uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                                  local_4c.slen);
                          if ((uVar7 & 0x80) == 0) {
                            if (uVar7 == 0x21) {
                              local_70 = (byte *)(local_4c.slen +
                                                 (-2 - ((int)local_4c.p - (int)local_4c.q)));
                              pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                              if (pAVar4 != (ASN1_INTEGER *)0x0) {
                                local_70 = (byte *)(local_4c.slen +
                                                   -((int)local_4c.p - (int)local_4c.q));
                                iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                                if (iVar3 != 0) goto LAB_080cc5d6;
                                local_4c.error = 0x3f;
                              }
                            }
                            else {
                              pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                              if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080cc5d6:
                                local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q)
                                ;
                                goto LAB_080cb9a7;
                              }
                            }
                          }
                          else {
                            local_4c.error = 0x3b;
                          }
                          local_4c.line = 0x21e;
                        }
                      }
                      else if (*local_4c.p == 0xa3) {
                        local_4c.q = local_4c.p;
                        uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                                local_4c.slen);
                        if ((uVar7 & 0x80) == 0) {
                          if (uVar7 == 0x21) {
                            local_70 = (byte *)(local_4c.slen +
                                               (-2 - ((int)local_4c.p - (int)local_4c.q)));
                            pXVar9 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_4c.p,
                                              (long)local_70);
                            if (pXVar9 != (X509 *)0x0) {
                              local_70 = (byte *)(local_4c.slen +
                                                 -((int)local_4c.p - (int)local_4c.q));
                              iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                              if (iVar3 != 0) goto LAB_080cc0f3;
                              local_4c.error = 0x3f;
                            }
                          }
                          else {
                            pXVar9 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_4c.p,
                                              (long)local_70);
                            if (pXVar9 != (X509 *)0x0) {
LAB_080cc0f3:
                              local_5c.length = 0;
                              local_5c.data = (uchar *)0x0;
                              local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                              if ((byte *)local_4c.slen == (byte *)0x0) goto LAB_080cb987;
                              goto LAB_080cb97e;
                            }
                          }
                        }
                        else {
                          local_4c.error = 0x3b;
                        }
                        local_4c.line = 0x208;
                      }
                      else {
LAB_080cb97e:
                        local_5c.data = (uchar *)0x0;
                        local_5c.length = 0;
                        if (*local_4c.p != 0xa4) goto LAB_080cb987;
                        local_4c.q = local_4c.p;
                        uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                                local_4c.slen);
                        if ((uVar7 & 0x80) == 0) {
                          if (uVar7 == 0x21) {
                            local_70 = (byte *)(local_4c.slen +
                                               (-2 - ((int)local_4c.p - (int)local_4c.q)));
                            pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
                              local_70 = (byte *)(local_4c.slen +
                                                 -((int)local_4c.p - (int)local_4c.q));
                              iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                              if (iVar3 != 0) goto LAB_080cc14d;
                              local_4c.error = 0x3f;
                            }
                          }
                          else {
                            pAVar6 = d2i_ASN1_OCTET_STRING(&local_7c,&local_4c.p,(long)local_70);
                            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_080cc14d:
                              local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                              if ((undefined4 *)local_5c.data == (undefined4 *)0x0)
                              goto LAB_080cb987;
                              if (0x20 < local_5c.length) {
                                local_4c.error = 0x10f;
                                local_4c.line = 0x211;
                                goto LAB_080cb43f;
                              }
                              ses->sid_ctx_length = local_5c.length;
                              if ((uint)local_5c.length < 4) {
                                if ((local_5c.length != 0) &&
                                   (ses->sid_ctx[0] = *local_5c.data, (local_5c.length & 2U) != 0))
                                {
                                  *(undefined2 *)(ses->sid_ctx + (local_5c.length - 2)) =
                                       *(undefined2 *)((int)local_5c.data + (local_5c.length - 2U));
                                }
                              }
                              else {
                                *(undefined4 *)ses->sid_ctx = *(undefined4 *)local_5c.data;
                                *(undefined4 *)(ses->sid_ctx + (local_5c.length - 4)) =
                                     *(undefined4 *)((int)local_5c.data + (local_5c.length - 4U));
                                uVar7 = (uint)(ses->sid_ctx + 4) & 0xfffffffc;
                                iVar3 = (int)ses->sid_ctx - uVar7;
                                uVar12 = iVar3 + local_5c.length & 0xfffffffc;
                                if (3 < uVar12) {
                                  uVar10 = 0;
                                  do {
                                    *(undefined4 *)(uVar7 + uVar10) =
                                         *(undefined4 *)((int)local_5c.data + (uVar10 - iVar3));
                                    uVar10 = uVar10 + 4;
                                  } while (uVar10 < uVar12);
                                }
                              }
                              CRYPTO_free(local_5c.data);
                              local_5c.data = (uchar *)0x0;
                              local_5c.length = 0;
                              goto LAB_080cb98e;
                            }
                          }
                        }
                        else {
                          local_4c.error = 0x3b;
                        }
                        local_4c.line = 0x20c;
                      }
                    }
                    else {
                      local_4c.q = local_4c.p;
                      uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                              local_4c.slen);
                      if ((uVar7 & 0x80) == 0) {
                        if (uVar7 == 0x21) {
                          local_70 = (byte *)(local_4c.slen +
                                             (-2 - ((int)local_4c.p - (int)local_4c.q)));
                          pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                          if (pAVar4 != (ASN1_INTEGER *)0x0) {
                            local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q)
                                               );
                            iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                            if (iVar3 != 0) goto LAB_080cc0b9;
                            local_4c.error = 0x3f;
                          }
                        }
                        else {
                          pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                          if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080cc0b9:
                            local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                            goto LAB_080cb8fa;
                          }
                        }
                      }
                      else {
                        local_4c.error = 0x3b;
                      }
                      local_4c.line = 0x1fb;
                    }
                  }
                  else {
                    local_4c.q = local_4c.p;
                    uVar7 = ASN1_get_object(&local_4c.p,(long *)&local_70,&local_78,&local_74,
                                            local_4c.slen);
                    if ((uVar7 & 0x80) == 0) {
                      if (uVar7 == 0x21) {
                        local_70 = (byte *)(local_4c.slen +
                                           (-2 - ((int)local_4c.p - (int)local_4c.q)));
                        pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                        if (pAVar4 != (ASN1_INTEGER *)0x0) {
                          local_70 = (byte *)(local_4c.slen + -((int)local_4c.p - (int)local_4c.q));
                          iVar3 = ASN1_const_check_infinite_end(&local_4c.p,(long)local_70);
                          if (iVar3 != 0) goto LAB_080cc081;
                          local_4c.error = 0x3f;
                        }
                      }
                      else {
                        pAVar4 = d2i_ASN1_INTEGER(&local_80,&local_4c.p,(long)local_70);
                        if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_080cc081:
                          local_4c.slen = local_4c.slen + -((int)local_4c.p - (int)local_4c.q);
                          goto LAB_080cb8aa;
                        }
                      }
                    }
                    else {
                      local_4c.error = 0x3b;
                    }
                    local_4c.line = 0x1f1;
                  }
                }
              }
            }
            else {
              local_4c.error = 0x89;
              local_4c.line = 0x1a5;
            }
          }
          else if ((lVar5 >> 8 == 3 || lVar5 >> 8 == 0xfe) || (lVar5 == 0x100)) {
            if (local_5c.length == 2) {
              uVar7 = *(byte *)((int)local_5c.data + 1) | 0x3000000 | (uint)*local_5c.data << 8;
              goto LAB_080cb713;
            }
            local_4c.error = 0x89;
            local_4c.line = 0x1b0;
          }
          else {
            local_4c.error = 0xfe;
            local_4c.line = 0x1b7;
          }
        }
      }
    }
  }
LAB_080cb43f:
  ERR_put_error(0xd,0x67,local_4c.error,"ssl_asn1.c",local_4c.line);
  asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
  if ((a == (SSL_SESSION **)0x0) || (ses != *a)) {
    SSL_SESSION_free(ses);
    ses = (SSL_SESSION *)0x0;
  }
  else {
    ses = (SSL_SESSION *)0x0;
  }
LAB_080cb484:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ses;
}

