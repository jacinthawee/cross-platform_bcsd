
int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  stack_st_CONF_VALUE *psVar4;
  int iVar5;
  int iVar6;
  _func_3660 *p_Var7;
  _func_3661 *p_Var8;
  CONF_METHOD *pCVar9;
  _func_3659 *p_Var10;
  CONF *conf;
  void *pvVar11;
  lhash_st_CONF_VALUE *plVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 uVar15;
  CONF *pCVar16;
  int iVar17;
  char *flags_00;
  int iVar18;
  char *pcVar19;
  CONF *local_64;
  undefined auStack_3c [16];
  char *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  flags_00 = (char *)flags;
  if (cnf == (CONF *)0x0) {
LAB_0059d4cc:
    iVar5 = 1;
  }
  else {
    if (appname == (char *)0x0) {
LAB_0059d920:
      pCVar16 = (CONF *)0x0;
      flags_00 = "openssl_conf";
      appname = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
      if ((CONF *)appname == (CONF *)0x0) {
LAB_0059d944:
        appname = (char *)pCVar16;
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        goto LAB_0059d4cc;
      }
    }
    else {
      pCVar16 = (CONF *)0x0;
      flags_00 = appname;
      appname = NCONF_get_string(cnf,(char *)0x0,appname);
      if ((CONF *)appname == (CONF *)0x0) {
        if ((flags & 0x20) != 0) goto LAB_0059d920;
        goto LAB_0059d944;
      }
    }
    psVar4 = NCONF_get_section(cnf,appname);
    if (psVar4 != (stack_st_CONF_VALUE *)0x0) {
      iVar18 = 0;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
      if (0 < iVar5) {
        do {
          iVar5 = (*(code *)PTR_sk_value_006a6e24)(psVar4,iVar18);
          appname = (char *)0x2e;
          flags_00 = *(char **)(iVar5 + 4);
          pcVar19 = *(char **)(iVar5 + 8);
          iVar5 = (*(code *)PTR_strrchr_006a99ac)(flags_00);
          if (iVar5 == 0) {
            iVar5 = (*(code *)PTR_strlen_006a9a24)(flags_00);
          }
          else {
            iVar5 = iVar5 - (int)flags_00;
          }
          for (iVar17 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(supported_modules), iVar17 < iVar6
              ; iVar17 = iVar17 + 1) {
            pCVar9 = (CONF_METHOD *)(*(code *)PTR_sk_value_006a6e24)(supported_modules,iVar17);
            appname = flags_00;
            iVar6 = (*(code *)PTR_strncmp_006a9970)(pCVar9->create,flags_00,iVar5);
            if (iVar6 == 0) goto LAB_0059d6d0;
          }
          pCVar16 = (CONF *)0x680000;
          if ((flags & 8) == 0) {
            local_64 = (CONF *)NCONF_get_string(cnf,pcVar19,"path");
            if (local_64 == (CONF *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              local_64 = (CONF *)flags_00;
            }
            pcVar14 = (char *)(*(code *)PTR_DSO_load_006a8884)(0,local_64,0,0);
            if (pcVar14 == (char *)0x0) {
              uVar15 = 0x6e;
LAB_0059d624:
              (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x75,uVar15,"conf_mod.c",0x10f);
              appname = "module=";
              pCVar16 = (CONF *)flags_00;
              (*(code *)PTR_ERR_add_error_data_006a813c)(4,"module=",flags_00,", path=",local_64);
              goto joined_r0x0059d670;
            }
            p_Var7 = (_func_3660 *)(*(code *)PTR_DSO_bind_func_006a888c)(pcVar14,"OPENSSL_init");
            if (p_Var7 == (_func_3660 *)0x0) {
              uVar15 = 0x70;
LAB_0059d614:
              (*(code *)PTR_DSO_free_006a8874)(pcVar14);
              goto LAB_0059d624;
            }
            p_Var8 = (_func_3661 *)(*(code *)PTR_DSO_bind_func_006a888c)(pcVar14,"OPENSSL_finish");
            if (((supported_modules == 0) &&
                (supported_modules = (*(code *)PTR_sk_new_null_006a6fa4)(), supported_modules == 0))
               || (pCVar9 = (CONF_METHOD *)
                            (*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"conf_mod.c",0x11d),
                  puVar2 = PTR_BUF_strdup_006a6fdc, pCVar9 == (CONF_METHOD *)0x0)) {
LAB_0059d610:
              uVar15 = 0;
              goto LAB_0059d614;
            }
            pCVar9->name = pcVar14;
            p_Var10 = (_func_3659 *)(*(code *)puVar2)(flags_00);
            pCVar9->create = p_Var10;
            iVar5 = supported_modules;
            puVar2 = PTR_sk_push_006a6fa8;
            pCVar9->destroy_data = (_func_3662 *)0x0;
            pCVar9->init = p_Var7;
            pCVar9->destroy = p_Var8;
            iVar5 = (*(code *)puVar2)(iVar5,pCVar9);
            if (iVar5 == 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(pCVar9);
              goto LAB_0059d610;
            }
LAB_0059d6d0:
            pCVar16 = (CONF *)0x154;
            appname = "conf_mod.c";
            conf = (CONF *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14);
            puVar2 = PTR_BUF_strdup_006a6fdc;
            if (conf == (CONF *)0x0) {
LAB_0059d80c:
              if ((flags & 4) == 0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x76,0x6d,"conf_mod.c",0xdf);
                (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_3c,0xd,&DAT_0066f1bc,0xffffffff);
                appname = "module=";
                (*(code *)PTR_ERR_add_error_data_006a813c)
                          (6,"module=",flags_00,", value=",pcVar19,", retcode=",auStack_3c);
                pCVar16 = (CONF *)flags_00;
              }
              goto LAB_0059d4a8;
            }
            conf->meth = pCVar9;
            pvVar11 = (void *)(*(code *)puVar2)(flags_00);
            puVar2 = PTR_BUF_strdup_006a6fdc;
            conf->meth_data = pvVar11;
            plVar12 = (lhash_st_CONF_VALUE *)(*(code *)puVar2)(pcVar19);
            conf[1].meth_data = (void *)0x0;
            conf->data = plVar12;
            if (conf->meth_data == (void *)0x0) {
LAB_0059d7e8:
              if (plVar12 != (lhash_st_CONF_VALUE *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)(plVar12);
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(conf);
              goto LAB_0059d80c;
            }
            if (plVar12 == (lhash_st_CONF_VALUE *)0x0) {
LAB_0059d7d8:
              (*(code *)PTR_CRYPTO_free_006a6e88)();
LAB_0059d7e4:
              plVar12 = conf->data;
              goto LAB_0059d7e8;
            }
            if (pCVar9->init != (_func_3660 *)0x0) {
              appname = (char *)cnf;
              iVar5 = (*pCVar9->init)(conf);
              if (0 < iVar5) {
                bVar1 = true;
                goto joined_r0x0059d758;
              }
              p_Var8 = pCVar9->destroy;
              if (p_Var8 != (_func_3661 *)0x0) goto LAB_0059d7c0;
              pvVar11 = conf->meth_data;
LAB_0059d7d0:
              if (pvVar11 != (void *)0x0) goto LAB_0059d7d8;
              goto LAB_0059d7e4;
            }
            bVar1 = false;
joined_r0x0059d758:
            if ((initialized_modules == 0) &&
               (initialized_modules = (*(code *)PTR_sk_new_null_006a6fa4)(),
               initialized_modules == 0)) {
              pCVar16 = (CONF *)&DAT_00000041;
              appname = &DAT_00000073;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x73,0x41,"conf_mod.c",0x16c);
LAB_0059d7ac:
              p_Var8 = pCVar9->destroy;
              if ((p_Var8 != (_func_3661 *)0x0) && (bVar1)) {
LAB_0059d7c0:
                (*p_Var8)(conf);
              }
              pvVar11 = conf->meth_data;
              goto LAB_0059d7d0;
            }
            appname = (char *)conf;
            iVar5 = (*(code *)PTR_sk_push_006a6fa8)(initialized_modules);
            if (iVar5 == 0) {
              pCVar16 = (CONF *)&DAT_00000041;
              appname = &DAT_00000073;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x73,0x41,"conf_mod.c",0x172);
              goto LAB_0059d7ac;
            }
            pCVar9->destroy_data = pCVar9->destroy_data + 1;
            flags_00 = (char *)pCVar16;
          }
          else {
joined_r0x0059d670:
            if ((flags & 4) == 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x76,0x71,"conf_mod.c",0xd4);
              appname = "module=";
              (*(code *)PTR_ERR_add_error_data_006a813c)(2);
              if ((flags & 1) == 0) {
                iVar5 = -1;
                goto LAB_0059d4d0;
              }
            }
            else {
LAB_0059d4a8:
              flags_00 = (char *)pCVar16;
              iVar5 = -1;
              if ((flags & 1) == 0) goto LAB_0059d4d0;
            }
          }
          iVar18 = iVar18 + 1;
          iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
        } while (iVar18 < iVar5);
      }
      goto LAB_0059d4cc;
    }
    iVar5 = 0;
  }
LAB_0059d4d0:
  if (local_2c == *(char **)puVar3) {
    return iVar5;
  }
  pcVar19 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pCVar16 = NCONF_new((CONF_METHOD *)0x0);
  if (pCVar16 == (CONF *)0x0) {
    iVar5 = 0;
    pcVar14 = (char *)0x0;
LAB_0059da44:
    if (pcVar19 != (char *)0x0) goto LAB_0059da4c;
  }
  else {
    pcVar14 = pcVar19;
    if (pcVar19 != (char *)0x0) {
LAB_0059da10:
      iVar5 = NCONF_load(pCVar16,pcVar14,(long *)0x0);
      if (iVar5 < 1) {
        if ((((uint)flags_00 & 0x10) == 0) ||
           (uVar13 = (*(code *)PTR_ERR_peek_last_error_006a7408)(), (uVar13 & 0xfff) != 0x72)) {
          iVar5 = 0;
        }
        else {
          iVar5 = 1;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
      }
      else {
        iVar5 = CONF_modules_load(pCVar16,appname,(ulong)flags_00);
      }
      goto LAB_0059da44;
    }
    iVar5 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF");
    if (iVar5 == 0) {
      uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
      iVar5 = (*(code *)PTR_strlen_006a9a24)(uVar15);
      iVar5 = iVar5 + 0xd;
      pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"conf_mod.c",0x21b);
      if (pcVar14 != (char *)0x0) {
        uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar14,uVar15,iVar5);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar14,&DAT_0063b2b4,iVar5);
        (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar14,"openssl.cnf",iVar5);
        goto LAB_0059da10;
      }
    }
    else {
      pcVar14 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(iVar5);
      if (pcVar14 != (char *)0x0) goto LAB_0059da10;
    }
    pcVar14 = (char *)0x0;
    iVar5 = 0;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar14);
LAB_0059da4c:
  NCONF_free(pCVar16);
  return iVar5;
}

