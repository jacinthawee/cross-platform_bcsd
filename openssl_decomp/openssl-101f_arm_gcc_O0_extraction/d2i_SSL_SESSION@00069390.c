
SSL_SESSION * d2i_SSL_SESSION(SSL_SESSION **a,uchar **pp,long length)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  ASN1_INTEGER *pAVar4;
  long lVar5;
  ASN1_OCTET_STRING *pAVar6;
  time_t tVar7;
  X509 *pXVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  SSL_SESSION *ses;
  byte *local_84 [2];
  ASN1_INTEGER *local_7c;
  ASN1_OCTET_STRING *local_78;
  int iStack_74;
  int iStack_70;
  byte *local_6c;
  ASN1_OCTET_STRING local_68;
  ASN1_INTEGER local_54;
  ASN1_const_CTX local_44;
  
  local_44.p = *pp;
  local_44.error = 0x3a;
  local_84[0] = (byte *)length;
  local_44.q = local_44.p;
  local_44.pp = pp;
  if ((a == (SSL_SESSION **)0x0) || (ses = *a, ses == (SSL_SESSION *)0x0)) {
    ses = SSL_SESSION_new();
    if (ses == (SSL_SESSION *)0x0) {
      local_44.line = 0x182;
      ERR_put_error(0xd,0x67,local_44.error,"ssl_asn1.c",0x182);
      asn1_add_error(*pp,(int)local_44.q - (int)*pp);
      return (SSL_SESSION *)0x0;
    }
    local_44.p = *pp;
  }
  local_7c = &local_54;
  local_78 = &local_68;
  local_44.max = local_84[0];
  if (local_84[0] != (byte *)0x0) {
    local_44.max = local_84[0] + (int)local_44.p;
  }
  iVar3 = asn1_GetSequence(&local_44,(long *)local_84);
  if (iVar3 == 0) {
    local_44.line = 0x188;
    goto LAB_000693d6;
  }
  local_54.data = (uchar *)0x0;
  local_44.q = local_44.p;
  local_54.length = 0;
  pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,local_44.slen);
  if (pAVar4 == (ASN1_INTEGER *)0x0) {
    local_44.line = 0x18b;
    goto LAB_000693d6;
  }
  local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
  if (local_54.data != (uchar *)0x0) {
    CRYPTO_free(local_54.data);
    local_54.data = (uchar *)0x0;
    local_54.length = 0;
  }
  local_44.q = local_44.p;
  pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,local_44.slen);
  if (pAVar4 == (ASN1_INTEGER *)0x0) {
    local_44.line = 399;
    goto LAB_000693d6;
  }
  local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
  lVar5 = ASN1_INTEGER_get(local_7c);
  ses->ssl_version = lVar5;
  if (local_54.data != (uchar *)0x0) {
    CRYPTO_free(local_54.data);
    local_54.data = (uchar *)0x0;
    local_54.length = 0;
  }
  local_68.data = (byte *)0x0;
  local_44.q = local_44.p;
  local_68.length = 0;
  pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,local_44.slen);
  if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
    local_44.line = 0x195;
    goto LAB_000693d6;
  }
  local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
  if (lVar5 == 2) {
    if ((byte *)local_68.length == (byte *)0x3) {
      uVar10 = local_68.data[2] | 0x2000000 | (uint)*local_68.data << 0x10 |
               (uint)local_68.data[1] << 8;
LAB_00069512:
      *(uint *)(ses->krb5_client_princ + 0x28) = uVar10;
      *(undefined4 *)(ses->krb5_client_princ + 0x24) = 0;
      local_44.q = local_44.p;
      pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,local_44.slen);
      if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
        local_44.line = 0x1b6;
        goto LAB_000693d6;
      }
      pbVar11 = (byte *)local_68.length;
      if (0x20 < local_68.length) {
        pbVar11 = (byte *)0x20;
      }
      local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
      ses->session_id_length = (uint)pbVar11;
      if (0x20 < local_68.length) {
        local_68.length = (int)pbVar11;
      }
      memcpy(ses->session_id,local_68.data,(size_t)pbVar11);
      local_44.q = local_44.p;
      pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,local_44.slen);
      if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
        local_44.line = 0x1c5;
        goto LAB_000693d6;
      }
      pbVar11 = (byte *)local_68.length;
      if (0x2f < local_68.length) {
        pbVar11 = (byte *)0x30;
      }
      local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
      ses->master_key_length = (int)pbVar11;
      memcpy(ses->master_key,local_68.data,(size_t)pbVar11);
      local_68.length = 0;
      pbVar11 = (byte *)local_44.slen;
      if ((byte *)local_44.slen != (byte *)0x0) {
        bVar1 = *local_44.p;
        if ((bVar1 & 0xdf) == 0x80) {
          *local_44.p = bVar1 & 0x20 | 4;
          local_44.q = local_44.p;
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,local_44.slen);
          if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
            local_44.line = 0x1e0;
            *local_44.q = bVar1;
            goto LAB_000693d6;
          }
          local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
          *local_44.q = bVar1;
          pbVar11 = (byte *)local_68.length;
          if (7 < local_68.length) {
            pbVar11 = &DAT_00000008;
          }
        }
        else {
          pbVar11 = (byte *)0x0;
        }
      }
      ses->key_arg_length = (uint)pbVar11;
      memcpy(ses->key_arg,local_68.data,(size_t)pbVar11);
      if (local_68.data != (byte *)0x0) {
        CRYPTO_free(local_68.data);
      }
      local_54.length = 0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa1)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_0006997a;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_0006997a:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            goto LAB_000695c8;
          }
        }
        local_44.line = 0x1e9;
        goto LAB_000693d6;
      }
LAB_000695c8:
      if (local_54.data == (uchar *)0x0) {
        tVar7 = time((time_t *)0x0);
        *(time_t *)(ses->krb5_client_princ + 0x1c) = tVar7;
      }
      else {
        lVar5 = ASN1_INTEGER_get(local_7c);
        *(long *)(ses->krb5_client_princ + 0x1c) = lVar5;
        CRYPTO_free(local_54.data);
        local_54.data = (uchar *)0x0;
      }
      local_54.length = 0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa2)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069956;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_00069956:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            goto LAB_000695f6;
          }
        }
        local_44.line = 499;
        goto LAB_000693d6;
      }
LAB_000695f6:
      if (local_54.data == (uchar *)0x0) {
        *(undefined4 *)(ses->krb5_client_princ + 0x18) = 3;
      }
      else {
        lVar5 = ASN1_INTEGER_get(local_7c);
        *(long *)(ses->krb5_client_princ + 0x18) = lVar5;
        CRYPTO_free(local_54.data);
        local_54.data = (uchar *)0x0;
        local_54.length = 0;
      }
      if (*(X509 **)(ses->krb5_client_princ + 0xc) != (X509 *)0x0) {
        X509_free(*(X509 **)(ses->krb5_client_princ + 0xc));
        *(undefined4 *)(ses->krb5_client_princ + 0xc) = 0;
      }
      pbVar11 = (byte *)local_44.slen;
      pbVar2 = (byte *)local_44.slen;
      if ((byte *)local_44.slen != (byte *)0x0) {
        if (*local_44.p == 0xa3) {
          local_44.q = local_44.p;
          iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen)
          ;
          if (iVar3 << 0x18 < 0) {
            local_44.error = 0x3b;
          }
          else if (iVar3 == 0x21) {
            local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
            pXVar8 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_44.p,(long)local_6c);
            if (pXVar8 != (X509 *)0x0) {
              local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
              iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
              if (iVar3 != 0) goto LAB_000699a0;
              local_44.error = 0x3f;
            }
          }
          else {
            pXVar8 = d2i_X509((X509 **)(ses->krb5_client_princ + 0xc),&local_44.p,(long)local_6c);
            if (pXVar8 != (X509 *)0x0) {
LAB_000699a0:
              local_68.length = 0;
              local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
              local_68.data = (byte *)0x0;
              pbVar11 = (byte *)local_68.length;
              pbVar2 = local_68.data;
              if ((byte *)local_44.slen == (byte *)0x0) goto LAB_00069648;
              goto LAB_00069640;
            }
          }
          local_44.line = 0x201;
          goto LAB_000693d6;
        }
LAB_00069640:
        local_68.data = (byte *)0x0;
        local_68.length = 0;
        pbVar11 = (byte *)local_68.length;
        pbVar2 = local_68.data;
        if (*local_44.p != 0xa4) goto LAB_00069648;
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_000699d2;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_000699d2:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            pbVar11 = (byte *)local_68.length;
            pbVar2 = local_68.data;
            if (local_68.data == (byte *)0x0) goto LAB_00069648;
            if (0x20 < local_68.length) {
              local_44.error = 0x10f;
              goto LAB_000693d6;
            }
            ses->sid_ctx_length = local_68.length;
            memcpy(ses->sid_ctx,local_68.data,local_68.length);
            CRYPTO_free(local_68.data);
            local_68.data = (byte *)0x0;
            local_68.length = 0;
            goto LAB_0006964c;
          }
        }
        local_44.line = 0x205;
        goto LAB_000693d6;
      }
LAB_00069648:
      local_68.data = pbVar2;
      local_68.length = (int)pbVar11;
      ses->sid_ctx_length = 0;
LAB_0006964c:
      local_54.length = 0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa5)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069dac;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_00069dac:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            goto LAB_0006965c;
          }
        }
        local_44.line = 0x219;
        goto LAB_000693d6;
      }
LAB_0006965c:
      if (local_54.data == (uchar *)0x0) {
        *(undefined4 *)(ses->krb5_client_princ + 0x10) = 0;
      }
      else {
        lVar5 = ASN1_INTEGER_get(local_7c);
        *(long *)(ses->krb5_client_princ + 0x10) = lVar5;
        CRYPTO_free(local_54.data);
        local_54.data = (uchar *)0x0;
        local_54.length = 0;
      }
      local_68.length = 0;
      local_68.data = (byte *)0x0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa6)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069c7c;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069c7c:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            if (local_68.data == (byte *)0x0) goto LAB_0006968a;
            pcVar9 = BUF_strndup((char *)local_68.data,local_68.length);
            *(char **)(ses->krb5_client_princ + 0x40) = pcVar9;
            CRYPTO_free(local_68.data);
            goto LAB_00069690;
          }
        }
        local_44.line = 0x225;
        goto LAB_000693d6;
      }
LAB_0006968a:
      *(undefined4 *)(ses->krb5_client_princ + 0x40) = 0;
LAB_00069690:
      local_68.length = 0;
      local_68.data = (byte *)0x0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa7)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069b6c;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069b6c:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            if (local_68.data == (byte *)0x0) goto LAB_0006969c;
            pcVar9 = BUF_strndup((char *)local_68.data,local_68.length);
            ses->krb5_client_princ_len = (uint)pcVar9;
            CRYPTO_free(local_68.data);
            goto LAB_000696a2;
          }
        }
        local_44.line = 0x234;
        goto LAB_000693d6;
      }
LAB_0006969c:
      ses->krb5_client_princ_len = 0;
LAB_000696a2:
      local_68.length = 0;
      local_68.data = (byte *)0x0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa8)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069d62;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069d62:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            if (local_68.data == (byte *)0x0) goto LAB_000696ae;
            pcVar9 = BUF_strndup((char *)local_68.data,local_68.length);
            *(char **)ses->krb5_client_princ = pcVar9;
            CRYPTO_free(local_68.data);
            local_68.data = (byte *)0x0;
            local_68.length = 0;
            goto LAB_000696b4;
          }
        }
        local_44.line = 0x241;
        goto LAB_000693d6;
      }
LAB_000696ae:
      *(undefined4 *)ses->krb5_client_princ = 0;
LAB_000696b4:
      local_54.length = 0;
      if (((byte *)local_44.slen != (byte *)0x0) && (*local_44.p == 0xa9)) {
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069cbc;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar4 = d2i_ASN1_INTEGER(&local_7c,&local_44.p,(long)local_6c);
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
LAB_00069cbc:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            goto LAB_000696c4;
          }
        }
        local_44.line = 0x24f;
        goto LAB_000693d6;
      }
LAB_000696c4:
      if (local_54.data == (uchar *)0x0) {
        if ((*(int *)(ses->krb5_client_princ + 0x58) == 0) || (ses->session_id_length == 0)) {
          *(undefined4 *)(ses->krb5_client_princ + 0x5c) = 0;
        }
        else {
          *(undefined4 *)(ses->krb5_client_princ + 0x5c) = 0xffffffff;
        }
      }
      else {
        lVar5 = ASN1_INTEGER_get(local_7c);
        *(long *)(ses->krb5_client_princ + 0x5c) = lVar5;
        CRYPTO_free(local_54.data);
        local_54.data = (uchar *)0x0;
        local_54.length = 0;
      }
      local_68.length = 0;
      local_68.data = (byte *)0x0;
      if ((byte *)local_44.slen == (byte *)0x0) {
        *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
LAB_00069834:
        local_68.length = 0;
        local_68.data = (byte *)0x0;
LAB_0006971e:
        *(undefined4 *)(ses->krb5_client_princ + 0x60) = 0;
LAB_00069724:
        iVar3 = asn1_const_Finish(&local_44);
        if (iVar3 != 0) {
          *pp = local_44.p;
          if (a != (SSL_SESSION **)0x0) {
            *a = ses;
            return ses;
          }
          return ses;
        }
        local_44.line = 0x281;
      }
      else {
        if (*local_44.p == 0xaa) {
          local_44.q = local_44.p;
          iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen)
          ;
          if (iVar3 << 0x18 < 0) {
            local_44.error = 0x3b;
          }
          else if (iVar3 == 0x21) {
            local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
            pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
              local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
              iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
              if (iVar3 != 0) goto LAB_00069b2e;
              local_44.error = 0x3f;
            }
          }
          else {
            pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069b2e:
              local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
              if (local_68.data != (byte *)0x0) {
                *(int *)(ses->krb5_client_princ + 0x58) = local_68.length;
              }
              *(uchar **)(ses->krb5_client_princ + 0x54) = local_68.data;
              if ((byte *)local_44.slen == (byte *)0x0) goto LAB_00069834;
              goto LAB_00069706;
            }
          }
          local_44.line = 0x25b;
          goto LAB_000693d6;
        }
        *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
LAB_00069706:
        local_68.data = (byte *)0x0;
        local_68.length = 0;
        if (*local_44.p == 0xab) {
          local_44.q = local_44.p;
          iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen)
          ;
          if (iVar3 << 0x18 < 0) {
            local_44.error = 0x3b;
          }
          else if (iVar3 == 0x21) {
            local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
            pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
              local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
              iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
              if (iVar3 != 0) goto LAB_00069d22;
              local_44.error = 0x3f;
            }
          }
          else {
            pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
            if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069d22:
              local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
              if (local_68.data != (byte *)0x0) {
                *(uint *)(ses->krb5_client_princ + 0x20) = (uint)*local_68.data;
                CRYPTO_free(local_68.data);
              }
              local_68.length = 0;
              local_68.data = (byte *)0x0;
              if ((byte *)local_44.slen == (byte *)0x0) goto LAB_0006971e;
              goto LAB_00069716;
            }
          }
          local_44.line = 0x269;
          goto LAB_000693d6;
        }
LAB_00069716:
        local_68.data = (byte *)0x0;
        local_68.length = 0;
        if (*local_44.p != 0xac) goto LAB_0006971e;
        local_44.q = local_44.p;
        iVar3 = ASN1_get_object(&local_44.p,(long *)&local_6c,&iStack_74,&iStack_70,local_44.slen);
        if (iVar3 << 0x18 < 0) {
          local_44.error = 0x3b;
        }
        else if (iVar3 == 0x21) {
          local_6c = (byte *)(local_44.slen + (int)(local_44.q + (-2 - (int)local_44.p)));
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            local_6c = (byte *)(local_44.slen + ((int)local_44.q - (int)local_44.p));
            iVar3 = ASN1_const_check_infinite_end(&local_44.p,(long)local_6c);
            if (iVar3 != 0) goto LAB_00069ce0;
            local_44.error = 0x3f;
          }
        }
        else {
          pAVar6 = d2i_ASN1_OCTET_STRING(&local_78,&local_44.p,(long)local_6c);
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
LAB_00069ce0:
            local_44.slen = local_44.slen + ((int)local_44.q - (int)local_44.p);
            if (local_68.data == (byte *)0x0) goto LAB_0006971e;
            pcVar9 = BUF_strndup((char *)local_68.data,local_68.length);
            *(char **)(ses->krb5_client_princ + 0x60) = pcVar9;
            CRYPTO_free(local_68.data);
            local_68.data = (byte *)0x0;
            local_68.length = 0;
            goto LAB_00069724;
          }
        }
        local_44.line = 0x275;
      }
      goto LAB_000693d6;
    }
  }
  else {
    if (lVar5 < 0x300) {
      local_44.error = 0xfe;
      goto LAB_000693d6;
    }
    if ((byte *)local_68.length == (byte *)0x2) {
      uVar10 = local_68.data[1] | 0x3000000 | (uint)*local_68.data << 8;
      goto LAB_00069512;
    }
  }
  local_44.error = 0x89;
LAB_000693d6:
  ERR_put_error(0xd,0x67,local_44.error,"ssl_asn1.c",local_44.line);
  asn1_add_error(*pp,(int)local_44.q - (int)*pp);
  if ((a == (SSL_SESSION **)0x0) || (ses != *a)) {
    SSL_SESSION_free(ses);
  }
  return (SSL_SESSION *)0x0;
}

