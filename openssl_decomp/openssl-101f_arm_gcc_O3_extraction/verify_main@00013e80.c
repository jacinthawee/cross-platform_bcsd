
void verify_main(int param_1,char **param_2)

{
  bool bVar1;
  BIO *bio;
  X509_STORE *ctx;
  int iVar2;
  int iVar3;
  X509_PURPOSE *xp;
  undefined4 uVar4;
  X509_LOOKUP_METHOD *pXVar5;
  X509_LOOKUP *pXVar6;
  _STACK *p_Var7;
  BIO_METHOD *type;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char **ppcVar11;
  char *pcVar12;
  _STACK *local_44;
  _STACK *local_40;
  _STACK *local_3c;
  char **local_38;
  int local_34;
  int local_30;
  X509_VERIFY_PARAM *local_2c [2];
  
  local_30 = 0;
  local_2c[0] = (X509_VERIFY_PARAM *)0x0;
  local_38 = param_2;
  local_34 = param_1;
  ctx = X509_STORE_new();
  if (ctx != (X509_STORE *)0x0) {
    X509_STORE_set_verify_cb(ctx,cb + 1);
    ERR_load_crypto_strings();
    signal(0xd,(__sighandler_t)0x1);
    if (bio_err == (BIO *)0x0) {
      type = BIO_s_file();
      bio_err = BIO_new(type);
      if (bio_err != (BIO *)0x0) {
        BIO_ctrl(bio_err,0x6a,0x10,stderr);
      }
    }
    iVar2 = load_config(bio_err,0);
    if (iVar2 != 0) {
      pcVar10 = (char *)0x0;
      pcVar9 = (char *)0x0;
      local_34 = local_34 + -1;
      local_3c = (_STACK *)0x0;
      local_38 = local_38 + 1;
      local_40 = (_STACK *)0x0;
      pcVar8 = (char *)0x0;
      local_44 = (_STACK *)0x0;
LAB_00013f10:
      iVar2 = local_34;
      ppcVar11 = local_38;
      if (local_34 < 1) {
LAB_000140b0:
        uVar4 = setup_engine(bio_err,pcVar10,0);
        if (local_2c[0] != (X509_VERIFY_PARAM *)0x0) {
          X509_STORE_set1_param(ctx,local_2c[0]);
        }
        pXVar5 = X509_LOOKUP_file();
        pXVar6 = X509_STORE_add_lookup(ctx,pXVar5);
        if (pXVar6 != (X509_LOOKUP *)0x0) {
          if (pcVar9 == (char *)0x0) {
            X509_LOOKUP_ctrl(pXVar6,1,(char *)0x0,3,(char **)0x0);
          }
          else {
            p_Var7 = (_STACK *)X509_LOOKUP_ctrl(pXVar6,1,pcVar9,1,(char **)0x0);
            if (p_Var7 == (_STACK *)0x0) {
              BIO_printf(bio_err,"Error loading file %s\n",pcVar9);
              ERR_print_errors(bio_err);
              local_44 = p_Var7;
              goto LAB_00013f70;
            }
          }
          pXVar5 = X509_LOOKUP_hash_dir();
          pXVar6 = X509_STORE_add_lookup(ctx,pXVar5);
          if (pXVar6 != (X509_LOOKUP *)0x0) {
            if (pcVar8 == (char *)0x0) {
              X509_LOOKUP_ctrl(pXVar6,2,(char *)0x0,3,(char **)0x0);
            }
            else {
              p_Var7 = (_STACK *)X509_LOOKUP_ctrl(pXVar6,2,pcVar8,1,(char **)0x0);
              if (p_Var7 == (_STACK *)0x0) {
                BIO_printf(bio_err,"Error loading directory %s\n",pcVar8);
                ERR_print_errors(bio_err);
                local_44 = p_Var7;
                goto LAB_00013f70;
              }
            }
            ERR_clear_error();
            if ((local_44 == (_STACK *)0x0) ||
               (local_44 = (_STACK *)load_certs(bio_err,local_44,3,0,uVar4,"untrusted certificates")
               , local_44 != (_STACK *)0x0)) {
              if (((local_40 != (_STACK *)0x0) &&
                  (local_40 = (_STACK *)
                              load_certs(bio_err,local_40,3,0,uVar4,"trusted certificates"),
                  p_Var7 = local_40, local_40 == (_STACK *)0x0)) ||
                 ((local_3c != (_STACK *)0x0 &&
                  (local_3c = (_STACK *)load_crls(bio_err,local_3c,3,0,uVar4,"other CRLs"),
                  p_Var7 = local_40, local_3c == (_STACK *)0x0)))) goto LAB_00013f70;
              if (local_34 < 1) {
                check(ctx,0,local_44,local_40,local_3c,uVar4);
              }
              else {
                iVar2 = 0;
                do {
                  ppcVar11 = local_38 + iVar2;
                  iVar2 = iVar2 + 1;
                  check(ctx,*ppcVar11,local_44,local_40,local_3c,uVar4);
                } while (iVar2 < local_34);
              }
              goto LAB_00013ff2;
            }
            goto LAB_00013f6c;
          }
        }
                    /* WARNING: Subroutine does not return */
        abort();
      }
      pcVar12 = *local_38;
      iVar3 = strcmp(pcVar12,"-CApath");
      if (iVar3 == 0) {
        pcVar8 = ppcVar11[1];
        iVar2 = iVar2 + -1;
        ppcVar11 = ppcVar11 + 1;
      }
      else {
        iVar3 = strcmp(pcVar12,"-CAfile");
        if (iVar3 == 0) {
          pcVar9 = ppcVar11[1];
          ppcVar11 = ppcVar11 + 1;
          iVar2 = iVar2 + -1;
          goto LAB_00013f04;
        }
        iVar2 = args_verify(&local_38,&local_34,&local_30,bio_err,local_2c);
        ppcVar11 = local_38;
        if (iVar2 != 0) {
          if (local_30 != 0) goto LAB_00013f6c;
          goto LAB_00013f10;
        }
        pcVar12 = *local_38;
        iVar2 = strcmp(pcVar12,"-untrusted");
        if (iVar2 == 0) {
          iVar2 = local_34 + -1;
          bVar1 = local_34 < 1;
          local_34 = iVar2;
          if (bVar1) goto LAB_00013f6c;
          local_44 = (_STACK *)ppcVar11[1];
          ppcVar11 = ppcVar11 + 1;
        }
        else {
          iVar2 = strcmp(pcVar12,"-trusted");
          if (iVar2 == 0) {
            iVar2 = local_34 + -1;
            bVar1 = local_34 < 1;
            local_34 = iVar2;
            if (bVar1) goto LAB_00013f6c;
            local_40 = (_STACK *)ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
          }
          else {
            iVar2 = strcmp(pcVar12,"-CRLfile");
            if (iVar2 == 0) {
              iVar2 = local_34 + -1;
              bVar1 = local_34 < 1;
              local_34 = iVar2;
              if (bVar1) goto LAB_00013f6c;
              local_3c = (_STACK *)ppcVar11[1];
              ppcVar11 = ppcVar11 + 1;
            }
            else {
              iVar2 = strcmp(pcVar12,"-engine");
              if (iVar2 == 0) {
                local_34 = local_34 + -1;
                if (0 < local_34) {
                  pcVar10 = ppcVar11[1];
                  ppcVar11 = ppcVar11 + 1;
                  iVar2 = local_34;
                  goto LAB_00013f04;
                }
                goto LAB_00013f6c;
              }
              iVar2 = strcmp(pcVar12,"-help");
              if (iVar2 == 0) goto LAB_00013f6c;
              iVar2 = strcmp(pcVar12,"-verbose");
              if (iVar2 != 0) {
                if (*pcVar12 != '-') goto LAB_000140b0;
                goto LAB_00013f6c;
              }
              v_verbose = 1;
              iVar2 = local_34;
            }
          }
        }
      }
LAB_00013f04:
      local_34 = iVar2 + -1;
      local_38 = ppcVar11 + 1;
      goto LAB_00013f10;
    }
  }
LAB_00013f6c:
  p_Var7 = (_STACK *)0x0;
  local_44 = (_STACK *)0x0;
LAB_00013f70:
  BIO_printf(bio_err,
             "usage: verify [-verbose] [-CApath path] [-CAfile file] [-purpose purpose] [-crl_check]"
            );
  BIO_printf(bio_err," [-attime timestamp]");
  BIO_printf(bio_err," [-engine e]");
  BIO_printf(bio_err," cert1 cert2 ...\n");
  BIO_printf(bio_err,"recognized usages:\n");
  for (iVar2 = 0; iVar3 = X509_PURPOSE_get_count(), iVar2 < iVar3; iVar2 = iVar2 + 1) {
    xp = X509_PURPOSE_get0(iVar2);
    bio = bio_err;
    pcVar8 = X509_PURPOSE_get0_sname(xp);
    pcVar9 = X509_PURPOSE_get0_name(xp);
    BIO_printf(bio,"\t%-10s\t%s\n",pcVar8,pcVar9);
  }
  local_3c = (_STACK *)0x0;
  local_40 = p_Var7;
LAB_00013ff2:
  if (local_2c[0] != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_2c[0]);
  }
  if (ctx != (X509_STORE *)0x0) {
    X509_STORE_free(ctx);
  }
  sk_pop_free(local_44,X509_free + 1);
  sk_pop_free(local_40,X509_free + 1);
  sk_pop_free(local_3c,X509_CRL_free + 1);
  return;
}

