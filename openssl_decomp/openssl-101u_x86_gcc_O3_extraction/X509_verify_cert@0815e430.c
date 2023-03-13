
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  X509_VERIFY_PARAM *pXVar1;
  _func_1856 *p_Var2;
  bool bVar3;
  bool bVar4;
  _STACK *p_Var5;
  int iVar6;
  X509 *pXVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  X509 *pXVar11;
  char *pcVar12;
  X509_NAME *pXVar13;
  X509_NAME *name;
  int iVar14;
  void *pvVar15;
  X509_NAME_ENTRY *pXVar16;
  ASN1_OBJECT *o;
  X509_VERIFY_PARAM *pXVar17;
  int in_GS_OFFSET;
  X509 *local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  X509 *local_38;
  int local_30;
  X509 *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (ctx->cert == (X509 *)0x0) {
    iVar10 = 0xa2;
    iVar6 = 0x69;
  }
  else {
    if (ctx->chain == (stack_st_X509 *)0x0) {
      pXVar1 = ctx->param;
      p_Var2 = ctx->verify_cb;
      p_Var5 = sk_new_null();
      ctx->chain = (stack_st_X509 *)p_Var5;
      if ((p_Var5 == (_STACK *)0x0) || (iVar6 = sk_push(p_Var5,ctx->cert), iVar6 == 0)) {
        p_Var5 = (_STACK *)0x0;
        iVar6 = -1;
        ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xb8);
        ctx->error = 0x11;
        local_50 = (X509 *)0x0;
      }
      else {
        CRYPTO_add_lock(&ctx->cert->references,1,3,"x509_vfy.c",0xbd);
        ctx->last_untrusted = 1;
        if ((_STACK *)ctx->untrusted == (_STACK *)0x0) {
          p_Var5 = (_STACK *)0x0;
LAB_0815e578:
          local_38 = (X509 *)sk_num((_STACK *)ctx->chain);
          pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,(int)local_38 + -1);
          iVar10 = pXVar1->depth;
          while ((((int)local_38 <= iVar10 &&
                  (iVar6 = (*ctx->check_issued)(ctx,pXVar7,pXVar7), iVar6 == 0)) &&
                 (ctx->untrusted != (stack_st_X509 *)0x0))) {
            iVar6 = 0;
            while( true ) {
              iVar8 = sk_num(p_Var5);
              if (iVar8 <= iVar6) {
                local_24 = (X509 *)0x0;
                goto LAB_0815e60e;
              }
              pXVar11 = (X509 *)sk_value(p_Var5,iVar6);
              iVar8 = (*ctx->check_issued)(ctx,pXVar7,pXVar11);
              if (iVar8 != 0) break;
              iVar6 = iVar6 + 1;
            }
            local_24 = pXVar11;
            if (pXVar11 == (X509 *)0x0) break;
            iVar6 = sk_push((_STACK *)ctx->chain,pXVar11);
            if (iVar6 == 0) {
              iVar10 = 0xde;
              goto LAB_0815e96f;
            }
            CRYPTO_add_lock(&local_24->references,1,3,"x509_vfy.c",0xe3);
            sk_delete_ptr(p_Var5,local_24);
            local_38 = (X509 *)((int)local_38 + 1);
            ctx->last_untrusted = ctx->last_untrusted + 1;
            pXVar7 = local_24;
          }
LAB_0815e60e:
          bVar4 = false;
          local_50 = (X509 *)0x0;
          local_44 = (int)local_38;
          do {
            iVar6 = sk_num((_STACK *)ctx->chain);
            iVar6 = iVar6 + -1;
            pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6);
            iVar8 = (*ctx->check_issued)(ctx,pXVar7,pXVar7);
            if (iVar8 != 0) {
              iVar8 = sk_num((_STACK *)ctx->chain);
              if (iVar8 == 1) {
                iVar8 = (*ctx->get_issuer)(&local_24,ctx,pXVar7);
                if (iVar8 < 1) {
                  ctx->error = 0x12;
                  ctx->current_cert = pXVar7;
                  ctx->error_depth = iVar6;
                }
                else {
                  iVar14 = X509_cmp(pXVar7,local_24);
                  if (iVar14 == 0) {
                    X509_free(pXVar7);
                    pXVar7 = local_24;
                    sk_set((_STACK *)ctx->chain,iVar6,local_24);
                    ctx->last_untrusted = 0;
                    goto joined_r0x0815e65f;
                  }
                  ctx->error = 0x12;
                  ctx->current_cert = pXVar7;
                  ctx->error_depth = iVar6;
                  if (iVar8 == 1) {
                    X509_free(local_24);
                  }
                }
                iVar6 = (*p_Var2)(0,ctx);
                if (iVar6 == 0) goto LAB_0815e4bf;
                bVar4 = true;
              }
              else {
                local_50 = (X509 *)sk_pop((_STACK *)ctx->chain);
                ctx->last_untrusted = ctx->last_untrusted + -1;
                local_44 = local_44 + -1;
                pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,(int)local_38 + -2);
                local_38 = (X509 *)((int)local_38 + -1);
              }
            }
joined_r0x0815e65f:
            while (((int)local_38 <= iVar10 &&
                   (iVar6 = (*ctx->check_issued)(ctx,pXVar7,pXVar7), iVar6 == 0))) {
              iVar6 = (*ctx->get_issuer)(&local_24,ctx,pXVar7);
              pXVar11 = local_24;
              if (iVar6 < 0) goto LAB_0815e9f9;
              if (iVar6 == 0) break;
              iVar6 = sk_push((_STACK *)ctx->chain,local_24);
              if (iVar6 == 0) {
                iVar6 = -1;
                X509_free(local_24);
                ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x139);
                ctx->error = 0x11;
                goto LAB_0815e4bf;
              }
              local_38 = (X509 *)((int)local_38 + 1);
              pXVar7 = pXVar11;
            }
            iVar8 = ctx->last_untrusted;
            if (((X509 *)iVar8 != local_38) ||
               (local_38 = (X509 *)iVar8, (*(byte *)((int)&ctx->param->flags + 2) & 0x10) != 0)) {
LAB_0815e713:
              iVar6 = (*ctx->check_issued)(ctx,pXVar7,pXVar7);
              if (iVar6 == 0) {
                if ((local_50 == (X509 *)0x0) ||
                   (iVar6 = (*ctx->check_issued)(ctx,pXVar7,local_50), iVar6 == 0)) {
                  iVar6 = 0x14;
                  ctx->current_cert = pXVar7;
                  if (ctx->last_untrusted < (int)local_38) {
                    iVar6 = 2;
                  }
                  ctx->error = iVar6;
                }
                else {
                  sk_push((_STACK *)ctx->chain,local_50);
                  local_38 = (X509 *)((int)local_38 + 1);
                  ctx->current_cert = local_50;
                  ctx->error = 0x13;
                  ctx->last_untrusted = (int)local_38;
                  local_50 = (X509 *)0x0;
                }
                ctx->error_depth = (int)local_38 + -1;
                iVar6 = (*p_Var2)(0,ctx);
                if (iVar6 == 0) goto LAB_0815e4bf;
                bVar4 = true;
              }
              p_Var2 = ctx->verify_cb;
              local_38 = (X509 *)0x0;
              local_30 = 6;
              if (ctx->parent == (X509_STORE_CTX *)0x0) {
                uVar9 = ctx->param->flags;
                pcVar12 = getenv("OPENSSL_ALLOW_PROXY_CERTS");
                local_38 = (X509 *)0x1;
                if (pcVar12 == (char *)0x0) {
                  local_38 = (X509 *)(uVar9 >> 6 & 1);
                }
                local_30 = ctx->param->purpose;
              }
              if (ctx->last_untrusted < 1) goto LAB_0815ecda;
              local_3c = 0;
              local_44 = 0;
              iVar6 = 0;
              local_40 = -1;
              goto LAB_0815e7fb;
            }
            iVar14 = local_44 + -1;
            do {
              local_44 = iVar14;
              if (local_44 + 1 < 2) goto LAB_0815e713;
              pXVar11 = (X509 *)sk_value((_STACK *)ctx->chain,local_44 + -1);
              iVar6 = (*ctx->get_issuer)(&local_24,ctx,pXVar11);
              if (iVar6 < 0) goto LAB_0815e9f9;
              iVar14 = local_44 + -1;
            } while (iVar6 == 0);
            X509_free(local_24);
            if (local_44 < iVar8) {
              do {
                iVar8 = iVar8 + -1;
                local_24 = (X509 *)sk_pop((_STACK *)ctx->chain);
                X509_free(local_24);
                local_38 = (X509 *)local_44;
              } while (local_44 != iVar8);
            }
            iVar6 = sk_num((_STACK *)ctx->chain);
            ctx->last_untrusted = iVar6;
          } while( true );
        }
        p_Var5 = sk_dup((_STACK *)ctx->untrusted);
        if (p_Var5 != (_STACK *)0x0) goto LAB_0815e578;
        iVar10 = 0xc3;
LAB_0815e96f:
        iVar6 = -1;
        ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",iVar10);
        ctx->error = 0x11;
        local_50 = (X509 *)0x0;
      }
      goto LAB_0815e4bf;
    }
    iVar10 = 0xab;
    iVar6 = 0x42;
  }
  ERR_put_error(0xb,0x7f,iVar6,"x509_vfy.c",iVar10);
  ctx->error = 0x41;
  iVar6 = -1;
  goto LAB_0815e4f9;
LAB_0815e7fb:
  do {
    pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6);
    if (((*(byte *)&ctx->param->flags & 0x10) == 0) &&
       ((*(byte *)((int)&pXVar7->ex_flags + 1) & 2) != 0)) {
      ctx->error = 0x22;
      ctx->error_depth = iVar6;
      ctx->current_cert = pXVar7;
      iVar10 = (*p_Var2)(0,ctx);
      if (iVar10 == 0) goto LAB_0815ec36;
    }
    pXVar11 = local_38;
    if ((local_38 == (X509 *)0x0) && ((*(byte *)((int)&pXVar7->ex_flags + 1) & 4) != 0)) {
      ctx->error = 0x28;
      ctx->error_depth = iVar6;
      ctx->current_cert = pXVar7;
      pXVar11 = (X509 *)(*p_Var2)(0,ctx);
      if (pXVar11 == (X509 *)0x0) goto LAB_0815ec36;
    }
    uVar9 = X509_check_ca(pXVar11);
    if (local_40 == -1) {
      pXVar17 = ctx->param;
      if (((*(byte *)&pXVar17->flags & 0x20) != 0) && (1 < uVar9)) {
LAB_0815ebae:
        ctx->error = 0x18;
LAB_0815e85d:
        ctx->error_depth = iVar6;
        ctx->current_cert = pXVar7;
        iVar10 = (*p_Var2)(0,ctx);
        if (iVar10 != 0) goto LAB_0815e876;
        goto LAB_0815ec36;
      }
    }
    else if (local_40 == 0) {
      if (uVar9 != 0) {
        ctx->error = 0x25;
        goto LAB_0815e85d;
      }
LAB_0815e876:
      pXVar17 = ctx->param;
    }
    else if ((uVar9 == 0) ||
            ((pXVar17 = ctx->param, (*(byte *)&pXVar17->flags & 0x20) != 0 && (uVar9 != 1))))
    goto LAB_0815ebae;
    if ((0 < pXVar17->purpose) &&
       ((iVar10 = X509_check_purpose(pXVar7,local_30,(uint)(0 < local_40)), iVar10 == 0 ||
        (((*(byte *)&ctx->param->flags & 0x20) != 0 && (iVar10 != 1)))))) {
      ctx->error = 0x1a;
      ctx->error_depth = iVar6;
      ctx->current_cert = pXVar7;
      iVar10 = (*p_Var2)(0,ctx);
      if (iVar10 == 0) goto LAB_0815ec36;
    }
    if (iVar6 < 2) {
LAB_0815ebf0:
      uVar9 = pXVar7->ex_flags;
      if ((uVar9 & 0x20) == 0) {
LAB_0815e8f8:
        local_3c = local_3c + 1;
      }
    }
    else {
      uVar9 = pXVar7->ex_flags;
      if ((uVar9 & 0x20) == 0) {
        if ((pXVar7->ex_pathlen == -1) || (local_3c <= pXVar7->ex_pathlen + 1 + local_44))
        goto LAB_0815e8f8;
        ctx->error = 0x19;
        ctx->error_depth = iVar6;
        ctx->current_cert = pXVar7;
        iVar10 = (*p_Var2)(0,ctx);
        if (iVar10 != 0) goto LAB_0815ebf0;
        goto LAB_0815ec36;
      }
    }
    if ((uVar9 & 0x400) == 0) {
      local_40 = 1;
    }
    else {
      iVar10 = pXVar7->ex_pcpathlen;
      if ((iVar10 != -1) && (bVar3 = iVar10 < local_44, local_44 = iVar10, bVar3)) {
        ctx->error = 0x26;
        ctx->error_depth = iVar6;
        ctx->current_cert = pXVar7;
        iVar10 = (*p_Var2)(0,ctx);
        if (iVar10 == 0) goto LAB_0815ec36;
        local_44 = pXVar7->ex_pcpathlen;
      }
      local_44 = local_44 + 1;
      local_40 = 0;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < ctx->last_untrusted);
LAB_0815ecda:
  local_48 = sk_num((_STACK *)ctx->chain);
LAB_0815ecf3:
  do {
    local_48 = local_48 + -1;
    if (local_48 < 0) goto LAB_0815ee95;
    pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,local_48);
  } while ((local_48 != 0) && ((pXVar7->ex_flags & 0x20) != 0));
  if ((pXVar7->ex_flags & 0x400) == 0) goto LAB_0815edd6;
  pXVar13 = X509_get_subject_name(pXVar7);
  name = X509_get_issuer_name(pXVar7);
  iVar10 = X509_NAME_entry_count(pXVar13);
  iVar6 = iVar10 + -1;
  if (0 < iVar6) {
    iVar8 = X509_NAME_entry_count(pXVar13);
    iVar14 = X509_NAME_entry_count(name);
    if (iVar8 == iVar14 + 1) {
      pXVar16 = X509_NAME_get_entry(pXVar13,iVar6);
      iVar8 = pXVar16->set;
      pXVar16 = X509_NAME_get_entry(pXVar13,iVar10 + -2);
      if (iVar8 != pXVar16->set) {
        pXVar13 = X509_NAME_dup(pXVar13);
        if (pXVar13 == (X509_NAME *)0x0) {
          ERR_put_error(0xb,0x6a,0x41,"x509_vfy.c",0x2d6);
          ctx->error = 0x11;
LAB_0815ec36:
          iVar6 = 0;
          goto LAB_0815e4bf;
        }
        pXVar16 = X509_NAME_delete_entry(pXVar13,iVar6);
        o = X509_NAME_ENTRY_get_object(pXVar16);
        iVar6 = OBJ_obj2nid(o);
        if ((iVar6 == 0xd) && (iVar6 = X509_NAME_cmp(pXVar13,name), iVar6 == 0)) {
          X509_NAME_ENTRY_free(pXVar16);
          X509_NAME_free(pXVar13);
          goto LAB_0815edd6;
        }
        X509_NAME_ENTRY_free(pXVar16);
        X509_NAME_free(pXVar13);
      }
    }
  }
  ctx->error = 0x43;
  ctx->current_cert = pXVar7;
  ctx->error_depth = local_48;
  iVar6 = (*ctx->verify_cb)(0,ctx);
  if (iVar6 == 0) goto LAB_0815ec36;
LAB_0815edd6:
  iVar6 = sk_num((_STACK *)ctx->chain);
  while (iVar6 = iVar6 + -1, local_48 < iVar6) {
    pvVar15 = sk_value((_STACK *)ctx->chain,iVar6);
    if ((*(NAME_CONSTRAINTS **)((int)pvVar15 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
       (iVar10 = NAME_CONSTRAINTS_check(pXVar7,*(NAME_CONSTRAINTS **)((int)pvVar15 + 0x4c)),
       iVar10 != 0)) {
      if (iVar10 == 0x11) {
        ctx->error = 0x11;
        goto LAB_0815ec36;
      }
      ctx->error = iVar10;
      ctx->current_cert = pXVar7;
      ctx->error_depth = local_48;
      iVar10 = (*ctx->verify_cb)(0,ctx);
      if (iVar10 == 0) goto LAB_0815ec36;
    }
  }
  goto LAB_0815ecf3;
LAB_0815ee95:
  if (0 < pXVar1->trust) {
    p_Var2 = ctx->verify_cb;
    iVar6 = sk_num((_STACK *)ctx->chain);
    pXVar7 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6 + -1);
    iVar10 = X509_check_trust(pXVar7,ctx->param->trust,0);
    if (iVar10 != 1) {
      ctx->error_depth = iVar6 + -1;
      ctx->current_cert = pXVar7;
      iVar6 = 0;
      ctx->error = (iVar10 == 2) + 0x1b;
      iVar10 = (*p_Var2)(0,ctx);
      if (iVar10 == 0) goto LAB_0815e4bf;
    }
  }
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
  iVar6 = (*ctx->check_revocation)(ctx);
  if (iVar6 == 0) goto LAB_0815e4bf;
  if (ctx->verify == (_func_1855 *)0x0) {
    iVar6 = internal_verify(ctx);
  }
  else {
    iVar6 = (*ctx->verify)(ctx);
  }
  if ((iVar6 == 0) ||
     (((!bVar4 && ((*(byte *)&ctx->param->flags & 0x80) != 0)) &&
      (iVar6 = (*ctx->check_policy)(ctx), iVar6 == 0)))) goto LAB_0815e4bf;
  goto LAB_0815e4cf;
LAB_0815e9f9:
  ctx->error = 0x42;
LAB_0815e4bf:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
LAB_0815e4cf:
  if (p_Var5 != (_STACK *)0x0) {
    sk_free(p_Var5);
  }
  if (local_50 != (X509 *)0x0) {
    X509_free(local_50);
  }
  if ((iVar6 < 1) && (ctx->error == 0)) {
    ctx->error = 1;
  }
LAB_0815e4f9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

