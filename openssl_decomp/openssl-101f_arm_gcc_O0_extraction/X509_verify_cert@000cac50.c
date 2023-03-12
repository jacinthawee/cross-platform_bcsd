
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  X509 *st;
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  int iVar4;
  X509 *pXVar5;
  X509 *pXVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  _STACK *st_00;
  char *pcVar10;
  X509_VERIFY_PARAM *pXVar11;
  _func_1856 *p_Var12;
  X509_VERIFY_PARAM *pXVar13;
  ulong uVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  int local_44;
  X509 *local_40;
  X509 *local_2c [2];
  
  pXVar11 = ctx->param;
  if (ctx->cert == (X509 *)0x0) {
    ERR_put_error(0xb,0x7f,0x69,"x509_vfy.c",0xa4);
    return -1;
  }
  p_Var12 = ctx->verify_cb;
  if (ctx->chain == (stack_st_X509 *)0x0) {
    st_00 = sk_new_null();
    ctx->chain = (stack_st_X509 *)st_00;
    if ((st_00 != (_STACK *)0x0) && (iVar1 = sk_push(st_00,ctx->cert), iVar1 != 0)) {
      CRYPTO_add_lock(&ctx->cert->references,1,3,"x509_vfy.c",0xb4);
      ctx->last_untrusted = 1;
      goto LAB_000cac70;
    }
    st = (X509 *)0x0;
    ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xb1);
    pXVar2 = (X509 *)0x0;
  }
  else {
LAB_000cac70:
    st = (X509 *)ctx->untrusted;
    if ((st == (X509 *)0x0) || (st = (X509 *)sk_dup((_STACK *)st), st != (X509 *)0x0)) {
      iVar1 = sk_num((_STACK *)ctx->chain);
      pXVar2 = (X509 *)sk_value((_STACK *)ctx->chain,iVar1 + -1);
      iVar15 = pXVar11->depth;
      while (((iVar1 <= iVar15 && (iVar3 = (*ctx->check_issued)(ctx,pXVar2,pXVar2), iVar3 == 0)) &&
             (ctx->untrusted != (stack_st_X509 *)0x0))) {
        do {
          iVar4 = sk_num((_STACK *)st);
          if (iVar4 <= iVar3) {
            local_2c[0] = (X509 *)0x0;
            goto LAB_000cace4;
          }
          pXVar5 = (X509 *)sk_value((_STACK *)st,iVar3);
          iVar4 = (*ctx->check_issued)(ctx,pXVar2,pXVar5);
          iVar3 = iVar3 + 1;
        } while (iVar4 == 0);
        local_2c[0] = pXVar5;
        if (pXVar5 == (X509 *)0x0) break;
        pXVar2 = (X509 *)sk_push((_STACK *)ctx->chain,pXVar5);
        if (pXVar2 == (X509 *)0x0) {
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xd9);
          goto LAB_000caf4a;
        }
        iVar1 = iVar1 + 1;
        CRYPTO_add_lock(&local_2c[0]->references,1,3,"x509_vfy.c",0xdc);
        sk_delete_ptr((_STACK *)st,local_2c[0]);
        ctx->last_untrusted = ctx->last_untrusted + 1;
        pXVar2 = local_2c[0];
      }
LAB_000cace4:
      iVar3 = sk_num((_STACK *)ctx->chain);
      iVar3 = iVar3 + -1;
      pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar3);
      pXVar2 = (X509 *)(*ctx->check_issued)(ctx,pXVar5,pXVar5);
      local_40 = pXVar2;
      if (pXVar2 != (X509 *)0x0) {
        iVar4 = sk_num((_STACK *)ctx->chain);
        if (iVar4 == 1) {
          iVar4 = (*ctx->get_issuer)(local_2c,ctx,pXVar5);
          if (iVar4 < 1) {
            ctx->current_cert = pXVar5;
            ctx->error_depth = iVar3;
            ctx->error = 0x12;
          }
          else {
            pXVar2 = (X509 *)X509_cmp(pXVar5,local_2c[0]);
            if (pXVar2 == (X509 *)0x0) {
              X509_free(pXVar5);
              pXVar5 = local_2c[0];
              sk_set((_STACK *)ctx->chain,iVar3,local_2c[0]);
              ctx->last_untrusted = 0;
              local_40 = pXVar2;
              goto LAB_000cad3e;
            }
            ctx->current_cert = pXVar5;
            ctx->error_depth = iVar3;
            ctx->error = 0x12;
            if (iVar4 == 1) {
              X509_free(local_2c[0]);
            }
          }
          pXVar2 = (X509 *)(*p_Var12)(0,ctx);
          if (pXVar2 == (X509 *)0x0) goto LAB_000caf4a;
          pXVar2 = (X509 *)0x0;
          local_40 = (X509 *)0x1;
        }
        else {
          pXVar2 = (X509 *)sk_pop((_STACK *)ctx->chain);
          ctx->last_untrusted = ctx->last_untrusted + -1;
          pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar1 + -2);
          local_40 = (X509 *)0x0;
          iVar1 = iVar1 + -1;
        }
      }
LAB_000cad3e:
      while ((iVar1 <= iVar15 && (iVar3 = (*ctx->check_issued)(ctx,pXVar5,pXVar5), iVar3 == 0))) {
        iVar3 = (*ctx->get_issuer)(local_2c,ctx,pXVar5);
        pXVar6 = local_2c[0];
        if (iVar3 < 0) {
          return iVar3;
        }
        if (iVar3 == 0) break;
        iVar3 = sk_push((_STACK *)ctx->chain,local_2c[0]);
        pXVar5 = pXVar6;
        iVar1 = iVar1 + 1;
        if (iVar3 == 0) {
          X509_free(local_2c[0]);
          ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0x12e);
          return 0;
        }
      }
      pXVar6 = (X509 *)(*ctx->check_issued)(ctx,pXVar5,pXVar5);
      if (pXVar6 == (X509 *)0x0) {
        if ((pXVar2 == (X509 *)0x0) ||
           (iVar15 = (*ctx->check_issued)(ctx,pXVar5,pXVar2), iVar15 == 0)) {
          ctx->current_cert = pXVar5;
          if (ctx->last_untrusted < iVar1) {
            iVar15 = 2;
          }
          else {
            iVar15 = 0x14;
          }
          ctx->error = iVar15;
          pXVar6 = pXVar2;
        }
        else {
          sk_push((_STACK *)ctx->chain,pXVar2);
          iVar1 = iVar1 + 1;
          ctx->current_cert = pXVar2;
          ctx->last_untrusted = iVar1;
          ctx->error = 0x13;
        }
        ctx->error_depth = iVar1 + -1;
        iVar1 = (*p_Var12)(0,ctx);
        pXVar2 = pXVar6;
        if (iVar1 == 0) goto LAB_000caf4a;
        local_40 = (X509 *)0x1;
      }
      p_Var12 = ctx->verify_cb;
      if (ctx->parent == (X509_STORE_CTX *)0x0) {
        uVar14 = ctx->param->flags;
        pcVar10 = getenv("OPENSSL_ALLOW_PROXY_CERTS");
        uVar16 = (uVar14 << 0x19) >> 0x1f;
        if (pcVar10 != (char *)0x0) {
          uVar16 = 1;
        }
        local_44 = ctx->param->purpose;
      }
      else {
        uVar16 = 0;
        local_44 = 6;
      }
      if (0 < ctx->last_untrusted) {
        iVar4 = 0;
        iVar15 = -1;
        iVar3 = 0;
        iVar1 = 0;
        do {
          pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar1);
          if (((ctx->param->flags & 0x10) == 0) && ((int)(pXVar5->ex_flags << 0x16) < 0)) {
            ctx->error_depth = iVar1;
            ctx->error = 0x22;
            ctx->current_cert = pXVar5;
            iVar8 = (*p_Var12)(0,ctx);
            if (iVar8 == 0) goto LAB_000caf4a;
          }
          if ((uVar16 == 0) && ((int)(pXVar5->ex_flags << 0x15) < 0)) {
            ctx->error = 0x28;
            ctx->error_depth = iVar1;
            ctx->current_cert = pXVar5;
            iVar8 = (*p_Var12)(0,ctx);
            if (iVar8 == 0) goto LAB_000caf4a;
          }
          uVar7 = X509_check_ca(pXVar5);
          if (iVar15 == -1) {
            pXVar13 = ctx->param;
            if (((int)(pXVar13->flags << 0x1a) < 0) && (1 < uVar7)) {
LAB_000cb09a:
              ctx->error = 0x18;
LAB_000cae06:
              ctx->error_depth = iVar1;
              ctx->current_cert = pXVar5;
              iVar8 = (*p_Var12)(0,ctx);
              if (iVar8 != 0) goto LAB_000cae1a;
              goto LAB_000caf4a;
            }
          }
          else if (iVar15 == 0) {
            if (uVar7 != 0) {
              ctx->error = 0x25;
              goto LAB_000cae06;
            }
LAB_000cae1a:
            pXVar13 = ctx->param;
          }
          else if ((uVar7 == 0) ||
                  ((pXVar13 = ctx->param, (int)(pXVar13->flags << 0x1a) < 0 && (uVar7 != 1))))
          goto LAB_000cb09a;
          if ((0 < pXVar13->purpose) &&
             ((iVar15 = X509_check_purpose(pXVar5,local_44,(uint)(0 < iVar15)), iVar15 == 0 ||
              (((int)(ctx->param->flags << 0x1a) < 0 && (iVar15 != 1)))))) {
            ctx->error = 0x1a;
            ctx->error_depth = iVar1;
            ctx->current_cert = pXVar5;
            iVar15 = (*p_Var12)(0,ctx);
            if (iVar15 == 0) goto LAB_000caf4a;
          }
          if (iVar1 < 2) {
LAB_000cb07c:
            uVar14 = pXVar5->ex_flags;
            if (-1 < (int)(uVar14 << 0x1a)) {
LAB_000cae80:
              iVar4 = iVar4 + 1;
            }
          }
          else {
            uVar14 = pXVar5->ex_flags;
            if ((uVar14 & 0x20) == 0) {
              if ((pXVar5->ex_pathlen == -1) || (iVar4 <= pXVar5->ex_pathlen + iVar3 + 1))
              goto LAB_000cae80;
              ctx->error_depth = iVar1;
              ctx->current_cert = pXVar5;
              ctx->error = 0x19;
              iVar15 = (*p_Var12)(0,ctx);
              if (iVar15 != 0) goto LAB_000cb07c;
              goto LAB_000caf4a;
            }
          }
          if ((int)(uVar14 << 0x15) < 0) {
            if ((pXVar5->ex_pcpathlen != -1) && (pXVar5->ex_pcpathlen < iVar1)) {
              ctx->error_depth = iVar1;
              ctx->current_cert = pXVar5;
              ctx->error = 0x26;
              iVar15 = (*p_Var12)(0,ctx);
              if (iVar15 == 0) goto LAB_000caf4a;
            }
            iVar3 = iVar3 + 1;
            iVar15 = 0;
          }
          else {
            iVar15 = 1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < ctx->last_untrusted);
      }
      iVar1 = sk_num((_STACK *)ctx->chain);
      iVar1 = iVar1 + -1;
      if (-1 < iVar1) {
        do {
          pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar1);
          if ((iVar1 == 0) || (-1 < (int)(pXVar5->ex_flags << 0x1a))) {
            iVar15 = sk_num((_STACK *)ctx->chain);
            iVar15 = iVar15 + -1;
            if (iVar1 < iVar15) {
              do {
                pvVar9 = sk_value((_STACK *)ctx->chain,iVar15);
                iVar15 = iVar15 + -1;
                if ((*(NAME_CONSTRAINTS **)((int)pvVar9 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
                   (iVar3 = NAME_CONSTRAINTS_check
                                      (pXVar5,*(NAME_CONSTRAINTS **)((int)pvVar9 + 0x4c)),
                   iVar3 != 0)) {
                  ctx->error = iVar3;
                  ctx->error_depth = iVar1;
                  ctx->current_cert = pXVar5;
                  iVar3 = (*ctx->verify_cb)(0,ctx);
                  if (iVar3 == 0) goto LAB_000caf4a;
                }
              } while (iVar15 != iVar1);
            }
          }
          bVar17 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar17);
      }
      if (0 < pXVar11->trust) {
        p_Var12 = ctx->verify_cb;
        iVar1 = sk_num((_STACK *)ctx->chain);
        pXVar5 = (X509 *)sk_value((_STACK *)ctx->chain,iVar1 + -1);
        iVar15 = X509_check_trust(pXVar5,ctx->param->trust,0);
        if (iVar15 != 1) {
          if (iVar15 == 2) {
            iVar15 = 0x1c;
          }
          else {
            iVar15 = 0x1b;
          }
          ctx->error_depth = iVar1 + -1;
          ctx->error = iVar15;
          ctx->current_cert = pXVar5;
          iVar1 = (*p_Var12)(0,ctx);
          if (iVar1 == 0) goto LAB_000caf4a;
        }
      }
      X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
      iVar1 = (*ctx->check_revocation)(ctx);
      if (iVar1 != 0) {
        if (ctx->verify == (_func_1855 *)0x0) {
          iVar1 = internal_verify();
        }
        else {
          iVar1 = (*ctx->verify)(ctx);
        }
        if ((iVar1 != 0) &&
           (((local_40 != (X509 *)0x0 || (-1 < (int)(ctx->param->flags << 0x18))) ||
            (iVar1 = (*ctx->check_policy)(ctx), iVar1 != 0)))) goto LAB_000caf54;
      }
    }
    else {
      ERR_put_error(0xb,0x7f,0x41,"x509_vfy.c",0xbc);
      pXVar2 = st;
    }
  }
LAB_000caf4a:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,ctx->chain);
  iVar1 = 0;
LAB_000caf54:
  if (st != (X509 *)0x0) {
    sk_free((_STACK *)st);
  }
  if (pXVar2 != (X509 *)0x0) {
    X509_free(pXVar2);
  }
  return iVar1;
}

