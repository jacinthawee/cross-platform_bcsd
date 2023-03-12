
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  X509_VERIFY_PARAM *pXVar1;
  _func_1856 *p_Var2;
  bool bVar3;
  _STACK *p_Var4;
  X509 *pXVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  X509 *pXVar9;
  void *pvVar10;
  int iVar11;
  char *pcVar12;
  X509_VERIFY_PARAM *pXVar13;
  int iVar14;
  int in_GS_OFFSET;
  X509 *local_50;
  int local_4c;
  X509 *local_48;
  int local_40;
  int local_3c;
  int local_38;
  X509 *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pXVar1 = ctx->param;
  if (ctx->cert == (X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x69,"x509_vfy.c",0xa4);
    iVar6 = -1;
    goto LAB_08160ac6;
  }
  p_Var2 = ctx->verify_cb;
  if (ctx->chain == (stack_st_X509 *)0x0) {
    p_Var4 = sk_new_null();
    ctx->chain = (stack_st_X509 *)p_Var4;
    if ((p_Var4 != (_STACK *)0x0) && (iVar6 = sk_push(p_Var4,ctx->cert), iVar6 != 0)) {
      CRYPTO_add_lock(&ctx->cert->references,1,3,"x509_vfy.c",0xb4);
      ctx->last_untrusted = 1;
      goto LAB_081606db;
    }
    p_Var4 = (_STACK *)0x0;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xb1);
    local_50 = (X509 *)0x0;
LAB_08160a86:
    iVar6 = 0;
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
  }
  else {
LAB_081606db:
    if ((_STACK *)ctx->untrusted != (_STACK *)0x0) {
      p_Var4 = sk_dup((_STACK *)ctx->untrusted);
      if (p_Var4 != (_STACK *)0x0) goto LAB_081606fc;
      iVar6 = 0xbc;
LAB_08160a6b:
      ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",iVar6);
LAB_08160a7e:
      local_50 = (X509 *)0x0;
      goto LAB_08160a86;
    }
    p_Var4 = (_STACK *)0x0;
LAB_081606fc:
    local_4c = sk_num((_STACK *)ctx->chain);
    pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,local_4c + -1);
    iVar14 = pXVar1->depth;
    while (((local_4c <= iVar14 && (iVar6 = (*ctx->check_issued)(ctx,pXVar5,pXVar5), iVar6 == 0)) &&
           (ctx->untrusted != (stack_st_X509 *)0x0))) {
      iVar6 = 0;
      while( true ) {
        iVar7 = sk_num(p_Var4);
        if (iVar7 <= iVar6) {
          local_24 = (X509 *)0x0;
          goto LAB_08160796;
        }
        pXVar9 = (X509 *)sk_value(p_Var4,iVar6);
        iVar7 = (*ctx->check_issued)(ctx,pXVar5,pXVar9);
        if (iVar7 != 0) break;
        iVar6 = iVar6 + 1;
      }
      local_24 = pXVar9;
      if (pXVar9 == (X509 *)0x0) break;
      iVar6 = sk_push((_STACK *)ctx->chain,pXVar9);
      if (iVar6 == 0) {
        iVar6 = 0xd9;
        goto LAB_08160a6b;
      }
      CRYPTO_add_lock(&local_24->references,1,3,"x509_vfy.c",0xdc);
      sk_delete_ptr(p_Var4,local_24);
      local_4c = local_4c + 1;
      ctx->last_untrusted = ctx->last_untrusted + 1;
      pXVar5 = local_24;
    }
LAB_08160796:
    iVar6 = sk_num((_STACK *)ctx->chain);
    iVar6 = iVar6 + -1;
    pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6);
    iVar7 = (*ctx->check_issued)(ctx,pXVar5,pXVar5);
    bVar3 = false;
    local_50 = (X509 *)0x0;
    if (iVar7 != 0) {
      iVar7 = sk_num((_STACK *)ctx->chain);
      if (iVar7 == 1) {
        iVar7 = (*ctx->get_issuer)(&local_24,ctx,pXVar5);
        if (iVar7 < 1) {
          ctx->error = 0x12;
          ctx->current_cert = pXVar5;
          ctx->error_depth = iVar6;
        }
        else {
          iVar11 = X509_cmp(pXVar5,local_24);
          if (iVar11 == 0) {
            X509_free(pXVar5);
            pXVar5 = local_24;
            sk_set((_STACK *)ctx->chain,iVar6,local_24);
            ctx->last_untrusted = 0;
            bVar3 = false;
            goto LAB_081607d5;
          }
          ctx->error = 0x12;
          ctx->current_cert = pXVar5;
          ctx->error_depth = iVar6;
          if (iVar7 == 1) {
            X509_free(local_24);
          }
        }
        iVar6 = (*p_Var2)(0,ctx);
        if (iVar6 == 0) goto LAB_08160a7e;
        bVar3 = true;
        local_50 = (X509 *)0x0;
      }
      else {
        local_50 = (X509 *)sk_pop((_STACK *)ctx->chain);
        ctx->last_untrusted = ctx->last_untrusted + -1;
        pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,local_4c + -2);
        local_4c = local_4c + -1;
      }
    }
LAB_081607d5:
    if (local_4c <= iVar14) {
      do {
        iVar6 = (*ctx->check_issued)(ctx,pXVar5,pXVar5);
        if (iVar6 != 0) break;
        iVar6 = (*ctx->get_issuer)(&local_24,ctx,pXVar5);
        pXVar9 = local_24;
        if (iVar6 < 0) goto LAB_08160ac6;
        if (iVar6 == 0) break;
        iVar6 = sk_push((_STACK *)ctx->chain,local_24);
        if (iVar6 == 0) {
          X509_free(local_24);
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x12e);
          goto LAB_08160ac6;
        }
        local_4c = local_4c + 1;
        pXVar5 = pXVar9;
      } while (local_4c <= iVar14);
    }
    iVar6 = (*ctx->check_issued)(ctx,pXVar5,pXVar5);
    if (iVar6 == 0) {
      if ((local_50 == (X509 *)0x0) ||
         (iVar6 = (*ctx->check_issued)(ctx,pXVar5,local_50), iVar6 == 0)) {
        iVar6 = 0x14;
        ctx->current_cert = pXVar5;
        if (ctx->last_untrusted < local_4c) {
          iVar6 = 2;
        }
        ctx->error = iVar6;
      }
      else {
        sk_push((_STACK *)ctx->chain,local_50);
        local_4c = local_4c + 1;
        ctx->current_cert = local_50;
        ctx->error = 0x13;
        ctx->last_untrusted = local_4c;
        local_50 = (X509 *)0x0;
      }
      ctx->error_depth = local_4c + -1;
      iVar6 = (*p_Var2)(0,ctx);
      if (iVar6 == 0) goto LAB_08160a86;
      bVar3 = true;
    }
    p_Var2 = ctx->verify_cb;
    local_48 = (X509 *)0x0;
    local_38 = 6;
    if (ctx->parent == (X509_STORE_CTX *)0x0) {
      uVar8 = ctx->param->flags;
      pcVar12 = getenv("OPENSSL_ALLOW_PROXY_CERTS");
      local_48 = (X509 *)0x1;
      if (pcVar12 == (char *)0x0) {
        local_48 = (X509 *)(uVar8 >> 6 & 1);
      }
      local_38 = ctx->param->purpose;
    }
    if (0 < ctx->last_untrusted) {
      local_40 = 0;
      local_3c = 0;
      iVar6 = 0;
      iVar14 = -1;
      do {
        pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6);
        if (((*(byte *)&ctx->param->flags & 0x10) == 0) &&
           ((*(byte *)((int)&pXVar5->ex_flags + 1) & 2) != 0)) {
          ctx->error = 0x22;
          ctx->error_depth = iVar6;
          ctx->current_cert = pXVar5;
          iVar7 = (*p_Var2)(0,ctx);
          if (iVar7 == 0) goto LAB_08160a86;
        }
        pXVar9 = local_48;
        if ((local_48 == (X509 *)0x0) && ((*(byte *)((int)&pXVar5->ex_flags + 1) & 4) != 0)) {
          ctx->error = 0x28;
          ctx->error_depth = iVar6;
          ctx->current_cert = pXVar5;
          pXVar9 = (X509 *)(*p_Var2)(0,ctx);
          if (pXVar9 == (X509 *)0x0) goto LAB_08160a86;
        }
        uVar8 = X509_check_ca(pXVar9);
        if (iVar14 == -1) {
          pXVar13 = ctx->param;
          if (((*(byte *)&pXVar13->flags & 0x20) != 0) && (1 < uVar8)) {
LAB_08160c5a:
            ctx->error = 0x18;
LAB_08160981:
            ctx->error_depth = iVar6;
            ctx->current_cert = pXVar5;
            iVar7 = (*p_Var2)(0,ctx);
            if (iVar7 != 0) goto LAB_0816099e;
            goto LAB_08160a86;
          }
        }
        else if (iVar14 == 0) {
          if (uVar8 != 0) {
            ctx->error = 0x25;
            goto LAB_08160981;
          }
LAB_0816099e:
          pXVar13 = ctx->param;
        }
        else if ((uVar8 == 0) ||
                ((pXVar13 = ctx->param, (*(byte *)&pXVar13->flags & 0x20) != 0 && (uVar8 != 1))))
        goto LAB_08160c5a;
        if ((0 < pXVar13->purpose) &&
           ((iVar14 = X509_check_purpose(pXVar5,local_38,(uint)(0 < iVar14)), iVar14 == 0 ||
            (((*(byte *)&ctx->param->flags & 0x20) != 0 && (iVar14 != 1)))))) {
          ctx->error = 0x1a;
          ctx->error_depth = iVar6;
          ctx->current_cert = pXVar5;
          iVar14 = (*p_Var2)(0,ctx);
          if (iVar14 == 0) goto LAB_08160a86;
        }
        if (iVar6 < 2) {
LAB_08160c30:
          uVar8 = pXVar5->ex_flags;
          if ((uVar8 & 0x20) == 0) {
LAB_08160a20:
            local_40 = local_40 + 1;
          }
        }
        else {
          uVar8 = pXVar5->ex_flags;
          if ((uVar8 & 0x20) == 0) {
            if ((pXVar5->ex_pathlen == -1) || (local_40 <= pXVar5->ex_pathlen + 1 + local_3c))
            goto LAB_08160a20;
            ctx->error = 0x19;
            ctx->error_depth = iVar6;
            ctx->current_cert = pXVar5;
            iVar14 = (*p_Var2)(0,ctx);
            if (iVar14 != 0) goto LAB_08160c30;
            goto LAB_08160a86;
          }
        }
        if ((uVar8 & 0x400) == 0) {
          iVar14 = 1;
        }
        else {
          if ((pXVar5->ex_pcpathlen != -1) && (pXVar5->ex_pcpathlen < iVar6)) {
            ctx->error = 0x26;
            ctx->error_depth = iVar6;
            ctx->current_cert = pXVar5;
            iVar14 = (*p_Var2)(0,ctx);
            if (iVar14 == 0) goto LAB_08160a86;
          }
          local_3c = local_3c + 1;
          iVar14 = 0;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < ctx->last_untrusted);
    }
    iVar6 = sk_num((_STACK *)ctx->chain);
    iVar6 = iVar6 + -1;
    if (-1 < iVar6) {
      do {
        pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6);
        if (iVar6 == 0) {
          iVar14 = sk_num((_STACK *)ctx->chain);
          iVar14 = iVar14 + -1;
          if (0 < iVar14) goto LAB_08160d77;
          break;
        }
        if ((*(byte *)&pXVar5->ex_flags & 0x20) == 0) {
          iVar14 = sk_num((_STACK *)ctx->chain);
          while (iVar14 = iVar14 + -1, iVar6 < iVar14) {
LAB_08160d77:
            pvVar10 = sk_value((_STACK *)ctx->chain,iVar14);
            if ((*(NAME_CONSTRAINTS **)((int)pvVar10 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
               (iVar7 = NAME_CONSTRAINTS_check(pXVar5,*(NAME_CONSTRAINTS **)((int)pvVar10 + 0x4c)),
               iVar7 != 0)) {
              ctx->error = iVar7;
              ctx->error_depth = iVar6;
              ctx->current_cert = pXVar5;
              iVar7 = (*ctx->verify_cb)(0,ctx);
              if (iVar7 == 0) goto LAB_08160a86;
            }
          }
        }
        iVar6 = iVar6 + -1;
      } while (iVar6 != -1);
    }
    if (0 < pXVar1->trust) {
      p_Var2 = ctx->verify_cb;
      iVar6 = sk_num((_STACK *)ctx->chain);
      pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar6 + -1);
      iVar14 = X509_check_trust(pXVar5,ctx->param->trust,0);
      if (iVar14 != 1) {
        ctx->error_depth = iVar6 + -1;
        ctx->current_cert = pXVar5;
        ctx->error = (iVar14 == 2) + 0x1b;
        iVar6 = (*p_Var2)(0,ctx);
        if (iVar6 == 0) goto LAB_08160a86;
      }
    }
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
    iVar6 = (*ctx->check_revocation)(ctx);
    if (iVar6 == 0) goto LAB_08160a86;
    if (ctx->verify == (_func_1855 *)0x0) {
      iVar6 = internal_verify(ctx);
    }
    else {
      iVar6 = (*ctx->verify)(ctx);
    }
    if ((iVar6 == 0) ||
       (((!bVar3 && ((*(byte *)&ctx->param->flags & 0x80) != 0)) &&
        (iVar6 = (*ctx->check_policy)(ctx), iVar6 == 0)))) goto LAB_08160a86;
  }
  if (p_Var4 != (_STACK *)0x0) {
    sk_free(p_Var4);
  }
  if (local_50 != (X509 *)0x0) {
    X509_free(local_50);
  }
LAB_08160ac6:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

