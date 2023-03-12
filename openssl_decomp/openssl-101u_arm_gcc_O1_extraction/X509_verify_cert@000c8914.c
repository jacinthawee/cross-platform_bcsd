
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  bool bVar1;
  _STACK *st;
  int iVar2;
  int iVar3;
  X509 *pXVar4;
  int iVar5;
  X509 *pXVar6;
  int iVar7;
  X509 *pXVar8;
  uint uVar9;
  X509_NAME *pXVar10;
  X509_NAME *name;
  void *pvVar11;
  int iVar12;
  char *pcVar13;
  X509_NAME_ENTRY *pXVar14;
  ASN1_OBJECT *o;
  _func_1856 *p_Var15;
  X509_VERIFY_PARAM *pXVar16;
  ulong uVar17;
  X509 *st_00;
  int iVar18;
  uint uVar19;
  X509_VERIFY_PARAM *pXVar20;
  int local_44;
  int local_3c;
  X509 *local_2c [2];
  
  pXVar20 = ctx->param;
  if (ctx->cert == (X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x69,"x509_vfy.c",0xa2);
    ctx->error = 0x41;
    return -1;
  }
  if (ctx->chain != (stack_st_X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x42,"x509_vfy.c",0xab);
    ctx->error = 0x41;
    return -1;
  }
  p_Var15 = ctx->verify_cb;
  st = sk_new_null();
  ctx->chain = (stack_st_X509 *)st;
  if ((st == (_STACK *)0x0) || (iVar2 = sk_push(st,ctx->cert), iVar2 == 0)) {
    st_00 = (X509 *)0x0;
    iVar2 = -1;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xb8);
    ctx->error = 0x11;
    pXVar4 = (X509 *)0x0;
  }
  else {
    CRYPTO_add_lock(&ctx->cert->references,1,3,"x509_vfy.c",0xbd);
    st_00 = (X509 *)ctx->untrusted;
    ctx->last_untrusted = 1;
    if ((st_00 == (X509 *)0x0) || (st_00 = (X509 *)sk_dup((_STACK *)st_00), st_00 != (X509 *)0x0)) {
      iVar3 = sk_num((_STACK *)ctx->chain);
      pXVar4 = (X509 *)sk_value((_STACK *)ctx->chain,iVar3 + -1);
      iVar18 = pXVar20->depth;
      while (((iVar3 <= iVar18 && (iVar2 = (*ctx->check_issued)(ctx,pXVar4,pXVar4), iVar2 == 0)) &&
             (ctx->untrusted != (stack_st_X509 *)0x0))) {
        do {
          iVar5 = sk_num((_STACK *)st_00);
          if (iVar5 <= iVar2) {
            local_2c[0] = (X509 *)0x0;
            goto LAB_000c8a2e;
          }
          pXVar6 = (X509 *)sk_value((_STACK *)st_00,iVar2);
          iVar5 = (*ctx->check_issued)(ctx,pXVar4,pXVar6);
          iVar2 = iVar2 + 1;
        } while (iVar5 == 0);
        local_2c[0] = pXVar6;
        if (pXVar6 == (X509 *)0x0) break;
        pXVar4 = (X509 *)sk_push((_STACK *)ctx->chain,pXVar6);
        if (pXVar4 == (X509 *)0x0) {
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xde);
          iVar2 = -1;
          ctx->error = 0x11;
          goto LAB_000c8966;
        }
        iVar3 = iVar3 + 1;
        CRYPTO_add_lock(&local_2c[0]->references,1,3,"x509_vfy.c",0xe3);
        sk_delete_ptr((_STACK *)st_00,local_2c[0]);
        ctx->last_untrusted = ctx->last_untrusted + 1;
        pXVar4 = local_2c[0];
      }
LAB_000c8a2e:
      pXVar4 = (X509 *)0x0;
      bVar1 = false;
      iVar5 = iVar3;
      do {
        iVar2 = sk_num((_STACK *)ctx->chain);
        iVar2 = iVar2 + -1;
        pXVar6 = (X509 *)sk_value((_STACK *)ctx->chain,iVar2);
        iVar7 = (*ctx->check_issued)(ctx,pXVar6,pXVar6);
        if (iVar7 != 0) {
          iVar7 = sk_num((_STACK *)ctx->chain);
          if (iVar7 == 1) {
            iVar7 = (*ctx->get_issuer)(local_2c,ctx,pXVar6);
            if (iVar7 < 1) {
              ctx->current_cert = pXVar6;
              ctx->error = 0x12;
              ctx->error_depth = iVar2;
            }
            else {
              iVar12 = X509_cmp(pXVar6,local_2c[0]);
              if (iVar12 == 0) {
                X509_free(pXVar6);
                pXVar6 = local_2c[0];
                sk_set((_STACK *)ctx->chain,iVar2,local_2c[0]);
                ctx->last_untrusted = 0;
                goto LAB_000c8a8e;
              }
              ctx->current_cert = pXVar6;
              ctx->error = 0x12;
              ctx->error_depth = iVar2;
              if (iVar7 == 1) {
                X509_free(local_2c[0]);
              }
            }
            iVar2 = (*p_Var15)(0,ctx);
            if (iVar2 == 0) goto LAB_000c8966;
            bVar1 = true;
          }
          else {
            pXVar4 = (X509 *)sk_pop((_STACK *)ctx->chain);
            iVar3 = iVar3 + -1;
            ctx->last_untrusted = ctx->last_untrusted + -1;
            pXVar6 = (X509 *)sk_value((_STACK *)ctx->chain,iVar5 + -2);
            iVar5 = iVar5 + -1;
          }
        }
LAB_000c8a8e:
        while ((iVar5 <= iVar18 && (iVar2 = (*ctx->check_issued)(ctx,pXVar6,pXVar6), iVar2 == 0))) {
          iVar2 = (*ctx->get_issuer)(local_2c,ctx,pXVar6);
          pXVar8 = local_2c[0];
          if (iVar2 < 0) goto LAB_000c8dcc;
          if (iVar2 == 0) break;
          iVar5 = iVar5 + 1;
          iVar2 = sk_push((_STACK *)ctx->chain,local_2c[0]);
          pXVar6 = pXVar8;
          if (iVar2 == 0) {
            X509_free(local_2c[0]);
            ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x139);
            iVar2 = -1;
            ctx->error = 0x11;
            goto LAB_000c8966;
          }
        }
        iVar7 = ctx->last_untrusted;
        if ((iVar7 != iVar5) || (iVar5 = iVar7, (int)(ctx->param->flags << 0xb) < 0)) {
LAB_000c8ada:
          pXVar8 = (X509 *)(*ctx->check_issued)(ctx,pXVar6,pXVar6);
          if (pXVar8 == (X509 *)0x0) {
            if ((pXVar4 == (X509 *)0x0) ||
               (iVar2 = (*ctx->check_issued)(ctx,pXVar6,pXVar4), iVar2 == 0)) {
              ctx->current_cert = pXVar6;
              if (ctx->last_untrusted < iVar5) {
                iVar2 = 2;
              }
              else {
                iVar2 = 0x14;
              }
              ctx->error = iVar2;
              pXVar8 = pXVar4;
            }
            else {
              sk_push((_STACK *)ctx->chain,pXVar4);
              iVar5 = iVar5 + 1;
              ctx->current_cert = pXVar4;
              ctx->last_untrusted = iVar5;
              ctx->error = 0x13;
            }
            ctx->error_depth = iVar5 + -1;
            iVar2 = (*p_Var15)(0,ctx);
            pXVar4 = pXVar8;
            if (iVar2 == 0) goto LAB_000c8966;
            bVar1 = true;
          }
          p_Var15 = ctx->verify_cb;
          if (ctx->parent == (X509_STORE_CTX *)0x0) {
            uVar19 = (ctx->param->flags << 0x19) >> 0x1f;
            pcVar13 = getenv("OPENSSL_ALLOW_PROXY_CERTS");
            local_3c = ctx->param->purpose;
            if (pcVar13 != (char *)0x0) {
              uVar19 = 1;
            }
          }
          else {
            uVar19 = 0;
            local_3c = 6;
          }
          if (ctx->last_untrusted < 1) goto LAB_000c8c4e;
          iVar18 = 0;
          iVar3 = 0;
          iVar2 = 0;
          local_44 = -1;
          goto LAB_000c8b5a;
        }
        iVar12 = iVar3 + -1;
        do {
          iVar3 = iVar12;
          if (iVar3 + 1 < 2) goto LAB_000c8ada;
          pXVar8 = (X509 *)sk_value((_STACK *)ctx->chain,iVar3 + -1);
          iVar2 = (*ctx->get_issuer)(local_2c,ctx,pXVar8);
          if (iVar2 < 0) goto LAB_000c8dcc;
          iVar12 = iVar3 + -1;
        } while (iVar2 == 0);
        X509_free(local_2c[0]);
        if (iVar3 < iVar7) {
          do {
            iVar7 = iVar7 + -1;
            local_2c[0] = (X509 *)sk_pop((_STACK *)ctx->chain);
            X509_free(local_2c[0]);
            iVar5 = iVar3;
          } while (iVar7 != iVar3);
        }
        iVar2 = sk_num((_STACK *)ctx->chain);
        ctx->last_untrusted = iVar2;
      } while( true );
    }
    iVar2 = -1;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xc3);
    ctx->error = 0x11;
    pXVar4 = st_00;
  }
LAB_000c8966:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
LAB_000c896e:
  if (st_00 != (X509 *)0x0) {
    sk_free((_STACK *)st_00);
  }
  if (pXVar4 != (X509 *)0x0) {
    X509_free(pXVar4);
  }
  if ((iVar2 < 1) && (ctx->error == 0)) {
    ctx->error = 1;
    return iVar2;
  }
  return iVar2;
LAB_000c8b5a:
  do {
    pXVar6 = (X509 *)sk_value((_STACK *)ctx->chain,iVar3);
    if (((ctx->param->flags & 0x10) == 0) && ((int)(pXVar6->ex_flags << 0x16) < 0)) {
      ctx->error_depth = iVar3;
      ctx->error = 0x22;
      ctx->current_cert = pXVar6;
      iVar5 = (*p_Var15)(0,ctx);
      if (iVar5 == 0) goto LAB_000c8d14;
    }
    if ((uVar19 == 0) && ((int)(pXVar6->ex_flags << 0x15) < 0)) {
      ctx->error = 0x28;
      ctx->error_depth = iVar3;
      ctx->current_cert = pXVar6;
      iVar5 = (*p_Var15)(0,ctx);
      if (iVar5 == 0) goto LAB_000c8d14;
    }
    uVar9 = X509_check_ca(pXVar6);
    if (local_44 == -1) {
      pXVar16 = ctx->param;
      if (((int)(pXVar16->flags << 0x1a) < 0) && (1 < uVar9)) {
LAB_000c8f20:
        ctx->error = 0x18;
LAB_000c8ba4:
        ctx->error_depth = iVar3;
        ctx->current_cert = pXVar6;
        iVar5 = (*p_Var15)(0,ctx);
        if (iVar5 != 0) goto LAB_000c8bb8;
        goto LAB_000c8d14;
      }
    }
    else if (local_44 == 0) {
      if (uVar9 != 0) {
        ctx->error = 0x25;
        goto LAB_000c8ba4;
      }
LAB_000c8bb8:
      pXVar16 = ctx->param;
    }
    else if ((uVar9 == 0) ||
            ((pXVar16 = ctx->param, (int)(pXVar16->flags << 0x1a) < 0 && (uVar9 != 1))))
    goto LAB_000c8f20;
    if ((0 < pXVar16->purpose) &&
       ((iVar5 = X509_check_purpose(pXVar6,local_3c,(uint)(0 < local_44)), iVar5 == 0 ||
        (((int)(ctx->param->flags << 0x1a) < 0 && (iVar5 != 1)))))) {
      ctx->error_depth = iVar3;
      ctx->current_cert = pXVar6;
      ctx->error = 0x1a;
      iVar5 = (*p_Var15)(0,ctx);
      if (iVar5 == 0) goto LAB_000c8d14;
    }
    if (iVar3 < 2) {
LAB_000c8f02:
      uVar17 = pXVar6->ex_flags;
      if (-1 < (int)(uVar17 << 0x1a)) {
LAB_000c8c1c:
        iVar18 = iVar18 + 1;
      }
    }
    else {
      uVar17 = pXVar6->ex_flags;
      if ((uVar17 & 0x20) == 0) {
        if ((pXVar6->ex_pathlen == -1) || (iVar18 <= pXVar6->ex_pathlen + iVar2 + 1))
        goto LAB_000c8c1c;
        ctx->error_depth = iVar3;
        ctx->error = 0x19;
        ctx->current_cert = pXVar6;
        iVar5 = (*p_Var15)(0,ctx);
        if (iVar5 != 0) goto LAB_000c8f02;
        goto LAB_000c8d14;
      }
    }
    if ((int)(uVar17 << 0x15) < 0) {
      iVar7 = pXVar6->ex_pcpathlen;
      iVar5 = iVar2;
      if ((iVar7 != -1) && (iVar5 = iVar7, iVar7 < iVar2)) {
        ctx->error_depth = iVar3;
        ctx->current_cert = pXVar6;
        ctx->error = 0x26;
        iVar2 = (*p_Var15)(0,ctx);
        if (iVar2 == 0) goto LAB_000c8d14;
        iVar5 = pXVar6->ex_pcpathlen;
      }
      iVar2 = iVar5 + 1;
      local_44 = 0;
    }
    else {
      local_44 = 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < ctx->last_untrusted);
LAB_000c8c4e:
  iVar2 = sk_num((_STACK *)ctx->chain);
LAB_000c8c60:
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) goto LAB_000c9006;
    pXVar6 = (X509 *)sk_value((_STACK *)ctx->chain,iVar2);
  } while ((iVar2 != 0) && ((int)(pXVar6->ex_flags << 0x1a) < 0));
  if (-1 < (int)(pXVar6->ex_flags << 0x15)) goto LAB_000c8cd0;
  pXVar10 = X509_get_subject_name(pXVar6);
  name = X509_get_issuer_name(pXVar6);
  iVar3 = X509_NAME_entry_count(pXVar10);
  iVar18 = iVar3 + -1;
  if (0 < iVar18) {
    iVar5 = X509_NAME_entry_count(pXVar10);
    iVar7 = X509_NAME_entry_count(name);
    if (iVar5 == iVar7 + 1) {
      pXVar14 = X509_NAME_get_entry(pXVar10,iVar18);
      iVar5 = pXVar14->set;
      pXVar14 = X509_NAME_get_entry(pXVar10,iVar3 + -2);
      if (iVar5 != pXVar14->set) {
        pXVar10 = X509_NAME_dup(pXVar10);
        if (pXVar10 == (X509_NAME *)0x0) {
          ERR_put_error(0xb,0x6a,0x41,"x509_vfy.c",0x2d6);
          ctx->error = 0x11;
LAB_000c8d14:
          iVar2 = 0;
          goto LAB_000c8966;
        }
        pXVar14 = X509_NAME_delete_entry(pXVar10,iVar18);
        o = X509_NAME_ENTRY_get_object(pXVar14);
        iVar3 = OBJ_obj2nid(o);
        if ((iVar3 == 0xd) && (iVar3 = X509_NAME_cmp(pXVar10,name), iVar3 == 0)) {
          X509_NAME_ENTRY_free(pXVar14);
          X509_NAME_free(pXVar10);
          goto LAB_000c8cd0;
        }
        X509_NAME_ENTRY_free(pXVar14);
        X509_NAME_free(pXVar10);
      }
    }
  }
  ctx->error = 0x43;
  ctx->error_depth = iVar2;
  ctx->current_cert = pXVar6;
  iVar3 = (*ctx->verify_cb)(0,ctx);
  if (iVar3 == 0) goto LAB_000c8d14;
LAB_000c8cd0:
  iVar3 = sk_num((_STACK *)ctx->chain);
  iVar3 = iVar3 + -1;
  while (iVar18 = iVar3 + -1, iVar2 < iVar3) {
    pvVar11 = sk_value((_STACK *)ctx->chain,iVar3);
    iVar3 = iVar18;
    if ((*(NAME_CONSTRAINTS **)((int)pvVar11 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
       (iVar18 = NAME_CONSTRAINTS_check(pXVar6,*(NAME_CONSTRAINTS **)((int)pvVar11 + 0x4c)),
       iVar18 != 0)) {
      if (iVar18 == 0x11) {
        ctx->error = 0x11;
        goto LAB_000c8d14;
      }
      ctx->error = iVar18;
      ctx->error_depth = iVar2;
      ctx->current_cert = pXVar6;
      iVar18 = (*ctx->verify_cb)(0,ctx);
      if (iVar18 == 0) goto LAB_000c8d14;
    }
  }
  goto LAB_000c8c60;
LAB_000c9006:
  if (0 < pXVar20->trust) {
    p_Var15 = ctx->verify_cb;
    iVar2 = sk_num((_STACK *)ctx->chain);
    pXVar6 = (X509 *)sk_value((_STACK *)ctx->chain,iVar2 + -1);
    iVar3 = X509_check_trust(pXVar6,ctx->param->trust,0);
    if (iVar3 != 1) {
      if (iVar3 == 2) {
        iVar3 = 0x1c;
      }
      else {
        iVar3 = 0x1b;
      }
      ctx->error_depth = iVar2 + -1;
      ctx->error = iVar3;
      ctx->current_cert = pXVar6;
      iVar2 = (*p_Var15)(0,ctx);
      if (iVar2 == 0) goto LAB_000c8966;
    }
  }
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
  iVar2 = (*ctx->check_revocation)(ctx);
  if (iVar2 != 0) {
    if (ctx->verify == (_func_1855 *)0x0) {
      iVar2 = internal_verify();
    }
    else {
      iVar2 = (*ctx->verify)(ctx);
    }
    if ((iVar2 != 0) &&
       (((bVar1 || (-1 < (int)(ctx->param->flags << 0x18))) ||
        (iVar2 = (*ctx->check_policy)(ctx), iVar2 != 0)))) goto LAB_000c896e;
  }
  goto LAB_000c8966;
LAB_000c8dcc:
  ctx->error = 0x42;
  goto LAB_000c8966;
}

