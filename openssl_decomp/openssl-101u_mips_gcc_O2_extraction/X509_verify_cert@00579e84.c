
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  stack_st_X509 *psVar4;
  int iVar5;
  X509 *x;
  uint uVar6;
  X509 *pXVar7;
  undefined4 uVar8;
  int iVar9;
  X509_NAME_ENTRY *pXVar10;
  ASN1_OBJECT *pAVar11;
  int iVar12;
  X509_VERIFY_PARAM *pXVar13;
  code *loc;
  undefined4 uVar14;
  X509 *unaff_s1;
  int unaff_s2;
  X509 *unaff_s3;
  X509 *unaff_s5;
  X509 *pXVar15;
  X509 *unaff_s6;
  X509 *unaff_s7;
  uint uVar16;
  ulong uVar17;
  code *pcVar18;
  X509_VERIFY_PARAM *local_48;
  _func_1856 *local_44;
  char *local_40;
  char *local_3c;
  X509 *local_38;
  X509 *local_30;
  X509_ALGOR *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(X509_ALGOR **)PTR___stack_chk_guard_006a9ae8;
  if (ctx->cert == (X509 *)0x0) {
    uVar14 = 0x69;
    uVar8 = 0xa2;
  }
  else {
    if (ctx->chain == (stack_st_X509 *)0x0) {
      local_48 = ctx->param;
      local_44 = ctx->verify_cb;
      psVar4 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
      ctx->chain = psVar4;
      if ((psVar4 != (stack_st_X509 *)0x0) &&
         (iVar5 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,ctx->cert), iVar5 != 0)) {
        local_40 = "encrypt";
        (*(code *)PTR_CRYPTO_add_lock_006a805c)(&ctx->cert->references,1,3,"x509_vfy.c",0xbd);
        ctx->last_untrusted = 1;
        if (ctx->untrusted == (stack_st_X509 *)0x0) {
          unaff_s2 = 0;
        }
        else {
          unaff_s2 = (*(code *)PTR_sk_dup_006a7f54)();
          if (unaff_s2 == 0) {
            uVar8 = 0xc3;
LAB_0057a558:
            iVar5 = -1;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7f,0x41,"x509_vfy.c",uVar8);
            unaff_s3 = (X509 *)0x0;
            ctx->error = 0x11;
            goto LAB_00579f54;
          }
        }
        unaff_s5 = (X509 *)(*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
        pXVar15 = (X509 *)(*(code *)PTR_sk_value_006a6e24)
                                    (ctx->chain,(undefined *)((int)&unaff_s5[-1].aux + 3));
        unaff_s6 = (X509 *)local_48->depth;
        if ((int)unaff_s5 <= (int)unaff_s6) {
          local_3c = "x509_vfy.c";
          do {
            iVar5 = (*ctx->check_issued)(ctx,pXVar15,pXVar15);
            if ((iVar5 != 0) || (ctx->untrusted == (stack_st_X509 *)0x0)) break;
            unaff_s1 = (X509 *)0x0;
            while( true ) {
              iVar5 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2);
              if (iVar5 <= (int)unaff_s1) {
                local_30 = (X509 *)0x0;
                goto LAB_0057a114;
              }
              unaff_s7 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,unaff_s1);
              iVar5 = (*ctx->check_issued)(ctx,pXVar15,unaff_s7);
              if (iVar5 != 0) break;
              unaff_s1 = (X509 *)((int)&unaff_s1->cert_info + 1);
            }
            local_30 = unaff_s7;
            if (unaff_s7 == (X509 *)0x0) break;
            iVar5 = (*(code *)PTR_sk_push_006a6fa8)(ctx->chain,unaff_s7);
            if (iVar5 == 0) {
              uVar8 = 0xde;
              goto LAB_0057a558;
            }
            unaff_s5 = (X509 *)((int)&unaff_s5->cert_info + 1);
            (*(code *)PTR_CRYPTO_add_lock_006a805c)(&local_30->references,1,3,"x509_vfy.c",0xe3);
            (*(code *)PTR_sk_delete_ptr_006a8f00)(unaff_s2,local_30);
            ctx->last_untrusted = ctx->last_untrusted + 1;
            pXVar15 = local_30;
          } while ((int)unaff_s5 <= (int)unaff_s6);
        }
LAB_0057a114:
        unaff_s3 = (X509 *)0x0;
        bVar1 = false;
        unaff_s7 = (X509 *)&local_30;
        local_3c = (char *)unaff_s5;
        goto LAB_0057a120;
      }
      unaff_s2 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7f,0x41,"x509_vfy.c",0xb8);
      iVar5 = -1;
      unaff_s3 = (X509 *)0x0;
      ctx->error = 0x11;
LAB_00579f54:
      psVar4 = ctx->chain;
LAB_00579f58:
      X509_get_pubkey_parameters((EVP_PKEY *)0x0,psVar4);
LAB_00579f64:
      if (unaff_s2 != 0) {
        (*(code *)PTR_sk_free_006a6e80)(unaff_s2);
      }
      if (unaff_s3 != (X509 *)0x0) {
        (*(code *)PTR_X509_free_006a6e90)(unaff_s3);
      }
      if ((iVar5 < 1) && (ctx->error == 0)) {
        ctx->error = 1;
      }
LAB_00579f98:
      if (local_2c == *(X509_ALGOR **)puVar3) {
        return iVar5;
      }
      pcVar18 = (code *)PTR___stack_chk_fail_006a9ab0;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      do {
        (*pcVar18)(local_30);
LAB_0057a7a8:
        do {
          iVar5 = (*local_44)(0,ctx);
          if (iVar5 == 0) goto LAB_00579f54;
          bVar1 = true;
          pXVar15 = unaff_s1;
LAB_0057a1c8:
          do {
            while (((int)unaff_s5 <= (int)unaff_s6 &&
                   (iVar5 = (*ctx->check_issued)(ctx,pXVar15,pXVar15), iVar5 == 0))) {
              iVar5 = (*ctx->get_issuer)((X509 **)unaff_s7,ctx,pXVar15);
              unaff_s1 = local_30;
              if (iVar5 < 0) {
LAB_0057a608:
                ctx->error = 0x42;
                unaff_s1 = pXVar15;
                goto LAB_00579f54;
              }
              if (iVar5 == 0) break;
              iVar5 = (*(code *)PTR_sk_push_006a6fa8)(ctx->chain,local_30);
              if (iVar5 == 0) {
                iVar5 = -1;
                (*(code *)PTR_X509_free_006a6e90)(local_30);
                (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7f,0x41,local_40 + -0x3a58,0x139);
                ctx->error = 0x11;
                goto LAB_00579f54;
              }
              unaff_s5 = (X509 *)((int)&unaff_s5->cert_info + 1);
              pXVar15 = unaff_s1;
            }
            local_38 = (X509 *)ctx->last_untrusted;
            pXVar7 = unaff_s5;
            if ((local_38 != unaff_s5) || (pXVar7 = local_38, (ctx->param->flags & 0x100000) != 0))
            {
LAB_0057a24c:
              local_38 = pXVar7;
              iVar5 = (*ctx->check_issued)(ctx,pXVar15,pXVar15);
              if (iVar5 == 0) {
                if ((unaff_s3 == (X509 *)0x0) ||
                   (iVar5 = (*ctx->check_issued)(ctx,pXVar15,unaff_s3), iVar5 == 0)) {
                  ctx->current_cert = pXVar15;
                  iVar5 = 2;
                  if ((int)local_38 <= ctx->last_untrusted) {
                    iVar5 = 0x14;
                  }
                  ctx->error = iVar5;
                }
                else {
                  pXVar15 = (X509 *)((int)&local_38->cert_info + 1);
                  (*(code *)PTR_sk_push_006a6fa8)(ctx->chain,unaff_s3);
                  ctx->current_cert = unaff_s3;
                  unaff_s3 = (X509 *)0x0;
                  ctx->last_untrusted = (int)pXVar15;
                  ctx->error = 0x13;
                  local_38 = pXVar15;
                }
                ctx->error_depth = (int)((int)&local_38[-1].aux + 3);
                iVar5 = (*local_44)(0,ctx);
                unaff_s1 = pXVar15;
                if (iVar5 == 0) goto LAB_00579f54;
                bVar1 = true;
              }
              local_44 = ctx->verify_cb;
              if (ctx->parent == (X509_STORE_CTX *)0x0) {
                uVar17 = ctx->param->flags;
                iVar5 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_ALLOW_PROXY_CERTS");
                uVar16 = (uVar17 << 0x19) >> 0x1f;
                if (iVar5 != 0) {
                  uVar16 = 1;
                }
                local_38 = (X509 *)ctx->param->purpose;
              }
              else {
                uVar16 = 0;
                local_38 = (X509 *)0x6;
              }
              unaff_s1 = (X509 *)0x0;
              if (ctx->last_untrusted < 1) goto LAB_0057a4a0;
              unaff_s5 = (X509 *)0x0;
              local_3c = (char *)0x0;
              unaff_s6 = (X509 *)0xffffffff;
              goto LAB_0057a310;
            }
            unaff_s5 = (X509 *)((int)&((X509 *)((int)local_3c + -0x70))->aux + 3);
            do {
              local_3c = (char *)unaff_s5;
              unaff_s5 = (X509 *)local_3c;
              if ((int)((int)(X509_CINF **)local_3c + 1) < 2) goto LAB_0057a24c;
              unaff_s5 = (X509 *)((int)&((X509 *)((int)local_3c + -0x70))->aux + 3);
              x = (X509 *)(*(code *)PTR_sk_value_006a6e24)(ctx->chain,unaff_s5);
              iVar5 = (*ctx->get_issuer)((X509 **)unaff_s7,ctx,x);
              if (iVar5 < 0) goto LAB_0057a608;
            } while (iVar5 == 0);
            (*(code *)PTR_X509_free_006a6e90)(local_30);
            unaff_s5 = local_38;
            if ((int)local_3c < (int)local_38) {
              do {
                local_38 = (X509 *)((int)&local_38[-1].aux + 3);
                local_30 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(ctx->chain);
                (*(code *)PTR_X509_free_006a6e90)(local_30);
                unaff_s5 = (X509 *)local_3c;
              } while ((X509 *)local_3c != local_38);
            }
            iVar5 = (*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
            ctx->last_untrusted = iVar5;
LAB_0057a120:
            iVar5 = (*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
            iVar5 = iVar5 + -1;
            unaff_s1 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(ctx->chain,iVar5);
            iVar12 = (*ctx->check_issued)(ctx,unaff_s1,unaff_s1);
            pXVar15 = unaff_s1;
          } while (iVar12 == 0);
          iVar12 = (*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
          if (iVar12 != 1) {
            local_3c = (char *)((int)&((X509 *)((int)local_3c + -0x70))->aux + 3);
            unaff_s3 = (X509 *)(*(code *)PTR_sk_pop_006a8da4)(ctx->chain);
            puVar2 = PTR_sk_value_006a6e24;
            ctx->last_untrusted = ctx->last_untrusted + -1;
            pXVar15 = (X509 *)(*(code *)puVar2)(ctx->chain,(undefined *)((int)&unaff_s5[-1].aux + 2)
                                               );
            unaff_s5 = (X509 *)((int)&unaff_s5[-1].aux + 3);
            goto LAB_0057a1c8;
          }
          iVar12 = (*ctx->get_issuer)((X509 **)unaff_s7,ctx,unaff_s1);
          if (iVar12 < 1) {
            ctx->current_cert = unaff_s1;
            ctx->error_depth = iVar5;
            ctx->error = 0x12;
            goto LAB_0057a7a8;
          }
          iVar9 = X509_cmp(unaff_s1,local_30);
          if (iVar9 == 0) {
            (*(code *)PTR_X509_free_006a6e90)(unaff_s1);
            pXVar15 = local_30;
            (*(code *)PTR_sk_set_006a8358)(ctx->chain,iVar5,local_30);
            ctx->last_untrusted = 0;
            goto LAB_0057a1c8;
          }
          ctx->current_cert = unaff_s1;
          ctx->error_depth = iVar5;
          ctx->error = 0x12;
          pcVar18 = (code *)PTR_X509_free_006a6e90;
        } while (iVar12 != 1);
      } while( true );
    }
    uVar14 = 0x42;
    uVar8 = 0xab;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7f,uVar14,"x509_vfy.c",uVar8);
  iVar5 = -1;
  ctx->error = 0x41;
  goto LAB_00579f98;
LAB_0057a310:
  do {
    unaff_s7 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(ctx->chain,unaff_s1);
    if (((ctx->param->flags & 0x10) == 0) && ((unaff_s7->ex_flags & 0x200) != 0)) {
      ctx->error_depth = (int)unaff_s1;
      ctx->current_cert = unaff_s7;
      ctx->error = 0x22;
      iVar5 = (*local_44)(0,ctx);
      if (iVar5 == 0) goto LAB_0057a5f8;
    }
    if ((uVar16 == 0) && ((unaff_s7->ex_flags & 0x400) != 0)) {
      ctx->error_depth = (int)unaff_s1;
      ctx->current_cert = unaff_s7;
      ctx->error = 0x28;
      iVar5 = (*local_44)(0,ctx);
      if (iVar5 == 0) {
        iVar5 = 0;
        goto LAB_00579f54;
      }
    }
    uVar6 = X509_check_ca(unaff_s7);
    if (unaff_s6 == (X509 *)0xffffffff) {
      pXVar13 = ctx->param;
      if (((pXVar13->flags & 0x20) != 0) && (1 < uVar6)) {
LAB_0057a804:
        ctx->error = 0x18;
        goto LAB_0057a388;
      }
    }
    else {
      if (unaff_s6 == (X509 *)0x0) {
        if (uVar6 != 0) {
          ctx->error = 0x25;
          goto LAB_0057a388;
        }
      }
      else {
        if (uVar6 == 0) goto LAB_0057a804;
        pXVar13 = ctx->param;
        if (((pXVar13->flags & 0x20) == 0) || (uVar6 == 1)) goto LAB_0057a3ac;
        ctx->error = 0x18;
LAB_0057a388:
        ctx->error_depth = (int)unaff_s1;
        ctx->current_cert = unaff_s7;
        iVar5 = (*local_44)(0,ctx);
        if (iVar5 == 0) goto LAB_0057a5f8;
      }
      pXVar13 = ctx->param;
    }
LAB_0057a3ac:
    if ((0 < pXVar13->purpose) &&
       ((iVar5 = X509_check_purpose(unaff_s7,(int)local_38,(uint)(0 < (int)unaff_s6)), iVar5 == 0 ||
        (((ctx->param->flags & 0x20) != 0 && (iVar5 != 1)))))) {
      ctx->error_depth = (int)unaff_s1;
      ctx->current_cert = unaff_s7;
      ctx->error = 0x1a;
      iVar5 = (*local_44)(0,ctx);
      if (iVar5 == 0) goto LAB_0057a5f8;
    }
    if ((int)unaff_s1 < 2) {
LAB_0057a860:
      uVar6 = unaff_s7->ex_flags;
      if ((uVar6 & 0x20) == 0) {
LAB_0057a454:
        local_3c = (char *)((int)(X509_CINF **)local_3c + 1);
      }
    }
    else {
      uVar6 = unaff_s7->ex_flags;
      if ((uVar6 & 0x20) == 0) {
        if ((unaff_s7->ex_pathlen == -1) ||
           ((int)local_3c <= (int)(unaff_s5->sha1_hash + unaff_s7->ex_pathlen + -0x57)))
        goto LAB_0057a454;
        ctx->error_depth = (int)unaff_s1;
        ctx->current_cert = unaff_s7;
        ctx->error = 0x19;
        iVar5 = (*local_44)(0,ctx);
        if (iVar5 != 0) goto LAB_0057a860;
        goto LAB_0057a5f8;
      }
    }
    unaff_s6 = (X509 *)0x1;
    if ((uVar6 & 0x400) != 0) {
      pXVar7 = (X509 *)unaff_s7->ex_pcpathlen;
      pXVar15 = unaff_s5;
      if ((pXVar7 != (X509 *)0xffffffff) && (pXVar15 = pXVar7, (int)pXVar7 < (int)unaff_s5)) {
        ctx->error_depth = (int)unaff_s1;
        ctx->current_cert = unaff_s7;
        ctx->error = 0x26;
        iVar5 = (*local_44)(0,ctx);
        unaff_s5 = pXVar7;
        if (iVar5 == 0) goto LAB_0057a5f8;
        pXVar15 = (X509 *)unaff_s7->ex_pcpathlen;
      }
      unaff_s5 = (X509 *)((int)&pXVar15->cert_info + 1);
      unaff_s6 = (X509 *)0x0;
    }
    unaff_s1 = (X509 *)((int)&unaff_s1->cert_info + 1);
  } while ((int)unaff_s1 < ctx->last_untrusted);
LAB_0057a4a0:
  unaff_s1 = (X509 *)(*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
  while (unaff_s1 = (X509 *)((int)&unaff_s1[-1].aux + 3), -1 < (int)unaff_s1) {
    unaff_s6 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(ctx->chain,unaff_s1);
    if ((unaff_s1 == (X509 *)0x0) || ((unaff_s6->ex_flags & 0x20) == 0)) {
      if ((unaff_s6->ex_flags & 0x400) != 0) {
        unaff_s5 = (X509 *)X509_get_subject_name(unaff_s6);
        unaff_s7 = (X509 *)X509_get_issuer_name(unaff_s6);
        local_44 = (_func_1856 *)X509_NAME_entry_count((X509_NAME *)unaff_s5);
        pcVar18 = local_44 + -1;
        if (0 < (int)pcVar18) {
          local_3c = (char *)X509_NAME_entry_count((X509_NAME *)unaff_s5);
          iVar5 = X509_NAME_entry_count((X509_NAME *)unaff_s7);
          if ((X509 *)local_3c == (X509 *)(iVar5 + 1)) {
            pXVar10 = X509_NAME_get_entry((X509_NAME *)unaff_s5,(int)pcVar18);
            loc = local_44 + -2;
            local_44 = (_func_1856 *)pXVar10->set;
            pXVar10 = X509_NAME_get_entry((X509_NAME *)unaff_s5,(int)loc);
            if (local_44 != (_func_1856 *)pXVar10->set) {
              unaff_s5 = (X509 *)(*(code *)PTR_X509_NAME_dup_006a713c)(unaff_s5);
              if (unaff_s5 == (X509 *)0x0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x6a,0x41,local_40 + -0x3a58,0x2d6);
                ctx->error = 0x11;
                goto LAB_0057a5f8;
              }
              pXVar10 = X509_NAME_delete_entry((X509_NAME *)unaff_s5,(int)pcVar18);
              pAVar11 = X509_NAME_ENTRY_get_object(pXVar10);
              iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar11);
              if ((iVar5 == 0xd) &&
                 (iVar5 = X509_NAME_cmp((X509_NAME *)unaff_s5,(X509_NAME *)unaff_s7), iVar5 == 0)) {
                (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(pXVar10);
                (*(code *)PTR_X509_NAME_free_006a6ff8)(unaff_s5);
                goto LAB_0057aa5c;
              }
              (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(pXVar10);
              (*(code *)PTR_X509_NAME_free_006a6ff8)(unaff_s5);
            }
          }
        }
        ctx->error_depth = (int)unaff_s1;
        ctx->current_cert = unaff_s6;
        ctx->error = 0x43;
        iVar5 = (*ctx->verify_cb)(0,ctx);
        if (iVar5 == 0) goto LAB_0057a5f8;
      }
LAB_0057aa5c:
      unaff_s5 = (X509 *)(*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
      while (unaff_s5 = (X509 *)((int)&unaff_s5[-1].aux + 3), (int)unaff_s1 < (int)unaff_s5) {
        iVar5 = (*(code *)PTR_sk_value_006a6e24)(ctx->chain,unaff_s5);
        if ((*(NAME_CONSTRAINTS **)(iVar5 + 0x4c) != (NAME_CONSTRAINTS *)0x0) &&
           (iVar5 = NAME_CONSTRAINTS_check(unaff_s6,*(NAME_CONSTRAINTS **)(iVar5 + 0x4c)),
           iVar5 != 0)) {
          if (iVar5 == 0x11) {
            ctx->error = 0x11;
            goto LAB_0057a5f8;
          }
          ctx->error = iVar5;
          ctx->error_depth = (int)unaff_s1;
          ctx->current_cert = unaff_s6;
          iVar5 = (*ctx->verify_cb)(0,ctx);
          if (iVar5 == 0) goto LAB_0057a5f8;
        }
      }
    }
  }
  if (0 < local_48->trust) {
    unaff_s1 = (X509 *)ctx->verify_cb;
    iVar5 = (*(code *)PTR_sk_num_006a6e2c)(ctx->chain);
    unaff_s6 = (X509 *)(iVar5 + -1);
    unaff_s5 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(ctx->chain,unaff_s6);
    iVar5 = X509_check_trust(unaff_s5,ctx->param->trust,0);
    if (iVar5 != 1) {
      ctx->error_depth = (int)unaff_s6;
      iVar12 = 0x1c;
      ctx->current_cert = unaff_s5;
      if (iVar5 != 2) {
        iVar12 = 0x1b;
      }
      ctx->error = iVar12;
      iVar5 = (*(code *)unaff_s1)(0,ctx);
      if (iVar5 == 0) {
LAB_0057a5f8:
        iVar5 = 0;
        goto LAB_00579f54;
      }
      psVar4 = ctx->chain;
      goto LAB_0057aaf8;
    }
  }
  psVar4 = ctx->chain;
LAB_0057aaf8:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,psVar4);
  iVar5 = (*ctx->check_revocation)(ctx);
  if (iVar5 == 0) goto LAB_00579f54;
  if (ctx->verify == (_func_1855 *)0x0) {
    iVar5 = internal_verify();
  }
  else {
    iVar5 = (*ctx->verify)(ctx);
  }
  if (iVar5 == 0) goto LAB_00579f54;
  if (((bVar1) || ((ctx->param->flags & 0x80) == 0)) ||
     (iVar5 = (*ctx->check_policy)(ctx), iVar5 != 0)) goto LAB_00579f64;
  psVar4 = ctx->chain;
  goto LAB_00579f58;
}

