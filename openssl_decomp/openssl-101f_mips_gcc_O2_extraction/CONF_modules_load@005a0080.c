
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
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  flags_00 = (char *)flags;
  if (cnf == (CONF *)0x0) {
LAB_005a023c:
    iVar5 = 1;
  }
  else {
    if (appname == (char *)0x0) {
LAB_005a0690:
      pCVar16 = (CONF *)0x0;
      flags_00 = "openssl_conf";
      appname = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
      if ((CONF *)appname == (CONF *)0x0) {
LAB_005a06b4:
        appname = (char *)pCVar16;
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        goto LAB_005a023c;
      }
    }
    else {
      pCVar16 = (CONF *)0x0;
      flags_00 = appname;
      appname = NCONF_get_string(cnf,(char *)0x0,appname);
      if ((CONF *)appname == (CONF *)0x0) {
        if ((flags & 0x20) != 0) goto LAB_005a0690;
        goto LAB_005a06b4;
      }
    }
    psVar4 = NCONF_get_section(cnf,appname);
    if (psVar4 != (stack_st_CONF_VALUE *)0x0) {
      iVar18 = 0;
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
      if (0 < iVar5) {
        do {
          iVar5 = (*(code *)PTR_sk_value_006a7f24)(psVar4,iVar18);
          appname = (char *)0x2e;
          flags_00 = *(char **)(iVar5 + 4);
          pcVar19 = *(char **)(iVar5 + 8);
          iVar5 = (*(code *)PTR_strrchr_006aaab8)(flags_00);
          if (iVar5 == 0) {
            iVar5 = (*(code *)PTR_strlen_006aab30)(flags_00);
          }
          else {
            iVar5 = iVar5 - (int)flags_00;
          }
          for (iVar17 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(supported_modules), iVar17 < iVar6
              ; iVar17 = iVar17 + 1) {
            pCVar9 = (CONF_METHOD *)(*(code *)PTR_sk_value_006a7f24)(supported_modules,iVar17);
            appname = flags_00;
            iVar6 = (*(code *)PTR_strncmp_006aaa7c)(pCVar9->create,flags_00,iVar5);
            if (iVar6 == 0) goto LAB_005a0440;
          }
          pCVar16 = (CONF *)0x680000;
          if ((flags & 8) == 0) {
            local_64 = (CONF *)NCONF_get_string(cnf,pcVar19,"path");
            if (local_64 == (CONF *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              local_64 = (CONF *)flags_00;
            }
            pcVar14 = (char *)(*(code *)PTR_DSO_load_006a99a4)(0,local_64,0,0);
            if (pcVar14 == (char *)0x0) {
              uVar15 = 0x6e;
LAB_005a0394:
              (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x75,uVar15,"conf_mod.c",0x11d);
              appname = "module=";
              pCVar16 = (CONF *)flags_00;
              (*(code *)PTR_ERR_add_error_data_006a9264)(4,"module=",flags_00,", path=",local_64);
              goto joined_r0x005a03e0;
            }
            p_Var7 = (_func_3660 *)(*(code *)PTR_DSO_bind_func_006a99ac)(pcVar14,"OPENSSL_init");
            if (p_Var7 == (_func_3660 *)0x0) {
              uVar15 = 0x70;
LAB_005a0384:
              (*(code *)PTR_DSO_free_006a9994)(pcVar14);
              goto LAB_005a0394;
            }
            p_Var8 = (_func_3661 *)(*(code *)PTR_DSO_bind_func_006a99ac)(pcVar14,"OPENSSL_finish");
            if (((supported_modules == 0) &&
                (supported_modules = (*(code *)PTR_sk_new_null_006a80a4)(), supported_modules == 0))
               || (pCVar9 = (CONF_METHOD *)
                            (*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"conf_mod.c",299),
                  puVar2 = PTR_BUF_strdup_006a80dc, pCVar9 == (CONF_METHOD *)0x0)) {
LAB_005a0380:
              uVar15 = 0;
              goto LAB_005a0384;
            }
            pCVar9->name = pcVar14;
            p_Var10 = (_func_3659 *)(*(code *)puVar2)(flags_00);
            pCVar9->create = p_Var10;
            iVar5 = supported_modules;
            puVar2 = PTR_sk_push_006a80a8;
            pCVar9->destroy_data = (_func_3662 *)0x0;
            pCVar9->init = p_Var7;
            pCVar9->destroy = p_Var8;
            iVar5 = (*(code *)puVar2)(iVar5,pCVar9);
            if (iVar5 == 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)(pCVar9);
              goto LAB_005a0380;
            }
LAB_005a0440:
            pCVar16 = (CONF *)0x163;
            appname = "conf_mod.c";
            conf = (CONF *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14);
            puVar2 = PTR_BUF_strdup_006a80dc;
            if (conf == (CONF *)0x0) {
LAB_005a057c:
              if ((flags & 4) == 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x76,0x6d,"conf_mod.c",0xeb);
                (*(code *)PTR_BIO_snprintf_006a8060)(auStack_3c,0xd,&DAT_0066faec,0xffffffff);
                appname = "module=";
                (*(code *)PTR_ERR_add_error_data_006a9264)
                          (6,"module=",flags_00,", value=",pcVar19,", retcode=",auStack_3c);
                pCVar16 = (CONF *)flags_00;
              }
              goto LAB_005a0218;
            }
            conf->meth = pCVar9;
            pvVar11 = (void *)(*(code *)puVar2)(flags_00);
            puVar2 = PTR_BUF_strdup_006a80dc;
            conf->meth_data = pvVar11;
            plVar12 = (lhash_st_CONF_VALUE *)(*(code *)puVar2)(pcVar19);
            conf[1].meth_data = (void *)0x0;
            conf->data = plVar12;
            if (conf->meth_data == (void *)0x0) {
LAB_005a0558:
              if (plVar12 != (lhash_st_CONF_VALUE *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)(plVar12);
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(conf);
              goto LAB_005a057c;
            }
            if (plVar12 == (lhash_st_CONF_VALUE *)0x0) {
LAB_005a0548:
              (*(code *)PTR_CRYPTO_free_006a7f88)();
LAB_005a0554:
              plVar12 = conf->data;
              goto LAB_005a0558;
            }
            if (pCVar9->init != (_func_3660 *)0x0) {
              appname = (char *)cnf;
              iVar5 = (*pCVar9->init)(conf);
              if (0 < iVar5) {
                bVar1 = true;
                goto joined_r0x005a04c8;
              }
              p_Var8 = pCVar9->destroy;
              if (p_Var8 != (_func_3661 *)0x0) goto LAB_005a0530;
              pvVar11 = conf->meth_data;
LAB_005a0540:
              if (pvVar11 != (void *)0x0) goto LAB_005a0548;
              goto LAB_005a0554;
            }
            bVar1 = false;
joined_r0x005a04c8:
            if ((initialized_modules == 0) &&
               (initialized_modules = (*(code *)PTR_sk_new_null_006a80a4)(),
               initialized_modules == 0)) {
              pCVar16 = (CONF *)&DAT_00000041;
              appname = &DAT_00000073;
              (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x73,0x41,"conf_mod.c",0x17e);
LAB_005a051c:
              p_Var8 = pCVar9->destroy;
              if ((p_Var8 != (_func_3661 *)0x0) && (bVar1)) {
LAB_005a0530:
                (*p_Var8)(conf);
              }
              pvVar11 = conf->meth_data;
              goto LAB_005a0540;
            }
            appname = (char *)conf;
            iVar5 = (*(code *)PTR_sk_push_006a80a8)(initialized_modules);
            if (iVar5 == 0) {
              pCVar16 = (CONF *)&DAT_00000041;
              appname = &DAT_00000073;
              (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x73,0x41,"conf_mod.c",0x185);
              goto LAB_005a051c;
            }
            pCVar9->destroy_data = pCVar9->destroy_data + 1;
            flags_00 = (char *)pCVar16;
          }
          else {
joined_r0x005a03e0:
            if ((flags & 4) == 0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x76,0x71,"conf_mod.c",0xde);
              appname = "module=";
              (*(code *)PTR_ERR_add_error_data_006a9264)(2);
              if ((flags & 1) == 0) {
                iVar5 = -1;
                goto LAB_005a0240;
              }
            }
            else {
LAB_005a0218:
              flags_00 = (char *)pCVar16;
              iVar5 = -1;
              if ((flags & 1) == 0) goto LAB_005a0240;
            }
          }
          iVar18 = iVar18 + 1;
          iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
        } while (iVar18 < iVar5);
      }
      goto LAB_005a023c;
    }
    iVar5 = 0;
  }
LAB_005a0240:
  if (local_2c == *(char **)puVar3) {
    return iVar5;
  }
  pcVar19 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pCVar16 = NCONF_new((CONF_METHOD *)0x0);
  if (pCVar16 == (CONF *)0x0) {
    iVar5 = 0;
    pcVar14 = (char *)0x0;
LAB_005a07b4:
    if (pcVar19 != (char *)0x0) goto LAB_005a07bc;
  }
  else {
    pcVar14 = pcVar19;
    if (pcVar19 != (char *)0x0) {
LAB_005a0780:
      iVar5 = NCONF_load(pCVar16,pcVar14,(long *)0x0);
      if (iVar5 < 1) {
        if ((((uint)flags_00 & 0x10) == 0) ||
           (uVar13 = (*(code *)PTR_ERR_peek_last_error_006a8508)(), (uVar13 & 0xfff) != 0x72)) {
          iVar5 = 0;
        }
        else {
          iVar5 = 1;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
      }
      else {
        iVar5 = CONF_modules_load(pCVar16,appname,(ulong)flags_00);
      }
      goto LAB_005a07b4;
    }
    iVar5 = (*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF");
    if (iVar5 == 0) {
      uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
      iVar5 = (*(code *)PTR_strlen_006aab30)(uVar15);
      iVar5 = iVar5 + 0xd;
      pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,"conf_mod.c",0x231);
      if (pcVar14 != (char *)0x0) {
        uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar14,uVar15,iVar5);
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar14,&DAT_0063ba98,iVar5);
        (*(code *)PTR_BUF_strlcat_006a8068)(pcVar14,"openssl.cnf",iVar5);
        goto LAB_005a0780;
      }
    }
    else {
      pcVar14 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(iVar5);
      if (pcVar14 != (char *)0x0) goto LAB_005a0780;
    }
    pcVar14 = (char *)0x0;
    iVar5 = 0;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar14);
LAB_005a07bc:
  NCONF_free(pCVar16);
  return iVar5;
}

