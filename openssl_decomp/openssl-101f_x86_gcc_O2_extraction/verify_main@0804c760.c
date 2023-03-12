
int verify_main(int param_1,byte **param_2)

{
  X509_STORE *ctx;
  int iVar1;
  X509_PURPOSE *xp;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  X509_LOOKUP_METHOD *pXVar6;
  X509_LOOKUP *pXVar7;
  int iVar8;
  BIO_METHOD *type;
  byte **ppbVar9;
  byte *argc;
  _STACK *st;
  byte *pbVar10;
  byte *pbVar11;
  _STACK *st_00;
  byte *pbVar12;
  int in_GS_OFFSET;
  bool bVar13;
  bool bVar14;
  byte bVar15;
  _STACK *local_4c;
  byte *local_44;
  byte *local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  byte **local_30 [2];
  int local_28;
  X509_VERIFY_PARAM *local_24;
  int local_20;
  
  bVar15 = 0;
  local_28 = 0;
  local_24 = (X509_VERIFY_PARAM *)0x0;
  local_30[0] = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = X509_STORE_new();
  if (ctx != (X509_STORE *)0x0) {
    X509_STORE_set_verify_cb(ctx,cb);
    ERR_load_crypto_strings();
    signal(0xd,(__sighandler_t)0x1);
    if (bio_err == (BIO *)0x0) {
      type = BIO_s_file();
      bio_err = BIO_new(type);
      if (bio_err != (BIO *)0x0) {
        BIO_ctrl(bio_err,0x6a,0x10,stderr);
      }
    }
    iVar1 = load_config(bio_err,0);
    if (iVar1 != 0) {
      local_30[0] = local_30[0] + 1;
      argc = (byte *)0x0;
      local_3c = (byte *)0x0;
      local_34 = (byte *)0x0;
      local_38 = (byte *)0x0;
      local_40 = (byte *)0x0;
      param_1 = param_1 + -1;
      local_44 = (byte *)0x0;
LAB_0804c837:
      while( true ) {
        bVar13 = false;
        bVar14 = param_1 == 0;
        if (param_1 < 1) break;
        iVar1 = 8;
        pbVar10 = *local_30[0];
        pbVar11 = (byte *)"-CApath";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar13 = *pbVar10 < *pbVar11;
          bVar14 = *pbVar10 == *pbVar11;
          pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        bVar13 = (!bVar13 && !bVar14) == bVar13;
        if (bVar13) {
          argc = local_30[0][1];
          ppbVar9 = local_30[0] + 1;
          iVar1 = param_1 + -1;
        }
        else {
          iVar1 = 8;
          pbVar10 = *local_30[0];
          pbVar11 = (byte *)"-CAfile";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar13 = *pbVar10 == *pbVar11;
            pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
          } while (bVar13);
          if (bVar13) {
            local_44 = local_30[0][1];
            ppbVar9 = local_30[0] + 1;
            iVar1 = param_1 + -1;
            goto LAB_0804c829;
          }
          iVar1 = args_verify(local_30,&param_1,&local_28,bio_err,&local_24);
          bVar13 = iVar1 == 0;
          if (!bVar13) goto code_r0x0804c8b5;
          iVar1 = 0xb;
          pbVar10 = *local_30[0];
          pbVar11 = pbVar10;
          pbVar12 = (byte *)"-untrusted";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar13 = *pbVar11 == *pbVar12;
            pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
            pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
          } while (bVar13);
          if (bVar13) {
            iVar1 = param_1 + -1;
            bVar13 = param_1 < 1;
            param_1 = iVar1;
            if (bVar13) goto LAB_0804c8c1;
            ppbVar9 = local_30[0] + 1;
            local_40 = local_30[0][1];
          }
          else {
            iVar1 = 9;
            pbVar11 = pbVar10;
            pbVar12 = (byte *)"-trusted";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar13 = *pbVar11 == *pbVar12;
              pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
              pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              iVar1 = param_1 + -1;
              bVar13 = param_1 < 1;
              param_1 = iVar1;
              if (bVar13) goto LAB_0804c8c1;
              local_38 = local_30[0][1];
              ppbVar9 = local_30[0] + 1;
            }
            else {
              iVar1 = 9;
              pbVar11 = pbVar10;
              pbVar12 = (byte *)"-CRLfile";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar13 = *pbVar11 == *pbVar12;
                pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
                pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
              } while (bVar13);
              if (bVar13) {
                iVar1 = param_1 + -1;
                bVar13 = param_1 < 1;
                param_1 = iVar1;
                if (bVar13) goto LAB_0804c8c1;
                ppbVar9 = local_30[0] + 1;
                local_34 = local_30[0][1];
              }
              else {
                iVar1 = 8;
                pbVar11 = pbVar10;
                pbVar12 = (byte *)"-engine";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar13 = *pbVar11 == *pbVar12;
                  pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
                  pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
                } while (bVar13);
                if (bVar13) {
                  param_1 = param_1 + -1;
                  if (0 < param_1) {
                    local_3c = local_30[0][1];
                    ppbVar9 = local_30[0] + 1;
                    iVar1 = param_1;
                    goto LAB_0804c829;
                  }
                  goto LAB_0804c8c1;
                }
                iVar1 = 6;
                pbVar11 = pbVar10;
                pbVar12 = (byte *)"-help";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar13 = *pbVar11 == *pbVar12;
                  pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
                  pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
                } while (bVar13);
                if (bVar13) goto LAB_0804c8c1;
                iVar1 = 9;
                pbVar11 = pbVar10;
                pbVar12 = (byte *)"-verbose";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar13 = *pbVar11 == *pbVar12;
                  pbVar11 = pbVar11 + (uint)bVar15 * -2 + 1;
                  pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
                } while (bVar13);
                if (!bVar13) {
                  if (*pbVar10 != 0x2d) break;
                  goto LAB_0804c8c1;
                }
                v_verbose = 1;
                ppbVar9 = local_30[0];
                iVar1 = param_1;
              }
            }
          }
        }
LAB_0804c829:
        param_1 = iVar1 + -1;
        local_30[0] = ppbVar9 + 1;
      }
      uVar5 = setup_engine(bio_err,local_3c,0);
      if (local_24 != (X509_VERIFY_PARAM *)0x0) {
        X509_STORE_set1_param(ctx,local_24);
      }
      pXVar6 = X509_LOOKUP_file();
      pXVar7 = X509_STORE_add_lookup(ctx,pXVar6);
      if (pXVar7 == (X509_LOOKUP *)0x0) goto LAB_0804ce29;
      if (local_44 != (byte *)0x0) {
        iVar1 = X509_LOOKUP_ctrl(pXVar7,1,(char *)local_44,1,(char **)0x0);
        if (iVar1 != 0) goto LAB_0804cb47;
        pcVar2 = "Error loading file %s\n";
LAB_0804ccf9:
        st_00 = (_STACK *)0x0;
        BIO_printf(bio_err,pcVar2,local_44);
        ERR_print_errors(bio_err);
        local_4c = (_STACK *)0x0;
        goto LAB_0804c8ca;
      }
      X509_LOOKUP_ctrl(pXVar7,1,(char *)0x0,3,(char **)0x0);
LAB_0804cb47:
      pXVar6 = X509_LOOKUP_hash_dir();
      pXVar7 = X509_STORE_add_lookup(ctx,pXVar6);
      if (pXVar7 == (X509_LOOKUP *)0x0) {
LAB_0804ce29:
                    /* WARNING: Subroutine does not return */
        abort();
      }
      if (argc == (byte *)0x0) {
        X509_LOOKUP_ctrl(pXVar7,2,(char *)0x0,3,(char **)0x0);
      }
      else {
        iVar1 = X509_LOOKUP_ctrl(pXVar7,2,(char *)argc,1,(char **)0x0);
        if (iVar1 == 0) {
          pcVar2 = "Error loading directory %s\n";
          local_44 = argc;
          goto LAB_0804ccf9;
        }
      }
      ERR_clear_error();
      if (local_40 == (byte *)0x0) {
        local_4c = (_STACK *)0x0;
      }
      else {
        local_4c = (_STACK *)load_certs(bio_err,local_40,3,0,uVar5,"untrusted certificates");
        if (local_4c == (_STACK *)0x0) goto LAB_0804c8c1;
      }
      if (local_38 == (byte *)0x0) {
        st_00 = (_STACK *)0x0;
      }
      else {
        st_00 = (_STACK *)load_certs(bio_err,local_38,3,0,uVar5,"trusted certificates");
        if (st_00 == (_STACK *)0x0) goto LAB_0804c8ca;
      }
      if (local_34 == (byte *)0x0) {
        st = (_STACK *)0x0;
      }
      else {
        st = (_STACK *)load_crls(bio_err,local_34,3,0,uVar5,"other CRLs");
        if (st == (_STACK *)0x0) goto LAB_0804c8ca;
      }
      if (param_1 < 1) {
        iVar1 = check(st_00,st,uVar5);
        iVar1 = -(uint)(iVar1 != 1);
      }
      else {
        iVar1 = 0;
        iVar4 = 0;
        do {
          iVar8 = check(st_00,st,uVar5);
          if (iVar8 != 1) {
            iVar1 = -1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_1);
      }
      if (local_24 != (X509_VERIFY_PARAM *)0x0) goto LAB_0804c981;
      goto LAB_0804c995;
    }
  }
LAB_0804c8c1:
  st_00 = (_STACK *)0x0;
  local_4c = (_STACK *)0x0;
LAB_0804c8ca:
  BIO_printf(bio_err,
             "usage: verify [-verbose] [-CApath path] [-CAfile file] [-purpose purpose] [-crl_check]"
            );
  BIO_printf(bio_err," [-attime timestamp]");
  BIO_printf(bio_err," [-engine e]");
  BIO_printf(bio_err," cert1 cert2 ...\n");
  BIO_printf(bio_err,"recognized usages:\n");
  for (iVar1 = 0; iVar4 = X509_PURPOSE_get_count(), iVar1 < iVar4; iVar1 = iVar1 + 1) {
    xp = X509_PURPOSE_get0(iVar1);
    pcVar2 = X509_PURPOSE_get0_name(xp);
    pcVar3 = X509_PURPOSE_get0_sname(xp);
    BIO_printf(bio_err,"\t%-10s\t%s\n",pcVar3,pcVar2);
  }
  st = (_STACK *)0x0;
  iVar1 = 1;
  if (local_24 == (X509_VERIFY_PARAM *)0x0) {
    if (ctx != (X509_STORE *)0x0) {
LAB_0804c995:
      X509_STORE_free(ctx);
      goto LAB_0804c9a4;
    }
    sk_pop_free(local_4c,X509_free);
    sk_pop_free(st_00,X509_free);
    sk_pop_free((_STACK *)0x0,X509_CRL_free);
  }
  else {
LAB_0804c981:
    X509_VERIFY_PARAM_free(local_24);
    if (ctx != (X509_STORE *)0x0) goto LAB_0804c995;
LAB_0804c9a4:
    sk_pop_free(local_4c,X509_free);
    sk_pop_free(st_00,X509_free);
    sk_pop_free(st,X509_CRL_free);
    iVar4 = 2;
    if (iVar1 == -1) goto LAB_0804c9de;
  }
  iVar4 = iVar1;
LAB_0804c9de:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
code_r0x0804c8b5:
  if (local_28 != 0) goto LAB_0804c8c1;
  goto LAB_0804c837;
}

