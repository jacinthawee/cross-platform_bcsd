
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  X509 *pXVar4;
  int iVar5;
  int iVar6;
  X509 *pXVar7;
  int iVar8;
  int iVar9;
  X509 *pXVar10;
  uint uVar11;
  stack_st_X509 *psVar12;
  int iVar13;
  _func_1856 *p_Var14;
  X509_VERIFY_PARAM *pXVar15;
  X509_STORE_CTX *chain;
  char *in_a3;
  ulong uVar16;
  int iVar17;
  X509_VERIFY_PARAM *pXVar18;
  X509 *pXVar19;
  undefined4 in_stack_ffffffa8;
  char *local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  X509 *local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pXVar18 = ctx->param;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ctx->cert == (X509 *)0x0) {
    pXVar7 = (X509 *)&DAT_00000069;
    in_a3 = "x509_vfy.c";
    in_stack_ffffffa8 = 0xa4;
    chain = (X509_STORE_CTX *)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7f,0x69,"x509_vfy.c",0xa4);
    iVar8 = -1;
    goto LAB_0057d610;
  }
  p_Var14 = ctx->verify_cb;
  if (ctx->chain == (stack_st_X509 *)0x0) {
    psVar12 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
    ctx->chain = psVar12;
    if ((psVar12 != (stack_st_X509 *)0x0) &&
       (iVar8 = (*(code *)PTR_sk_push_006a80a8)(psVar12,ctx->cert), iVar8 != 0)) {
      in_a3 = "x509_vfy.c";
      in_stack_ffffffa8 = 0xb4;
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(&ctx->cert->references,1,3,"x509_vfy.c",0xb4);
      ctx->last_untrusted = 1;
      goto LAB_0057d0bc;
    }
    pXVar7 = (X509 *)&DAT_00000041;
    in_a3 = "x509_vfy.c";
    in_stack_ffffffa8 = 0xb1;
    iVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7f,0x41,"x509_vfy.c",0xb1);
    pXVar19 = (X509 *)0x0;
LAB_0057d5d0:
    chain = (X509_STORE_CTX *)ctx->chain;
LAB_0057d5d4:
    iVar8 = 0;
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,(stack_st_X509 *)chain);
  }
  else {
LAB_0057d0bc:
    if (ctx->untrusted == (stack_st_X509 *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(code *)PTR_sk_dup_006a9074)();
      if (iVar5 == 0) {
        in_stack_ffffffa8 = 0xbc;
LAB_0057d5bc:
        in_a3 = "x509_vfy.c";
        pXVar7 = (X509 *)&DAT_00000041;
        pXVar19 = (X509 *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7f,0x41,"x509_vfy.c",in_stack_ffffffa8);
        goto LAB_0057d5d0;
      }
    }
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
    pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar6 + -1);
    iVar17 = pXVar18->depth;
    if (iVar6 <= iVar17) {
      local_48 = "x509_vfy.c";
      do {
        iVar8 = (*ctx->check_issued)(ctx,pXVar7,pXVar7);
        if ((iVar8 != 0) || (ctx->untrusted == (stack_st_X509 *)0x0)) break;
        iVar8 = 0;
        while( true ) {
          iVar9 = (*(code *)PTR_sk_num_006a7f2c)(iVar5);
          if (iVar9 <= iVar8) {
            local_30 = (X509 *)0x0;
            goto LAB_0057d1a4;
          }
          pXVar19 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(iVar5,iVar8);
          iVar9 = (*ctx->check_issued)(ctx,pXVar7,pXVar19);
          if (iVar9 != 0) break;
          iVar8 = iVar8 + 1;
        }
        local_30 = pXVar19;
        if (pXVar19 == (X509 *)0x0) break;
        iVar8 = (*(code *)PTR_sk_push_006a80a8)(ctx->chain,pXVar19);
        if (iVar8 == 0) {
          in_stack_ffffffa8 = 0xd9;
          goto LAB_0057d5bc;
        }
        in_stack_ffffffa8 = 0xdc;
        iVar6 = iVar6 + 1;
        in_a3 = local_48;
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(&local_30->references,1,3,"x509_vfy.c",0xdc);
        (*(code *)PTR_sk_delete_ptr_006aa020)(iVar5,local_30);
        ctx->last_untrusted = ctx->last_untrusted + 1;
        pXVar7 = local_30;
      } while (iVar6 <= iVar17);
    }
LAB_0057d1a4:
    iVar8 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
    iVar8 = iVar8 + -1;
    pXVar10 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar8);
    iVar9 = (*ctx->check_issued)(ctx,pXVar10,pXVar10);
    if (iVar9 == 0) {
      pXVar19 = (X509 *)0x0;
      bVar1 = false;
    }
    else {
      iVar9 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
      if (iVar9 == 1) {
        pXVar7 = pXVar10;
        iVar9 = (*ctx->get_issuer)(&local_30,ctx,pXVar10);
        if (iVar9 < 1) {
          ctx->current_cert = pXVar10;
          ctx->error_depth = iVar8;
          ctx->error = 0x12;
        }
        else {
          iVar13 = X509_cmp(pXVar10,local_30);
          if (iVar13 == 0) {
            pXVar19 = (X509 *)0x0;
            (*(code *)PTR_X509_free_006a7f90)(pXVar10);
            pXVar10 = local_30;
            (*(code *)PTR_sk_set_006a9478)(ctx->chain,iVar8,local_30);
            bVar1 = false;
            ctx->last_untrusted = 0;
            goto LAB_0057d1ec;
          }
          ctx->current_cert = pXVar10;
          ctx->error_depth = iVar8;
          ctx->error = 0x12;
          if (iVar9 == 1) {
            (*(code *)PTR_X509_free_006a7f90)(local_30);
          }
        }
        iVar8 = (*p_Var14)(0,ctx);
        if (iVar8 == 0) {
          pXVar19 = (X509 *)0x0;
          goto LAB_0057d5d0;
        }
        pXVar19 = (X509 *)0x0;
        bVar1 = true;
      }
      else {
        pXVar19 = (X509 *)(*(code *)PTR_sk_pop_006a9ec4)(ctx->chain);
        puVar2 = PTR_sk_value_006a7f24;
        ctx->last_untrusted = ctx->last_untrusted + -1;
        pXVar10 = (X509 *)(*(code *)puVar2)(ctx->chain,iVar6 + -2);
        bVar1 = false;
        iVar6 = iVar6 + -1;
      }
    }
LAB_0057d1ec:
    if (iVar6 <= iVar17) {
      do {
        iVar8 = (*ctx->check_issued)(ctx,pXVar10,pXVar10);
        if (iVar8 != 0) break;
        chain = ctx;
        pXVar7 = pXVar10;
        iVar8 = (*ctx->get_issuer)(&local_30,ctx,pXVar10);
        pXVar4 = local_30;
        if (iVar8 < 0) goto LAB_0057d610;
        if (iVar8 == 0) break;
        iVar8 = (*(code *)PTR_sk_push_006a80a8)(ctx->chain,local_30);
        if (iVar8 == 0) {
          (*(code *)PTR_X509_free_006a7f90)(local_30);
          pXVar7 = (X509 *)&DAT_00000041;
          in_a3 = "x509_vfy.c";
          in_stack_ffffffa8 = 0x12e;
          chain = (X509_STORE_CTX *)0x7f;
          (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7f,0x41,"x509_vfy.c",0x12e);
          goto LAB_0057d610;
        }
        iVar6 = iVar6 + 1;
        pXVar10 = pXVar4;
      } while (iVar6 <= iVar17);
    }
    pXVar7 = pXVar10;
    iVar8 = (*ctx->check_issued)(ctx,pXVar10,pXVar10);
    if (iVar8 == 0) {
      pXVar7 = pXVar19;
      if ((pXVar19 == (X509 *)0x0) ||
         (iVar8 = (*ctx->check_issued)(ctx,pXVar10,pXVar19), iVar8 == 0)) {
        ctx->current_cert = pXVar10;
        iVar8 = 2;
        if (iVar6 <= ctx->last_untrusted) {
          iVar8 = 0x14;
        }
        ctx->error = iVar8;
      }
      else {
        iVar6 = iVar6 + 1;
        (*(code *)PTR_sk_push_006a80a8)(ctx->chain,pXVar19);
        ctx->current_cert = pXVar19;
        pXVar19 = (X509 *)0x0;
        ctx->last_untrusted = iVar6;
        ctx->error = 0x13;
      }
      ctx->error_depth = iVar6 + -1;
      iVar8 = (*p_Var14)(0,ctx);
      if (iVar8 == 0) goto LAB_0057d5d0;
      bVar1 = true;
    }
    p_Var14 = ctx->verify_cb;
    if (ctx->parent == (X509_STORE_CTX *)0x0) {
      uVar16 = ctx->param->flags;
      iVar8 = (*(code *)PTR_getenv_006aab6c)("OPENSSL_ALLOW_PROXY_CERTS");
      if (iVar8 == 0) {
        local_3c = (uVar16 << 0x19) >> 0x1f;
      }
      else {
        local_3c = 1;
      }
      local_38 = ctx->param->purpose;
    }
    else {
      local_3c = 0;
      local_38 = 6;
    }
    iVar8 = 0;
    if (0 < ctx->last_untrusted) {
      iVar6 = -1;
      local_40 = 0;
      local_44 = 0;
      do {
        pXVar10 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar8);
        if (((ctx->param->flags & 0x10) == 0) && ((pXVar10->ex_flags & 0x200) != 0)) {
          ctx->error_depth = iVar8;
          ctx->current_cert = pXVar10;
          ctx->error = 0x22;
          iVar17 = (*p_Var14)(0,ctx);
          if (iVar17 == 0) {
            chain = (X509_STORE_CTX *)ctx->chain;
            goto LAB_0057d5d4;
          }
        }
        if ((local_3c == 0) && ((pXVar10->ex_flags & 0x400) != 0)) {
          ctx->error_depth = iVar8;
          ctx->current_cert = pXVar10;
          ctx->error = 0x28;
          iVar17 = (*p_Var14)(0,ctx);
          if (iVar17 == 0) {
            chain = (X509_STORE_CTX *)ctx->chain;
            goto LAB_0057d5d4;
          }
        }
        uVar11 = X509_check_ca(pXVar10);
        if (iVar6 == -1) {
          pXVar15 = ctx->param;
          if (((pXVar15->flags & 0x20) != 0) && (1 < uVar11)) {
            ctx->error = 0x18;
            goto LAB_0057d398;
          }
        }
        else {
          if (iVar6 == 0) {
            if (uVar11 != 0) {
              ctx->error = 0x25;
              goto LAB_0057d398;
            }
          }
          else {
            if ((uVar11 != 0) &&
               ((pXVar15 = ctx->param, (pXVar15->flags & 0x20) == 0 || (uVar11 == 1))))
            goto LAB_0057d3bc;
            ctx->error = 0x18;
LAB_0057d398:
            ctx->error_depth = iVar8;
            ctx->current_cert = pXVar10;
            iVar17 = (*p_Var14)(0,ctx);
            if (iVar17 == 0) goto LAB_0057d5d0;
          }
          pXVar15 = ctx->param;
        }
LAB_0057d3bc:
        if (0 < pXVar15->purpose) {
          pXVar7 = (X509 *)(uint)(0 < iVar6);
          iVar6 = X509_check_purpose(pXVar10,local_38,(int)pXVar7);
          if ((iVar6 == 0) || (((ctx->param->flags & 0x20) != 0 && (iVar6 != 1)))) {
            ctx->error_depth = iVar8;
            ctx->current_cert = pXVar10;
            ctx->error = 0x1a;
            iVar6 = (*p_Var14)(0,ctx);
            if (iVar6 == 0) goto LAB_0057d5d0;
          }
        }
        if (iVar8 < 2) {
LAB_0057d7f0:
          uVar11 = pXVar10->ex_flags;
          if ((uVar11 & 0x20) == 0) {
LAB_0057d464:
            local_40 = local_40 + 1;
          }
        }
        else {
          uVar11 = pXVar10->ex_flags;
          if ((uVar11 & 0x20) == 0) {
            if ((pXVar10->ex_pathlen == -1) || (local_40 <= local_44 + pXVar10->ex_pathlen + 1))
            goto LAB_0057d464;
            ctx->error_depth = iVar8;
            ctx->current_cert = pXVar10;
            ctx->error = 0x19;
            iVar6 = (*p_Var14)(0,ctx);
            if (iVar6 != 0) goto LAB_0057d7f0;
            goto LAB_0057d5d0;
          }
        }
        iVar6 = 1;
        if ((uVar11 & 0x400) != 0) {
          if ((pXVar10->ex_pcpathlen != -1) && (pXVar10->ex_pcpathlen < iVar8)) {
            ctx->error_depth = iVar8;
            ctx->current_cert = pXVar10;
            ctx->error = 0x26;
            iVar6 = (*p_Var14)(0,ctx);
            if (iVar6 == 0) {
              chain = (X509_STORE_CTX *)ctx->chain;
              goto LAB_0057d5d4;
            }
          }
          iVar6 = 0;
          local_44 = local_44 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < ctx->last_untrusted);
    }
    iVar8 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
    iVar8 = iVar8 + -1;
    if (-1 < iVar8) {
      do {
        pXVar10 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar8);
        if (iVar8 == 0) {
          iVar6 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
          iVar6 = iVar6 + -1;
          if (0 < iVar6) goto LAB_0057d52c;
          iVar8 = pXVar18->trust;
          goto LAB_0057d8f0;
        }
        if ((pXVar10->ex_flags & 0x20) == 0) {
          iVar6 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
          while (iVar6 = iVar6 + -1, iVar8 < iVar6) {
LAB_0057d52c:
            iVar17 = (*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar6);
            if ((*(NAME_CONSTRAINTS **)(iVar17 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
               (iVar17 = NAME_CONSTRAINTS_check(pXVar10,*(NAME_CONSTRAINTS **)(iVar17 + 0x4c)),
               iVar17 != 0)) {
              ctx->error = iVar17;
              ctx->error_depth = iVar8;
              ctx->current_cert = pXVar10;
              iVar17 = (*ctx->verify_cb)(0,ctx);
              if (iVar17 == 0) {
                chain = (X509_STORE_CTX *)ctx->chain;
                goto LAB_0057d5d4;
              }
            }
          }
        }
        iVar8 = iVar8 + -1;
      } while (iVar8 != -1);
    }
    iVar8 = pXVar18->trust;
LAB_0057d8f0:
    if (0 < iVar8) {
      p_Var14 = ctx->verify_cb;
      iVar8 = (*(code *)PTR_sk_num_006a7f2c)(ctx->chain);
      pXVar10 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ctx->chain,iVar8 + -1);
      pXVar7 = (X509 *)0x0;
      iVar6 = X509_check_trust(pXVar10,ctx->param->trust,0);
      if (iVar6 != 1) {
        ctx->error_depth = iVar8 + -1;
        iVar8 = 0x1c;
        ctx->current_cert = pXVar10;
        if (iVar6 != 2) {
          iVar8 = 0x1b;
        }
        ctx->error = iVar8;
        iVar8 = (*p_Var14)(0,ctx);
        if (iVar8 == 0) goto LAB_0057d5d0;
      }
    }
    chain = (X509_STORE_CTX *)ctx->chain;
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,(stack_st_X509 *)chain);
    iVar8 = (*ctx->check_revocation)(ctx);
    if (iVar8 == 0) goto LAB_0057d5d0;
    if (ctx->verify == (_func_1855 *)0x0) {
      iVar8 = internal_verify();
    }
    else {
      iVar8 = (*ctx->verify)(ctx);
    }
    if (iVar8 == 0) goto LAB_0057d5d0;
    if (((!bVar1) && ((ctx->param->flags & 0x80) != 0)) &&
       (iVar8 = (*ctx->check_policy)(ctx), iVar8 == 0)) {
      chain = (X509_STORE_CTX *)ctx->chain;
      goto LAB_0057d5d4;
    }
  }
  if (iVar5 != 0) {
    (*(code *)PTR_sk_free_006a7f80)(iVar5);
  }
  if (pXVar19 != (X509 *)0x0) {
    (*(code *)PTR_X509_free_006a7f90)(pXVar19);
  }
LAB_0057d610:
  if (local_2c != *(int *)puVar3) {
    iVar8 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar8 = (*(code *)PTR_CRYPTO_get_ex_new_index_006a947c)
                      (5,iVar8,chain,pXVar7,in_a3,in_stack_ffffffa8,&_gp);
    return iVar8;
  }
  return iVar8;
}

