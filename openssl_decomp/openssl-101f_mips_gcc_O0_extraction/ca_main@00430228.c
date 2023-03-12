
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ca_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int *piVar19;
  char **ppcVar20;
  int *piVar21;
  int *piVar22;
  undefined4 uVar23;
  int iVar24;
  int *piVar25;
  byte *pbVar26;
  int *piVar27;
  undefined4 uVar28;
  byte *pbVar29;
  uint *puVar30;
  undefined1 *puVar31;
  undefined4 uVar32;
  int *piVar33;
  char *pcVar34;
  char *pcVar35;
  int iVar36;
  char *pcVar37;
  int **ppiVar38;
  int **ppiVar39;
  byte *pbVar40;
  byte **ppbVar41;
  byte **ppbVar42;
  code *pcVar43;
  int **ppiVar44;
  undefined1 *local_450;
  undefined1 *local_44c;
  byte **local_448;
  byte *local_444;
  char *local_440;
  int local_43c;
  byte *local_438;
  int local_434;
  byte **local_430;
  int local_42c;
  int local_428;
  undefined *local_424;
  int local_420;
  int *local_418;
  int *local_414;
  int *local_410;
  char *local_40c;
  int *local_408;
  byte *local_404;
  int *local_400;
  int *local_3f8;
  int *local_3f4;
  byte *local_3f0;
  int local_3ec;
  int *local_3e8;
  byte *local_3e4;
  int *local_3e0;
  byte *local_3dc;
  undefined4 local_3d8;
  byte *local_3d4;
  int local_3d0;
  byte *local_3c8;
  byte *local_3c4;
  int *local_3c0;
  int *local_3bc;
  int local_3b8;
  byte *local_3b4;
  int *local_3ac;
  char *local_3a8;
  int *local_3a0;
  int *local_39c;
  byte *local_374;
  int local_370;
  int local_36c;
  int local_368;
  int *local_364;
  int *local_360;
  int *local_35c;
  int *local_358;
  undefined4 local_354;
  int *local_350;
  undefined4 local_34c;
  undefined4 local_348 [7];
  uint local_32c [3];
  char *local_320;
  undefined4 local_31c;
  undefined4 local_318;
  uint auStack_314 [122];
  undefined auStack_12c [256];
  int local_2c;
  
  puVar9 = PTR___stack_chk_guard_006aabf0;
  puVar8 = PTR_bio_err_006a7f3c;
  local_368 = -1;
  local_374 = (byte *)0x0;
  local_370 = 0;
  local_36c = 0;
  local_364 = (int *)0x0;
  local_360 = (int *)0x0;
  local_35c = (int *)0x0;
  local_358 = (int *)0x0;
  local_354 = 0;
  local_350 = (int *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  local_374 = (byte *)0x0;
  local_448 = (byte **)&_ITM_registerTMCloneTable;
  conf = (int *)0x0;
  local_450 = &_ITM_registerTMCloneTable;
  local_39c = (int *)&_ITM_registerTMCloneTable;
  local_3a0 = (int *)&_ITM_registerTMCloneTable;
  section = 0;
  preserve = 0;
  msie_hack = 0;
  if (*(int *)puVar8 == 0) {
    uVar15 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar36 = (*(code *)PTR_BIO_new_006a7fa4)(uVar15);
    *(int *)puVar8 = iVar36;
    if (iVar36 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar36,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  ppiVar44 = (int **)(param_1 + -1);
  local_438 = (byte *)0x0;
  ppbVar41 = (byte **)(param_2 + 4);
  if ((int)ppiVar44 < 1) {
    local_3d0 = 0;
    bVar5 = false;
    pbVar40 = (byte *)0x0;
    local_3ec = 0;
    iVar36 = 0;
    local_424 = (undefined *)0x1001;
    local_408 = (int *)0x0;
    local_40c = (char *)0x0;
    local_3a8 = (char *)0x3;
    local_3d4 = (byte *)0x0;
    local_3d8 = 0;
    local_3f0 = (byte *)0x0;
    local_410 = (int *)0x0;
    local_444 = (byte *)0x0;
    local_3e0 = (int *)0x0;
    local_414 = (int *)0x0;
    local_404 = (byte *)0x0;
    local_3c0 = (int *)0x0;
    local_3e4 = (byte *)0x0;
    local_3bc = (int *)0x0;
    local_3e8 = (int *)0x0;
    local_3dc = (byte *)0x0;
    local_3c4 = (byte *)0x0;
    local_3c8 = (byte *)0x0;
    local_400 = (int *)0x0;
    local_3f4 = (int *)0x0;
    local_3b8 = 0;
    local_3ac = (int *)0x0;
    bVar6 = false;
    bVar4 = false;
    bVar3 = true;
    local_418 = (int *)0x0;
    local_3b4 = (byte *)0x0;
    local_420 = 0;
    local_3f8 = (int *)0x0;
    goto LAB_00430448;
  }
  local_420 = 0;
  local_3d0 = 0;
  bVar5 = false;
  local_424 = (undefined *)0x1001;
  local_3ec = 0;
  pbVar40 = (byte *)0x0;
  local_408 = (int *)0x0;
  iVar36 = 0;
  local_3a8 = (char *)0x3;
  local_40c = (char *)0x0;
  puVar31 = (undefined1 *)0x630000;
  local_3d4 = (byte *)0x0;
  pcVar34 = "-config";
  bVar3 = true;
  local_3d8 = 0;
  pcVar37 = "-name";
  local_3f0 = (byte *)0x0;
  local_410 = (int *)0x0;
  local_444 = (byte *)0x0;
  local_3e0 = (int *)0x0;
  local_414 = (int *)0x0;
  local_404 = (byte *)0x0;
  local_3c0 = (int *)0x0;
  local_3e4 = (byte *)0x0;
  local_3bc = (int *)0x0;
  local_3e8 = (int *)0x0;
  local_3dc = (byte *)0x0;
  local_3c4 = (byte *)0x0;
  local_3c8 = (byte *)0x0;
  local_400 = (int *)0x0;
  local_3f4 = (int *)0x0;
  local_3b8 = 0;
  local_3ac = (int *)0x0;
  bVar6 = false;
  bVar4 = false;
  local_3f8 = (int *)0x0;
  local_418 = (int *)0x0;
  local_3b4 = (byte *)0x0;
  local_44c = (undefined1 *)0x630000;
  local_440 = "-utf8";
  local_43c = 0x630000;
  do {
    do {
      pbVar29 = *ppbVar41;
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,puVar31 + 0x2894);
      if (iVar14 != 0) {
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,pcVar34);
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          pbVar40 = ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,pcVar37);
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          ppbVar42 = ppbVar41 + 1;
          ppbVar41 = ppbVar41 + 1;
          *(byte **)(local_450 + -0x4df8) = *ppbVar42;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,local_44c + 0x31a4);
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_444 = ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,local_440);
        if (iVar14 == 0) {
          local_424 = (undefined *)0x1000;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,local_43c + 0x6410);
        if (iVar14 == 0) {
          local_418 = (int *)0x1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-multivalue-rdn");
        if (iVar14 == 0) {
          local_410 = (int *)0x1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-startdate");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_40c = (char *)ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-enddate");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_408 = (int *)ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-days");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          ppbVar42 = ppbVar41 + 1;
          ppbVar41 = ppbVar41 + 1;
          local_360 = (int *)(*(code *)PTR_strtol_006aaa68)(*ppbVar42,0,10);
          goto LAB_00430410;
        }
        local_434 = 0x2d - (uint)*pbVar29;
        if ((((local_434 == 0) && (pbVar29[1] == 0x6d)) && (pbVar29[2] == 100)) && (pbVar29[3] == 0)
           ) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_3f4 = (int *)ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-policy");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_400 = (int *)ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-keyfile");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          local_3c8 = ppbVar41[1];
          ppbVar41 = ppbVar41 + 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-keyform");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 == (int **)0x0) goto LAB_00430804;
          ppbVar41 = ppbVar41 + 1;
          local_3a8 = (char *)(*(code *)PTR_str2fmt_006a7f4c)(*ppbVar41);
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-passin");
        ppbVar42 = ppbVar41;
        if (iVar14 != 0) goto LAB_0043165c;
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 == (int **)0x0) goto LAB_00430804;
        local_3b4 = ppbVar41[1];
        ppbVar41 = ppbVar41 + 1;
        goto LAB_00430410;
      }
      ppiVar44 = (int **)((int)ppiVar44 + -1);
      iVar36 = 1;
      ppbVar41 = ppbVar41 + 1;
    } while (ppiVar44 != (int **)0x0);
LAB_00430448:
    do {
      piVar19 = local_3bc;
      (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
      if (((pbVar40 == (byte *)0x0) &&
          (pbVar40 = (byte *)(*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF"), pbVar40 == (byte *)0x0)
          ) && (pbVar40 = (byte *)(*(code *)PTR_getenv_006aab6c)("SSLEAY_CONF"),
               pbVar40 == (byte *)0x0)) {
        uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
        iVar14 = (*(code *)PTR_strlen_006aab30)(uVar15);
        iVar14 = iVar14 + 0xd;
        pbVar29 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar14,&DAT_00635b2c,0x254);
        (*(code *)PTR_BUF_strlcpy_006a8064)(pbVar29,uVar15,iVar14);
        (*(code *)PTR_BUF_strlcat_006a8068)(pbVar29,&DAT_0063ba98,iVar14);
        (*(code *)PTR_BUF_strlcat_006a8068)(pbVar29,"openssl.cnf",iVar14);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Using configuration from %s\n",pbVar29);
        conf = (int *)(*(code *)PTR_NCONF_new_006a7f58)(0);
        iVar14 = (*(code *)PTR_NCONF_load_006a7f5c)(conf,pbVar29,&local_368);
        pbVar40 = pbVar29;
        if (0 < iVar14) {
          if (pbVar29 != (byte *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar29);
          }
          goto LAB_004309a0;
        }
LAB_004304b4:
        if (local_368 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"error loading the config file \'%s\'\n",pbVar40);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"error on line %ld of config file \'%s\'\n",local_368,
                     pbVar40);
        }
        if (pbVar29 != (byte *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(pbVar29);
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Using configuration from %s\n",pbVar40);
        conf = (int *)(*(code *)PTR_NCONF_new_006a7f58)(0);
        iVar14 = (*(code *)PTR_NCONF_load_006a7f5c)(conf,pbVar40,&local_368);
        if (iVar14 < 1) {
          pbVar29 = (byte *)0x0;
          goto LAB_004304b4;
        }
LAB_004309a0:
        puVar7 = PTR_bio_err_006a7f3c;
        iVar14 = (*(code *)PTR_load_config_006a7f64)(*(undefined4 *)puVar8,conf);
        if (iVar14 != 0) {
          uVar15 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar7,local_438,0);
          if ((*(int *)(local_450 + -0x4df8) != 0) ||
             (section = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","default_ca"),
             section != 0)) {
            if (conf != (int *)0x0) {
              iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,0,"oid_file");
              if ((iVar14 == 0) ||
                 (iVar14 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar14,"r"), iVar14 == 0)) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else {
                (*(code *)PTR_OBJ_create_objects_006a7fb0)(iVar14);
                (*(code *)PTR_BIO_free_006a7f70)(iVar14);
              }
              iVar14 = (*(code *)PTR_add_oid_section_006a7f60)(*(undefined4 *)puVar8,conf);
              if (iVar14 == 0) {
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                goto LAB_004304ec;
              }
            }
            local_42c = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","RANDFILE");
            if (local_42c == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            (*(code *)PTR_app_RAND_load_file_006a7fcc)(local_42c,*(undefined4 *)puVar8,0);
            iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(local_450 + -0x4df8),"string_mask");
            if (iVar14 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar16 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a7fc0)(iVar14);
              if (iVar16 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "Invalid global string mask setting %s\n",iVar14);
                goto LAB_004304f0;
              }
            }
            if (local_424 == (undefined *)0x1000) {
LAB_00430b5c:
              local_424 = (undefined *)0x1000;
            }
            else {
              pcVar37 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (conf,*(undefined4 *)(local_450 + -0x4df8),&DAT_00633b60);
              if (pcVar37 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else if ((((*pcVar37 == 'y') && (pcVar37[1] == 'e')) && (pcVar37[2] == 's')) &&
                      (pcVar37[3] == '\0')) goto LAB_00430b5c;
            }
            local_34c = 1;
            iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(local_450 + -0x4df8),"unique_subject");
            if (iVar14 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              local_34c = (*(code *)PTR_parse_yesno_006a8168)(iVar14,1);
            }
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            local_428 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            local_434 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            local_438 = (byte *)(*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            local_430 = (byte **)(*(code *)PTR_BIO_new_006a7fa4)(uVar17);
            if (((local_428 == 0) || (local_434 == 0)) ||
               ((local_438 == (byte *)0x0 || (local_430 == (byte **)0x0)))) {
              pbVar40 = (byte *)0x0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
              goto LAB_0043050c;
            }
            if (local_3e4 != (byte *)0x0) {
              iVar36 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                 (conf,*(undefined4 *)(local_450 + -0x4df8),"database");
              if (iVar36 != 0) {
                pbVar40 = (byte *)(*(code *)PTR_load_index_006a816c)(iVar36,&local_34c);
                if (pbVar40 == (byte *)0x0) goto LAB_0043050c;
                iVar36 = (*(code *)PTR_index_index_006a8170)(pbVar40);
                if (iVar36 == 0) goto LAB_0043050c;
                puVar30 = local_32c;
                local_32c[0] = 0;
                local_32c[1] = 0;
                local_32c[2] = 0;
                local_320 = (char *)0x0;
                local_31c = 0;
                local_318 = 0;
                iVar36 = (*(code *)PTR_strlen_006aab30)(local_3e4);
                pcVar37 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                            (iVar36 + 2,&DAT_00635b2c,0x9eb);
                local_320 = pcVar37;
                if (pcVar37 == (char *)0x0) {
                  iVar36 = -1;
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Malloc failure\n");
                }
                else {
                  uVar18 = (*(code *)PTR_strlen_006aab30)(local_3e4);
                  puVar7 = PTR_strlen_006aab30;
                  if ((uVar18 & 1) == 0) {
                    (*(code *)PTR_memcpy_006aabf4)(pcVar37,local_3e4,uVar18);
                    iVar36 = (*(code *)PTR_strlen_006aab30)(local_3e4);
                    local_320[iVar36] = '\0';
                  }
                  else {
                    *pcVar37 = '0';
                    uVar15 = (*(code *)puVar7)(local_3e4);
                    (*(code *)PTR_memcpy_006aabf4)(local_320 + 1,local_3e4,uVar15);
                    iVar36 = (*(code *)PTR_strlen_006aab30)(local_3e4);
                    local_320[iVar36 + 1] = '\0';
                  }
                  pcVar37 = local_320;
                  uVar18 = (uint)*local_320;
                  if (uVar18 != 0) {
                    piVar19 = (int *)(*(code *)PTR___ctype_toupper_loc_006aac30)();
                    iVar36 = 0;
                    do {
                      iVar36 = iVar36 + 1;
                      *pcVar37 = (char)*(undefined4 *)(*piVar19 + (uVar18 & 0xff) * 4);
                      pcVar37 = local_320 + iVar36;
                      uVar18 = (uint)*pcVar37;
                    } while (uVar18 != 0);
                  }
                  ppcVar20 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)
                                                (*(undefined4 *)(pbVar40 + 4),3,puVar30);
                  if (ppcVar20 == (char **)0x0) {
                    iVar36 = -1;
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar8,"Serial %s not present in db.\n",local_320);
                  }
                  else {
                    cVar1 = **ppcVar20;
                    if (cVar1 == 'V') {
                      iVar36 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Valid (%c)\n",local_320,0x56);
                    }
                    else if (cVar1 == 'R') {
                      iVar36 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Revoked (%c)\n",local_320,0x52);
                    }
                    else if (cVar1 == 'E') {
                      iVar36 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Expired (%c)\n",local_320,0x45);
                    }
                    else if (cVar1 == 'S') {
                      iVar36 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Suspended (%c)\n",local_320,0x53);
                    }
                    else {
                      iVar36 = -1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Unknown (%c).\n",local_320);
                    }
                  }
                }
                do {
                  if (*puVar30 != 0) {
                    (*(code *)PTR_CRYPTO_free_006a7f88)();
                  }
                  puVar30 = puVar30 + 1;
                } while (puVar30 != auStack_314);
                if (iVar36 == 1) goto LAB_0043050c;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Error verifying serial %s!\n",local_3e4);
                goto LAB_0043050c;
              }
              pcVar37 = "database";
LAB_004315b4:
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,pcVar37
                        );
              pbVar40 = (byte *)0x0;
              goto LAB_0043050c;
            }
            if ((local_3c8 == (byte *)0x0) &&
               (local_3c8 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                              (conf,*(undefined4 *)(local_450 + -0x4df8),
                                               "private_key"), local_3c8 == (byte *)0x0)) {
              pcVar37 = "private_key";
              goto LAB_004315b4;
            }
            if (local_374 == (byte *)0x0) {
              iVar14 = (*(code *)PTR_app_passwd_006a7f54)
                                 (*(undefined4 *)puVar8,local_3b4,0,&local_374,0);
              if (iVar14 == 0) {
                pcVar34 = (char *)0x0;
                pbVar29 = (byte *)0x0;
                pbVar40 = (byte *)0x0;
                pcVar37 = (char *)0x0;
                puVar31 = (undefined1 *)0x0;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,"Error getting password\n");
                iVar36 = 1;
                local_440 = (char *)0x0;
                local_43c = 1;
                goto LAB_00430528;
              }
              local_43c = 1;
            }
            else {
              local_43c = 0;
            }
            local_440 = (char *)(*(code *)PTR_load_key_006a7fc8)
                                          (*(undefined4 *)puVar8,local_3c8,local_3a8,0,local_374,
                                           uVar15,"CA private key");
            pbVar40 = local_374;
            if (local_374 != (byte *)0x0) {
              uVar17 = (*(code *)PTR_strlen_006aab30)(local_374);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(pbVar40,uVar17);
            }
            if (local_440 == (char *)0x0) {
LAB_004317b0:
              pcVar34 = (char *)0x0;
              pbVar29 = (byte *)0x0;
              pbVar40 = (byte *)0x0;
              pcVar37 = (char *)0x0;
              puVar31 = (undefined1 *)0x0;
              iVar36 = 1;
              goto LAB_00430528;
            }
            if ((((local_3d0 == 0) || (local_3e8 != (int *)0x0)) || (local_3bc != (int *)0x0)) ||
               (bVar4)) {
              if ((local_3c4 == (byte *)0x0) &&
                 (local_3c4 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                (conf,*(undefined4 *)(local_450 + -0x4df8),
                                                 "certificate"), local_3c4 == (byte *)0x0)) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,
                           "certificate");
                goto LAB_004317b0;
              }
              pcVar37 = (char *)(*(code *)PTR_load_cert_006a8178)
                                          (*(undefined4 *)puVar8,local_3c4,3,0,uVar15,
                                           "CA certificate");
              if ((byte *)pcVar37 == (byte *)0x0) goto LAB_00431744;
              iVar14 = (*(code *)PTR_X509_check_private_key_006a817c)(pcVar37,local_440);
              if (iVar14 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "CA certificate and CA private key do not match\n");
                goto LAB_00431744;
              }
              local_3b4 = (byte *)pcVar37;
              if (local_3d0 != 0) goto LAB_00431524;
            }
            else {
              pcVar37 = (char *)0x0;
LAB_00431524:
              local_3b4 = (byte *)0x0;
            }
            pbVar40 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","preserve");
            if (pbVar40 == (byte *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else if ((*pbVar40 & 0xdf) == 0x59) {
              local_39c[-0x137f] = 1;
            }
            pbVar40 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","msie_hack");
            if (pbVar40 == (byte *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else if ((*pbVar40 & 0xdf) == 0x59) {
              local_3a0[-0x1380] = 1;
            }
            iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(local_450 + -0x4df8),"name_opt");
            if (iVar14 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              local_3c8 = (byte *)0x1;
            }
            else {
              iVar16 = (*(code *)PTR_set_name_ex_006a80ac)(&local_35c,iVar14);
              if (iVar16 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid name options: \"%s\"\n",iVar14);
                goto LAB_00431744;
              }
              local_3c8 = (byte *)0x0;
            }
            iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(local_450 + -0x4df8),"cert_opt");
            if (iVar14 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar16 = (*(code *)PTR_set_cert_ex_006a80b0)(&local_358,iVar14);
              if (iVar16 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid certificate options: \"%s\"\n",iVar14);
                goto LAB_00431744;
              }
              local_3c8 = (byte *)0x0;
            }
            iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(local_450 + -0x4df8),"copy_extensions");
            if (iVar14 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar16 = (*(code *)PTR_set_ext_copy_006a8180)(&local_354,iVar14);
              if (iVar16 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid extension copy option: \"%s\"\n",iVar14);
                goto LAB_00431744;
              }
            }
            if ((local_404 == (byte *)0x0) && (local_3f8 != (int *)0x0)) {
              local_404 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                            (conf,*(undefined4 *)(local_450 + -0x4df8),
                                             "new_certs_dir");
              if (local_404 == (byte *)0x0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,
                           "there needs to be defined a directory for new certificate to be placed in\n"
                          );
                goto LAB_00431744;
              }
              iVar14 = (*(code *)PTR_access_006aaad8)(local_404,7);
              if (iVar14 != 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"I am unable to access the %s directory\n",
                           local_404);
                (*(code *)PTR_perror_006aab88)(local_404);
                goto LAB_00431744;
              }
              iVar14 = (*(code *)PTR_app_isdir_006a8188)(local_404);
              if (iVar14 < 1) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"%s need to be a directory\n",local_404);
                (*(code *)PTR_perror_006aab88)(local_404);
                goto LAB_00431744;
              }
            }
            local_3e4 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (conf,*(undefined4 *)(local_450 + -0x4df8),"database");
            if (local_3e4 == (byte *)0x0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,
                         "database");
LAB_00431744:
              pcVar34 = (char *)0x0;
              pbVar29 = (byte *)0x0;
              pbVar40 = (byte *)0x0;
              puVar31 = (undefined1 *)0x0;
              iVar36 = 1;
              goto LAB_00430528;
            }
            pbVar40 = (byte *)(*(code *)PTR_load_index_006a816c)(local_3e4,&local_34c);
            if (pbVar40 == (byte *)0x0) goto LAB_004314a8;
            iVar14 = 0;
            goto LAB_004313b0;
          }
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar7,"variable lookup failed for %s::%s\n","ca","default_ca");
        }
      }
LAB_004304ec:
      local_42c = 0;
LAB_004304f0:
      local_430 = (byte **)0x0;
      local_438 = (byte *)0x0;
      pbVar40 = (byte *)0x0;
      local_434 = 0;
      local_428 = 0;
LAB_0043050c:
      pcVar34 = (char *)0x0;
      pbVar29 = (byte *)0x0;
      local_440 = (char *)0x0;
      pcVar37 = (char *)0x0;
      local_43c = 0;
      puVar31 = (undefined1 *)0x0;
      iVar36 = 1;
LAB_00430528:
      local_44c = &_ITM_registerTMCloneTable;
      (*(code *)PTR_BIO_free_all_006a7f74)(local_430);
      (*(code *)PTR_BIO_free_all_006a7f74)(local_438);
      (*(code *)PTR_BIO_free_all_006a7f74)(local_434);
      (*(code *)PTR_BIO_free_all_006a7f74)(local_428);
      if (pcVar34 != (char *)0x0) {
        (*(code *)PTR_sk_pop_free_006a8158)(pcVar34,PTR_X509_free_006a7f90);
      }
      if (iVar36 != 0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
      }
      (*(code *)PTR_app_RAND_write_file_006a804c)(local_42c,*(undefined4 *)puVar8);
      if ((local_43c != 0) && (local_374 != (byte *)0x0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      (*(code *)PTR_BN_free_006a811c)(local_364);
      (*(code *)PTR_BN_free_006a811c)(puVar31);
      (*(code *)PTR_free_index_006a815c)(pbVar40);
      if (local_420 != 0) {
        (*(code *)PTR_sk_free_006a7f80)(local_420);
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_440);
      if ((byte *)pcVar37 != (byte *)0x0) {
        (*(code *)PTR_X509_free_006a7f90)(pcVar37);
      }
      (*(code *)PTR_X509_CRL_free_006a8160)(pbVar29);
      (*(code *)PTR_NCONF_free_006a7f6c)(conf);
      (*(code *)PTR_NCONF_free_006a7f6c)(extconf);
      (*(code *)PTR_OBJ_cleanup_006a7f98)();
      if (local_2c == *(int *)puVar9) {
        return iVar36;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      ppbVar42 = ppbVar41;
LAB_0043165c:
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,&DAT_006330b4);
      ppbVar41 = ppbVar42;
      if (iVar14 == 0) {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          local_374 = ppbVar42[1];
          ppbVar41 = ppbVar42 + 1;
          goto LAB_00430410;
        }
LAB_00430804:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"unknown option %s\n",pbVar29);
        if (ca_usage._0_4_ == 0) goto LAB_004304ec;
        puVar31 = ca_usage;
        do {
          puVar31 = (undefined1 *)((int)puVar31 + 4);
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"%s");
        } while (*(int *)puVar31 != 0);
        local_42c = 0;
        goto LAB_004304f0;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-cert");
      if (iVar14 == 0) {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          local_3c4 = ppbVar42[1];
          ppbVar41 = ppbVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-selfsign");
      if (iVar14 == 0) {
        local_3d0 = 1;
        goto LAB_00430410;
      }
      if ((((local_434 == 0) && (pbVar29[1] == 0x69)) && (pbVar29[2] == 0x6e)) && (pbVar29[3] == 0))
      {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          local_3dc = ppbVar42[1];
          local_3f8 = (int *)0x1;
          ppbVar41 = ppbVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,&DAT_00632edc);
      if (iVar14 == 0) {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          local_3c0 = (int *)ppbVar42[1];
          ppbVar41 = ppbVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-outdir");
      if (iVar14 == 0) {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          local_404 = ppbVar42[1];
          ppbVar41 = ppbVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-sigopt");
      if (iVar14 == 0) {
        ppiVar44 = (int **)((int)ppiVar44 + -1);
        if (ppiVar44 != (int **)0x0) {
          if ((local_420 == 0) &&
             (local_420 = (*(code *)PTR_sk_new_null_006a80a4)(), local_420 == 0)) {
            pbVar29 = *ppbVar42;
          }
          else {
            ppbVar41 = ppbVar42 + 1;
            iVar14 = (*(code *)PTR_sk_push_006a80a8)(local_420,ppbVar42[1]);
            if (iVar14 != 0) goto LAB_00430410;
            pbVar29 = ppbVar42[1];
            ppbVar41 = ppbVar42;
          }
        }
        goto LAB_00430804;
      }
      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-notext");
      if (iVar14 != 0) {
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-batch");
        if (iVar14 == 0) {
          local_3ec = 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-preserveDN");
        if (iVar14 == 0) {
          local_39c[-0x137f] = 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-noemailDN");
        if (iVar14 == 0) {
          bVar3 = false;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-gencrl");
        if (iVar14 == 0) {
          bVar4 = true;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-msie_hack");
        if (iVar14 == 0) {
          local_3a0[-0x1380] = 1;
          goto LAB_00430410;
        }
        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crldays");
        if (iVar14 == 0) {
          ppiVar44 = (int **)((int)ppiVar44 + -1);
          if (ppiVar44 != (int **)0x0) {
            local_370 = (*(code *)PTR_strtol_006aaa68)(ppbVar42[1],0,10);
            ppbVar41 = ppbVar42 + 1;
            goto LAB_00430410;
          }
        }
        else {
          iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crlhours");
          if (iVar14 == 0) {
            ppiVar44 = (int **)((int)ppiVar44 + -1);
            if (ppiVar44 != (int **)0x0) {
              local_36c = (*(code *)PTR_strtol_006aaa68)(ppbVar42[1],0,10);
              ppbVar41 = ppbVar42 + 1;
              goto LAB_00430410;
            }
          }
          else {
            iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crlsec");
            if (iVar14 == 0) {
              ppiVar44 = (int **)((int)ppiVar44 + -1);
              if (ppiVar44 != (int **)0x0) {
                local_3b8 = (*(code *)PTR_strtol_006aaa68)(ppbVar42[1],0,10);
                ppbVar41 = ppbVar42 + 1;
                goto LAB_00430410;
              }
            }
            else {
              iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-infiles");
              if (iVar14 == 0) {
                ppiVar44 = (int **)((int)ppiVar44 + -1);
                ppbVar41 = ppbVar42 + 1;
                local_3f8 = (int *)0x1;
                goto LAB_00430448;
              }
              iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-ss_cert");
              if (iVar14 == 0) {
                ppiVar44 = (int **)((int)ppiVar44 + -1);
                if (ppiVar44 != (int **)0x0) {
                  local_3bc = (int *)ppbVar42[1];
                  local_3f8 = (int *)0x1;
                  ppbVar41 = ppbVar42 + 1;
                  goto LAB_00430410;
                }
              }
              else {
                iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-spkac");
                if (iVar14 == 0) {
                  ppiVar44 = (int **)((int)ppiVar44 + -1);
                  if (ppiVar44 != (int **)0x0) {
                    local_3e8 = (int *)ppbVar42[1];
                    local_3f8 = (int *)0x1;
                    ppbVar41 = ppbVar42 + 1;
                    goto LAB_00430410;
                  }
                }
                else {
                  iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-revoke");
                  if (iVar14 == 0) {
                    ppiVar44 = (int **)((int)ppiVar44 + -1);
                    if (ppiVar44 != (int **)0x0) {
                      local_3dc = ppbVar42[1];
                      bVar6 = true;
                      ppbVar41 = ppbVar42 + 1;
                      goto LAB_00430410;
                    }
                  }
                  else {
                    iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-extensions");
                    if (iVar14 == 0) {
                      ppiVar44 = (int **)((int)ppiVar44 + -1);
                      if (ppiVar44 != (int **)0x0) {
                        local_414 = (int *)ppbVar42[1];
                        ppbVar41 = ppbVar42 + 1;
                        goto LAB_00430410;
                      }
                    }
                    else {
                      iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-extfile");
                      if (iVar14 == 0) {
                        ppiVar44 = (int **)((int)ppiVar44 + -1);
                        if (ppiVar44 != (int **)0x0) {
                          local_3e0 = (int *)ppbVar42[1];
                          ppbVar41 = ppbVar42 + 1;
                          goto LAB_00430410;
                        }
                      }
                      else {
                        iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-status");
                        if (iVar14 == 0) {
                          ppiVar44 = (int **)((int)ppiVar44 + -1);
                          if (ppiVar44 != (int **)0x0) {
                            local_3e4 = ppbVar42[1];
                            ppbVar41 = ppbVar42 + 1;
                            goto LAB_00430410;
                          }
                        }
                        else {
                          iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-updatedb");
                          if (iVar14 == 0) {
                            local_3ac = (int *)0x1;
                            goto LAB_00430410;
                          }
                          iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crlexts");
                          if (iVar14 == 0) {
                            ppiVar44 = (int **)((int)ppiVar44 + -1);
                            if (ppiVar44 != (int **)0x0) {
                              local_3f0 = ppbVar42[1];
                              ppbVar41 = ppbVar42 + 1;
                              goto LAB_00430410;
                            }
                          }
                          else {
                            iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crl_reason");
                            if (iVar14 == 0) {
                              ppiVar44 = (int **)((int)ppiVar44 + -1);
                              if (ppiVar44 != (int **)0x0) {
                                local_3d4 = ppbVar42[1];
                                local_3d8 = 1;
                                ppbVar41 = ppbVar42 + 1;
                                goto LAB_00430410;
                              }
                            }
                            else {
                              iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crl_hold");
                              if (iVar14 == 0) {
                                ppiVar44 = (int **)((int)ppiVar44 + -1);
                                if (ppiVar44 != (int **)0x0) {
                                  local_3d4 = ppbVar42[1];
                                  local_3d8 = 2;
                                  ppbVar41 = ppbVar42 + 1;
                                  goto LAB_00430410;
                                }
                              }
                              else {
                                iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-crl_compromise");
                                if (iVar14 == 0) {
                                  ppiVar44 = (int **)((int)ppiVar44 + -1);
                                  if (ppiVar44 != (int **)0x0) {
                                    local_3d4 = ppbVar42[1];
                                    local_3d8 = 3;
                                    ppbVar41 = ppbVar42 + 1;
                                    goto LAB_00430410;
                                  }
                                }
                                else {
                                  iVar14 = (*(code *)PTR_strcmp_006aac20)
                                                     (pbVar29,"-crl_CA_compromise");
                                  if (iVar14 == 0) {
                                    ppiVar44 = (int **)((int)ppiVar44 + -1);
                                    if (ppiVar44 != (int **)0x0) {
                                      local_3d4 = ppbVar42[1];
                                      local_3d8 = 4;
                                      ppbVar41 = ppbVar42 + 1;
                                      goto LAB_00430410;
                                    }
                                  }
                                  else {
                                    iVar14 = (*(code *)PTR_strcmp_006aac20)(pbVar29,"-engine");
                                    if ((iVar14 == 0) &&
                                       (ppiVar44 = (int **)((int)ppiVar44 + -1),
                                       ppiVar44 != (int **)0x0)) {
                                      local_438 = ppbVar42[1];
                                      ppbVar41 = ppbVar42 + 1;
                                      goto LAB_00430410;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_00430804;
      }
      bVar5 = true;
LAB_00430410:
      ppiVar44 = (int **)((int)ppiVar44 + -1);
      ppbVar41 = ppbVar41 + 1;
    } while (ppiVar44 == (int **)0x0);
  } while( true );
LAB_004313b0:
  iVar16 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(pbVar40 + 4) + 4));
  if (iVar16 <= iVar14) goto LAB_00431a68;
  ppcVar20 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                (*(undefined4 *)(*(int *)(pbVar40 + 4) + 4),iVar14);
  if (**ppcVar20 == 'R') {
    iVar16 = make_revoked(0,ppcVar20[2]);
    if (iVar16 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8," in entry %d\n",iVar14 + 1);
      goto LAB_004314a8;
    }
  }
  else if (*ppcVar20[2] != '\0') {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: not revoked yet, but has a revocation date\n",
               iVar14 + 1);
    goto LAB_004314a8;
  }
  iVar16 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,ppcVar20[1]);
  if (iVar16 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: invalid expiry date\n",iVar14 + 1);
    goto LAB_004314a8;
  }
  pcVar35 = ppcVar20[3];
  uVar18 = (*(code *)PTR_strlen_006aab30)(pcVar35);
  pcVar34 = pcVar35;
  if (*pcVar35 == '-') {
    uVar18 = uVar18 - 1;
    pcVar34 = pcVar35 + 1;
  }
  if (((uVar18 & 1) != 0) || ((int)uVar18 < 2)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: bad serial number length (%d)\n",iVar14 + 1,uVar18);
    goto LAB_004314a8;
  }
  while( true ) {
    uVar18 = (uint)*pcVar34;
    if (uVar18 == 0) break;
    if ((9 < (uVar18 & 0xff) - 0x30) && (5 < (uVar18 & 0xdf) - 0x41)) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",iVar14 + 1
                 ,(int)pcVar34 - (int)pcVar35,uVar18);
      goto LAB_004314a8;
    }
    pcVar34 = pcVar34 + 1;
  }
  iVar14 = iVar14 + 1;
  goto LAB_004313b0;
LAB_00431a68:
  if (iVar36 != 0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(local_434,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
    (*(code *)PTR_TXT_DB_write_006a818c)(local_434,*(undefined4 *)(pbVar40 + 4));
    uVar32 = *(undefined4 *)puVar8;
    uVar17 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(pbVar40 + 4) + 4));
    (*(code *)PTR_BIO_printf_006a7f38)(uVar32,"%d entries loaded from the database\n",uVar17);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"generating index\n");
  }
  iVar14 = (*(code *)PTR_index_index_006a8170)(pbVar40);
  if (iVar14 == 0) {
LAB_004314a8:
    pcVar34 = (char *)0x0;
    pbVar29 = (byte *)0x0;
    puVar31 = (undefined1 *)0x0;
    iVar36 = 1;
    goto LAB_00430528;
  }
  if (local_3ac != (int *)0x0) {
    if (iVar36 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Updating %s ...\n",local_3e4);
    }
    uVar17 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
    piVar21 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(uVar17,0);
    iVar14 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*piVar21 + 1,&DAT_00635b2c,0xa44);
    if (iVar14 == 0) {
      (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar21);
      (*(code *)PTR_CRYPTO_free_006a7f88)(0);
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Malloc failure\n");
      goto LAB_004314a8;
    }
    (*(code *)PTR_memcpy_006aabf4)(iVar14,piVar21[2],*piVar21);
    puVar7 = PTR_strncmp_006aaa7c;
    local_3a0 = (int *)&DAT_00636944;
    *(undefined *)(iVar14 + *piVar21) = 0;
    local_3ac = (int *)(*(code *)puVar7)(iVar14,&DAT_00636944,2);
    local_44c = (undefined1 *)0x0;
    local_3a8 = "%s=Expired\n";
    for (local_3c4 = (byte *)0x0;
        iVar16 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(pbVar40 + 4) + 4)),
        (int)local_3c4 < iVar16; local_3c4 = local_3c4 + 1) {
      ppcVar20 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                    (*(undefined4 *)(*(int *)(pbVar40 + 4) + 4),local_3c4);
      pcVar34 = *ppcVar20;
      if (*pcVar34 == 'V') {
        pcVar35 = ppcVar20[1];
        iVar16 = (*(code *)PTR_strncmp_006aaa7c)(pcVar35,&DAT_00636944,2);
        if (iVar16 < 1) {
          if ((int)local_3ac < 1) {
LAB_00433c70:
            iVar16 = (*(code *)PTR_strcmp_006aac20)(pcVar35,iVar14);
            if (iVar16 < 1) {
              *pcVar34 = 'E';
              pcVar34 = *ppcVar20;
              goto LAB_00433bb8;
            }
          }
        }
        else {
          if (0 < (int)local_3ac) goto LAB_00433c70;
          *pcVar34 = 'E';
          pcVar34 = *ppcVar20;
LAB_00433bb8:
          puVar7 = PTR_BIO_printf_006a7f38;
          local_44c = (undefined1 *)((int)local_44c + 1);
          pcVar34[1] = '\0';
          (*(code *)puVar7)(*(undefined4 *)puVar8,"%s=Expired\n",ppcVar20[3]);
        }
      }
    }
    (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar21);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar14);
    local_39c = piVar21;
    if (local_44c == (undefined1 *)0x0) {
      if (iVar36 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"No entries found to mark expired\n");
      }
    }
    else {
      iVar14 = (*(code *)PTR_save_index_006a8190)(local_3e4,"new",pbVar40);
      if ((iVar14 == 0) ||
         (iVar14 = (*(code *)PTR_rotate_index_006a8194)(local_3e4,"new","old"), iVar14 == 0))
      goto LAB_004314a8;
      if (iVar36 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Done. %d entries marked as expired\n",local_44c);
      }
    }
  }
  if (local_3e0 != (int *)0x0) {
    extconf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar14 = (*(code *)PTR_NCONF_load_006a7f5c)(extconf,local_3e0,&local_368);
    if (0 < iVar14) {
      if (iVar36 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Successfully loaded extensions file %s\n",local_3e0);
      }
      if (local_414 == (int *)0x0) {
        piVar21 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)(extconf,"default","extensions");
        local_414 = (int *)0x66fa44;
        if (piVar21 != (int *)0x0) {
          local_414 = piVar21;
        }
      }
      goto LAB_00431d50;
    }
    uVar15 = *(undefined4 *)puVar8;
    if (0 < local_368) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (uVar15,"ERROR: on line %ld of config file \'%s\'\n",local_368,local_3e0);
      goto LAB_004320fc;
    }
    pcVar34 = "ERROR: loading the config file \'%s\'\n";
    piVar19 = local_3e0;
LAB_00432ce8:
    (*(code *)PTR_BIO_printf_006a7f38)(uVar15,pcVar34,piVar19);
LAB_004320fc:
    pcVar34 = (char *)0x0;
    pbVar29 = (byte *)0x0;
    puVar31 = (undefined1 *)0x0;
    iVar36 = 1;
    goto LAB_00430528;
  }
LAB_00431d50:
  if ((local_3f8 != (int *)0x0) || (bVar4)) {
    if (local_3c0 == (int *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(local_438,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
    }
    else {
      iVar14 = (*(code *)PTR_BIO_ctrl_006a7f18)(local_438,0x6c,5,local_3c0);
      if (iVar14 < 1) {
        (*(code *)PTR_perror_006aab88)(local_3c0);
        goto LAB_004320fc;
      }
    }
  }
  if ((local_3f4 == (int *)0x0) &&
     (local_3f4 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                   (conf,*(undefined4 *)(local_450 + -0x4df8),"default_md"),
     local_3f4 == (int *)0x0)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,"default_md");
    goto LAB_004320fc;
  }
  iVar14 = (*(code *)PTR_strcmp_006aac20)(local_3f4,"default");
  if (iVar14 == 0) {
    iVar14 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a8198)(local_440,local_348);
    if (iVar14 < 1) {
      (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar8,"no default digest\n");
      goto LAB_004320fc;
    }
    local_3f4 = (int *)(*(code *)PTR_OBJ_nid2sn_006a819c)(local_348[0]);
  }
  local_3e0 = (int *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(local_3f4);
  if (local_3e0 == (int *)0x0) {
    uVar15 = *(undefined4 *)puVar8;
    pcVar34 = "%s is an unsupported message digest type\n";
    piVar19 = local_3f4;
    goto LAB_00432ce8;
  }
  pcVar34 = (char *)0x0;
  if (local_3f8 == (int *)0x0) goto LAB_004330e0;
  if ((bVar3 != false) &&
     (pbVar29 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                  (conf,*(undefined4 *)(local_450 + -0x4df8),"email_in_dn"),
     pbVar29 != (byte *)0x0)) {
    iVar14 = 0x6e - (uint)*pbVar29;
    if ((iVar14 == 0) && (iVar14 = 0x6f - (uint)pbVar29[1], iVar14 == 0)) {
      iVar14 = -(uint)pbVar29[2];
    }
    bVar3 = iVar14 != 0;
  }
  if (iVar36 == 0) {
    if ((local_400 == (int *)0x0) &&
       (local_400 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                     (conf,*(undefined4 *)(local_450 + -0x4df8),"policy"),
       local_400 == (int *)0x0)) {
LAB_004339a0:
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",
                 *(undefined4 *)(local_450 + -0x4df8),"policy");
      goto LAB_004320fc;
    }
  }
  else {
    uVar32 = *(undefined4 *)puVar8;
    uVar17 = (*(code *)PTR_OBJ_nid2ln_006a821c)(*local_3e0);
    (*(code *)PTR_BIO_printf_006a7f38)(uVar32,"message digest is %s\n",uVar17);
    if ((local_400 == (int *)0x0) &&
       (local_400 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                     (conf,*(undefined4 *)(local_450 + -0x4df8),"policy"),
       local_400 == (int *)0x0)) goto LAB_004339a0;
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"policy is %s\n",local_400);
  }
  local_3c4 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                (conf,*(undefined4 *)(local_450 + -0x4df8),"serial");
  if (local_3c4 == (byte *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,"serial");
    goto LAB_004320fc;
  }
  if (extconf == 0) {
    if ((local_414 == (int *)0x0) &&
       (local_414 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,section,"x509_extensions"),
       local_414 == (int *)0x0)) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
    }
    else {
      (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_348,0,0,0,0,1);
      (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_348,conf);
      iVar14 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(conf,local_348,local_414,0);
      if (iVar14 == 0) {
        uVar15 = *(undefined4 *)puVar8;
        pcVar34 = "Error Loading extension section %s\n";
        piVar19 = local_414;
        goto LAB_00432ce8;
      }
    }
  }
  if (((int **)local_40c == (int **)0x0) &&
     (local_40c = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (conf,*(undefined4 *)(local_450 + -0x4df8),"default_startdate"),
     (int **)local_40c == (int **)0x0)) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    local_40c = "today";
  }
  else {
    iVar14 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,local_40c);
    if (iVar14 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
      goto LAB_004320fc;
    }
  }
  if ((local_408 == (int *)0x0) &&
     (local_408 = (int *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                   (conf,*(undefined4 *)(local_450 + -0x4df8),"default_enddate"),
     local_408 == (int *)0x0)) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  else {
    iVar14 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,local_408);
    if (iVar14 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
      goto LAB_004320fc;
    }
  }
  if (local_360 == (int *)0x0) {
    iVar14 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                       (conf,*(undefined4 *)(local_450 + -0x4df8),"default_days",&local_360);
    if (iVar14 == 0) {
      local_360 = (int *)0x0;
      piVar21 = local_408;
    }
    else {
      piVar21 = local_360;
      if (local_408 != (int *)0x0) goto LAB_00431ebc;
    }
    if (piVar21 == (int *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"cannot lookup how many days to certify for\n");
      goto LAB_004320fc;
    }
  }
LAB_00431ebc:
  local_364 = (int *)(*(code *)PTR_load_serial_006a81a0)(local_3c4,local_418,0);
  if (local_364 == (int *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"error while loading serial number\n");
    goto LAB_004320fc;
  }
  if (iVar36 != 0) {
    if (local_364[1] == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"next serial number is 00\n");
    }
    else {
      iVar14 = (*(code *)PTR_BN_bn2hex_006a8118)(local_364);
      if (iVar14 == 0) goto LAB_004320fc;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"next serial number is %s\n",iVar14);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar14);
    }
  }
  local_3f4 = (int *)(*(code *)PTR_NCONF_get_section_006a7fd4)(conf,local_400);
  if (local_3f4 == (int *)0x0) {
    uVar15 = *(undefined4 *)puVar8;
    pcVar34 = "unable to find \'section\' for %s\n";
    piVar19 = local_400;
    goto LAB_00432ce8;
  }
  pcVar34 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
  uVar17 = local_354;
  piVar12 = local_358;
  piVar11 = local_35c;
  piVar10 = local_360;
  piVar25 = local_364;
  piVar21 = conf;
  if (pcVar34 == (char *)0x0) {
    uVar15 = *(undefined4 *)puVar8;
    pcVar35 = "Memory allocation failure\n";
    goto LAB_004329a0;
  }
  if (local_3e8 == (int *)0x0) {
    local_3f8 = (int *)0x0;
    piVar21 = (int *)0x0;
    local_3ac = (int *)&SUB_00000002;
    local_3e8 = (int *)&SUB_00000002;
    local_400 = (int *)0x1;
    local_418 = (int *)0x1;
    piVar25 = (int *)0x0;
    goto LAB_00432364;
  }
  local_3a8 = (char *)local_360;
  local_3ac = local_364;
  local_3a0 = conf;
  local_39c = local_358;
  local_418 = (int *)(*(code *)PTR_CONF_load_006a81a4)(0,local_3e8,local_348);
  if (local_418 == (int *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"error on line %ld of %s\n",local_348[0],local_3e8);
    piVar27 = *(int **)puVar8;
    pcVar43 = (code *)PTR_ERR_print_errors_006a7f40;
LAB_00432c2c:
    pbVar29 = (byte *)0x0;
    (*pcVar43)(piVar27);
  }
  else {
    uVar32 = (*(code *)PTR_CONF_get_section_006a81a8)(local_418,"default");
    iVar14 = (*(code *)PTR_sk_num_006a7f2c)(uVar32);
    piVar27 = local_418;
    if (iVar14 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"no name/value pairs found in %s\n",local_3e8);
      (*(code *)PTR_CONF_free_006a81b4)(local_418);
      pcVar43 = (code *)PTR_CONF_free_006a81b4;
      goto LAB_00432c2c;
    }
    piVar22 = (int *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
    if (piVar22 == (int *)0x0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
      pcVar43 = (code *)PTR_CONF_free_006a81b4;
      goto LAB_00432c2c;
    }
    iVar14 = 0;
    local_400 = (int *)0x0;
    uVar23 = *(undefined4 *)(*piVar22 + 0x10);
    for (; iVar16 = (*(code *)PTR_sk_num_006a7f2c)(uVar32), puVar7 = PTR_bio_err_006a7f3c,
        local_3f8 = piVar22, (int)local_400 < iVar16; local_400 = (int *)((int)local_400 + 1)) {
      iVar16 = (*(code *)PTR_sk_value_006a7f24)(uVar32,local_400);
      pbVar26 = *(byte **)(iVar16 + 4);
      bVar2 = *pbVar26;
      pbVar29 = pbVar26;
      while (bVar2 != 0) {
        if ((bVar2 == 0x3a) || ((bVar2 & 0xfd) == 0x2c)) {
          if (pbVar29[1] != 0) {
            pbVar26 = pbVar29 + 1;
          }
          break;
        }
        pbVar29 = pbVar29 + 1;
        bVar2 = *pbVar29;
      }
      uVar28 = *(undefined4 *)(iVar16 + 8);
      iVar24 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pbVar26);
      if (iVar24 == 0) {
        iVar24 = (*(code *)PTR_strcmp_006aac20)(pbVar26,"SPKAC");
        if ((iVar24 == 0) &&
           (iVar14 = (*(code *)PTR_NETSCAPE_SPKI_b64_decode_006a81d4)
                               (*(undefined4 *)(iVar16 + 8),0xffffffff), iVar14 == 0)) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"unable to load Netscape SPKAC structure\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
          local_400 = (int *)0xffffffff;
          goto LAB_00432264;
        }
      }
      else {
        iVar16 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a806c)
                           (uVar23,iVar24,local_424,uVar28,0xffffffff,0xffffffff,0);
        if (iVar16 == 0) {
          local_400 = (int *)0xffffffff;
          goto LAB_00432264;
        }
      }
    }
    if (iVar14 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"Netscape SPKAC structure not found in %s\n",local_3e8);
      local_400 = (int *)0xffffffff;
    }
    else {
      local_3f8 = (int *)PTR_bio_err_006a7f3c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"Check that the SPKAC request matches the signature\n");
      iVar16 = (*(code *)PTR_NETSCAPE_SPKI_get_pubkey_006a81ac)(iVar14);
      if (iVar16 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"error unpacking SPKAC public key\n");
        local_400 = (int *)0xffffffff;
      }
      else {
        iVar24 = (*(code *)PTR_NETSCAPE_SPKI_verify_006a81b0)(iVar14,iVar16);
        if (iVar24 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar7,"signature verification failed on SPKAC public key\n");
          local_400 = (int *)0xffffffff;
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"Signature ok\n");
          (*(code *)PTR_X509_REQ_set_pubkey_006a8030)(piVar22,iVar16);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar16);
          local_400 = (int *)do_body(&local_350,local_440,pcVar37,local_3e0,local_420,local_3f4,
                                     pbVar40,piVar25,local_444,local_424,local_410,bVar3,local_40c,
                                     local_408,piVar10,1,iVar36,piVar22,local_414,piVar21,piVar12,
                                     piVar11,local_3c8,uVar17,0);
        }
      }
    }
LAB_00432264:
    (*(code *)PTR_X509_REQ_free_006a7f8c)(piVar22);
    (*(code *)PTR_CONF_free_006a81b4)(local_418);
    if (iVar14 != 0) {
      (*(code *)PTR_NETSCAPE_SPKI_free_006a81b8)(iVar14);
      local_418 = local_400;
    }
    pbVar29 = (byte *)0x0;
    if (-1 < (int)local_400) {
      if (local_400 != (int *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
        iVar14 = (*(code *)PTR_BN_add_word_006a81bc)(local_364,1);
        if (iVar14 == 0) goto LAB_004322e4;
        iVar14 = (*(code *)PTR_sk_push_006a80a8)(pcVar34,local_350);
        if (iVar14 != 0) {
          piVar21 = (int *)0x1;
          local_3ac = (int *)0x3;
          local_3e8 = (int *)0x3;
          if (local_3c0 != (int *)0x0) {
            local_3ec = 1;
          }
          local_400 = (int *)&SUB_00000002;
          local_418 = (int *)&SUB_00000002;
          local_3f8 = (int *)(uint)(local_3c0 != (int *)0x0);
          piVar25 = (int *)0x1;
          goto LAB_00432364;
        }
LAB_0043298c:
        pcVar35 = "Memory allocation failure\n";
        uVar15 = *(undefined4 *)PTR_bio_err_006a7f3c;
LAB_004329a0:
        pbVar29 = (byte *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar15,pcVar35);
        puVar31 = (undefined1 *)0x0;
        iVar36 = 1;
        goto LAB_00430528;
      }
      local_3f8 = (int *)0x0;
      piVar21 = (int *)0x0;
      local_3ac = (int *)&SUB_00000002;
      local_3e8 = (int *)0x3;
      local_400 = (int *)0x1;
      local_418 = (int *)&SUB_00000002;
      piVar25 = (int *)0x1;
LAB_00432364:
      uVar17 = local_354;
      piVar13 = local_358;
      piVar22 = local_35c;
      piVar27 = local_360;
      piVar12 = local_364;
      piVar11 = local_400;
      piVar10 = conf;
      piVar33 = local_418;
      if (local_3bc == (int *)0x0) goto LAB_004324fc;
      local_3c0 = local_364;
      local_3bc = local_360;
      local_3a8 = (char *)conf;
      local_3a0 = local_358;
      local_39c = local_35c;
      iVar14 = (*(code *)PTR_load_cert_006a8178)(*(undefined4 *)puVar8,piVar19,3,0,uVar15,piVar19);
      if (iVar14 != 0) {
        if (iVar36 != 0) {
          (*(code *)PTR_X509_print_006a81c0)(*(undefined4 *)PTR_bio_err_006a7f3c,iVar14);
        }
        puVar7 = PTR_bio_err_006a7f3c;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Check that the request matches the signature\n");
        iVar16 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar14);
        if (iVar16 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"error unpacking public key\n");
          local_3c0 = (int *)0xffffffff;
        }
        else {
          iVar24 = (*(code *)PTR_X509_verify_006a81c4)(iVar14,iVar16);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar16);
          if (iVar24 < 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar7,"Signature verification problems....\n");
            local_3c0 = (int *)0x0;
          }
          else if (iVar24 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar7,"Signature did not match the certificate\n");
            local_3c0 = (int *)0x0;
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"Signature ok\n");
            uVar32 = (*(code *)PTR_EVP_md5_006a81c8)();
            iVar16 = (*(code *)PTR_X509_to_X509_REQ_006a81cc)(iVar14,0,uVar32);
            if (iVar16 == 0) {
              local_3c0 = (int *)0xffffffff;
            }
            else {
              local_3c0 = (int *)do_body(&local_350,local_440,pcVar37,local_3e0,local_420,local_3f4,
                                         pbVar40,piVar12,local_444,local_424,local_410,bVar3,
                                         local_40c,local_408,piVar27,local_3ec,iVar36,iVar16,
                                         local_414,piVar10,piVar13,piVar22,local_3c8,uVar17,0);
              (*(code *)PTR_X509_REQ_free_006a7f8c)(iVar16);
            }
          }
        }
        (*(code *)PTR_X509_free_006a7f90)(iVar14);
        if (-1 < (int)local_3c0) {
          piVar33 = local_3e8;
          piVar25 = local_418;
          if (local_3c0 != (int *)0x0) {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
            iVar14 = (*(code *)PTR_BN_add_word_006a81bc)(local_364,1);
            if (iVar14 == 0) goto LAB_004322e4;
            iVar14 = (*(code *)PTR_sk_push_006a80a8)(pcVar34,local_350);
            if (iVar14 == 0) goto LAB_0043298c;
            local_400 = local_3ac;
            piVar21 = piVar11;
          }
LAB_004324fc:
          local_418 = piVar25;
          piVar19 = local_418;
          if (local_3dc != (byte *)0x0) {
            iVar14 = certify(&local_350,local_3dc,local_440,local_3b4,local_3e0,local_420,local_3f4,
                             pbVar40,local_364,local_444,local_424,local_410,bVar3,local_40c,
                             local_408,local_360,local_3ec,local_414,conf,iVar36,local_358,local_35c
                             ,local_3c8,local_354,local_3d0);
            if (iVar14 < 0) goto LAB_004322e4;
            piVar19 = piVar33;
            if (iVar14 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
              iVar14 = (*(code *)PTR_BN_add_word_006a81bc)(local_364,1);
              if (iVar14 == 0) goto LAB_004322e4;
              iVar14 = (*(code *)PTR_sk_push_006a80a8)(pcVar34,local_350);
              piVar21 = local_400;
              if (iVar14 == 0) goto LAB_0043298c;
            }
          }
          local_418 = (int *)((int)piVar19 + (int)ppiVar44);
          piVar25 = piVar19;
          if (0 < (int)ppiVar44) {
            ppiVar44 = &local_350;
            local_400 = (int *)0x63bac8;
            do {
              piVar19 = (int *)((int)piVar19 + 1);
              iVar14 = certify(ppiVar44,*ppbVar41,local_440,local_3b4,local_3e0,local_420,local_3f4,
                               pbVar40,local_364,local_444,local_424,local_410,bVar3,local_40c,
                               local_408,local_360,local_3ec,local_414,conf,iVar36,local_358,
                               local_35c,local_3c8,local_354,local_3d0);
              if (iVar14 < 0) goto LAB_004322e4;
              if (iVar14 != 0) {
                piVar21 = (int *)((int)piVar21 + 1);
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
                iVar14 = (*(code *)PTR_BN_add_word_006a81bc)(local_364,1);
                if (iVar14 == 0) goto LAB_004322e4;
                iVar14 = (*(code *)PTR_sk_push_006a80a8)(pcVar34,local_350);
                if (iVar14 == 0) goto LAB_0043298c;
              }
              ppbVar41 = ppbVar41 + 1;
              piVar25 = local_418;
            } while (local_418 != piVar19);
          }
          local_418 = piVar25;
          iVar14 = (*(code *)PTR_sk_num_006a7f2c)(pcVar34);
          puVar7 = PTR_bio_err_006a7f3c;
          if (0 < iVar14) {
            if (local_3ec == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,
                         "\n%d out of %d certificate requests certified, commit? [y/n]",piVar21,
                         local_418);
              (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar8,0xb,0,0);
              local_32c[0] = local_32c[0] & 0xffffff;
              iVar14 = (*(code *)PTR_fgets_006aabe8)(local_32c,10,*(undefined4 *)PTR_stdin_006aab20)
              ;
              if (iVar14 == 0) {
                uVar15 = *(undefined4 *)puVar7;
                pcVar35 = "CERTIFICATION CANCELED: I/O error\n";
              }
              else {
                if ((local_32c[0]._0_1_ & 0xdf) == 0x59) goto LAB_00432a08;
                uVar15 = *(undefined4 *)puVar7;
                pcVar35 = "CERTIFICATION CANCELED\n";
              }
              pbVar29 = (byte *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar15,pcVar35);
              goto LAB_0043280c;
            }
LAB_00432a08:
            uVar32 = *(undefined4 *)puVar8;
            uVar17 = (*(code *)PTR_sk_num_006a7f2c)(pcVar34);
            (*(code *)PTR_BIO_printf_006a7f38)
                      (uVar32,"Write out database with %d new entries\n",uVar17);
            iVar14 = (*(code *)PTR_save_serial_006a81d0)(local_3c4,"new",local_364,0);
            if ((iVar14 == 0) ||
               (iVar14 = (*(code *)PTR_save_index_006a8190)(local_3e4,"new",pbVar40), iVar14 == 0))
            goto LAB_004322e4;
          }
          if (iVar36 != 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"writing new certificates\n");
          }
          local_424 = &DAT_0063ba98;
          local_418 = (int *)&DAT_00635448;
          local_414 = (int *)0x630000;
          for (iVar14 = 0; iVar16 = (*(code *)PTR_sk_num_006a7f2c)(pcVar34), ppbVar41 = local_430,
              local_444 = (byte *)pcVar37, iVar14 < iVar16; iVar14 = iVar14 + 1) {
            local_350 = (int *)(*(code *)PTR_sk_value_006a7f24)(pcVar34,iVar14);
            ppiVar44 = (int **)**(byte ***)(*local_350 + 4);
            ppiVar38 = (int **)(*(byte ***)(*local_350 + 4))[2];
            uVar18 = (*(code *)PTR_strlen_006aab30)(local_404);
            if (ppiVar44 == (int **)0x0) {
              if (0xf7 < uVar18) goto LAB_00433018;
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_12c,local_404,uVar18 + 1,0x100);
              (*(code *)PTR_BUF_strlcat_006a8068)(auStack_12c,&DAT_0063ba98,0x100);
              iVar16 = (*(code *)PTR_strlen_006aab30)(auStack_12c);
              piVar19 = (int *)(auStack_12c + iVar16);
LAB_00432f54:
              piVar21 = (int *)((int)piVar19 + 2);
              auStack_12c[iVar16] = 0x30;
              *(byte *)((int)piVar19 + 1) = 0x30;
            }
            else {
              if ((uint)((0x7d - (int)ppiVar44) * 2) <= uVar18) {
LAB_00433018:
                uVar15 = *(undefined4 *)puVar8;
                pcVar35 = "certificate file name too long\n";
                goto LAB_004329a0;
              }
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_12c,local_404,uVar18 + 1,0x100);
              (*(code *)PTR_BUF_strlcat_006a8068)(auStack_12c,&DAT_0063ba98,0x100);
              iVar16 = (*(code *)PTR_strlen_006aab30)(auStack_12c);
              piVar21 = (int *)(auStack_12c + iVar16);
              piVar19 = piVar21;
              if ((int)ppiVar44 < 1) goto LAB_00432f54;
              if (piVar21 < &local_2c) {
                local_40c = (char *)((int)ppiVar38 + (int)ppiVar44);
                ppiVar44 = (int **)((int)ppiVar38 +
                                   ((uint)((int)&local_2c + (1 - (int)(auStack_12c + iVar16 + 2)))
                                   >> 1) + 1);
                piVar25 = (int *)(auStack_12c + iVar16 + 2);
                do {
                  piVar21 = piVar25;
                  ppiVar39 = (int **)((int)ppiVar38 + 1);
                  (*(code *)PTR_BIO_snprintf_006a8060)
                            (piVar19,(int)&local_2c - (int)piVar19,&DAT_00635448,*(byte *)ppiVar38);
                  local_410 = &local_2c;
                  local_408 = piVar21;
                  if (ppiVar39 == (int **)local_40c) break;
                  piVar19 = piVar21;
                  piVar25 = (int *)((int)piVar21 + 2);
                  ppiVar38 = ppiVar39;
                } while (ppiVar44 != ppiVar39);
              }
            }
            piVar27 = (int *)auStack_12c;
            *(byte *)(piVar21 + 1) = 0;
            *(byte *)piVar21 = 0x2e;
            *(byte *)((int)piVar21 + 1) = 0x70;
            *(byte *)((int)piVar21 + 2) = 0x65;
            *(byte *)((int)piVar21 + 3) = 0x6d;
            if (iVar36 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"writing %s\n",piVar27);
            }
            iVar16 = (*(code *)PTR_BIO_ctrl_006a7f18)(local_430,0x6c,5,piVar27);
            piVar19 = local_350;
            pcVar43 = (code *)PTR_perror_006aab88;
            if (iVar16 < 1) goto LAB_00432c2c;
            if (bVar5) {
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(local_430,local_350);
              piVar19 = local_350;
              if (local_3f8 == (int *)0x0) goto LAB_00432ffc;
LAB_00433030:
              (*(code *)PTR_i2d_X509_bio_006a801c)(local_438,local_350);
            }
            else {
              (*(code *)PTR_X509_print_006a81c0)(local_430,local_350);
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(local_430,piVar19);
              piVar19 = local_350;
              if (local_3f8 != (int *)0x0) goto LAB_00433030;
              (*(code *)PTR_X509_print_006a81c0)(local_438,local_350);
LAB_00432ffc:
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(local_438,piVar19);
            }
          }
          iVar14 = (*(code *)PTR_sk_num_006a7f2c)(pcVar34);
          if (iVar14 != 0) {
            iVar14 = (*(code *)PTR_rotate_serial_006a8218)(local_3c4,"new","old");
            if ((iVar14 == 0) ||
               (iVar14 = (*(code *)PTR_rotate_index_006a8194)(local_3e4,"new","old"), iVar14 == 0))
            goto LAB_004322e4;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Data Base Updated\n");
          }
LAB_004330e0:
          pbVar29 = (byte *)0x0;
          if (bVar4) {
            if ((local_3f0 == (byte *)0x0) &&
               (local_3f0 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                              (conf,*(undefined4 *)(local_450 + -0x4df8),
                                               "crl_extensions"), local_3f0 == (byte *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_348,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_348,conf);
              iVar14 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(conf,local_348,local_3f0,0);
              if (iVar14 == 0) {
                pbVar29 = (byte *)0x0;
                puVar31 = (undefined1 *)0x0;
                iVar36 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Error Loading CRL extension section %s\n",
                           local_3f0);
                goto LAB_00430528;
              }
            }
            local_444 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (conf,*(undefined4 *)(local_450 + -0x4df8),"crlnumber");
            if (local_444 == (byte *)0x0) {
              puVar31 = (undefined1 *)0x0;
            }
            else {
              puVar31 = (undefined1 *)(*(code *)PTR_load_serial_006a81a0)(local_444,0,0);
              if (puVar31 == (undefined1 *)0x0) {
                pbVar29 = (byte *)0x0;
                iVar36 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"error while loading CRL number\n");
                goto LAB_00430528;
              }
            }
            if (((local_370 == 0) && (local_36c == 0)) && (local_3b8 == 0)) {
              iVar14 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                 (conf,*(undefined4 *)(local_450 + -0x4df8),"default_crl_days",
                                  &local_370);
              if (iVar14 == 0) {
                local_370 = 0;
              }
              iVar14 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                 (conf,*(undefined4 *)(local_450 + -0x4df8),"default_crl_hours",
                                  &local_36c);
              if (iVar14 == 0) {
                local_36c = 0;
              }
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              if ((local_370 == 0) && (local_36c == 0)) {
                pbVar29 = (byte *)0x0;
                iVar36 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,
                           "cannot lookup how long until the next CRL is issued\n");
                goto LAB_00430528;
              }
            }
            if (iVar36 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"making CRL\n");
            }
            pbVar29 = (byte *)(*(code *)PTR_X509_CRL_new_006a81d8)();
            if (pbVar29 == (byte *)0x0) goto LAB_004322ec;
            uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(pcVar37);
            iVar14 = (*(code *)PTR_X509_CRL_set_issuer_name_006a81dc)(pbVar29,uVar17);
            if ((iVar14 == 0) ||
               (ppbVar41 = (byte **)(*(code *)PTR_ASN1_TIME_new_006a81e0)(),
               ppbVar41 == (byte **)0x0)) goto LAB_004322ec;
            (*(code *)PTR_X509_gmtime_adj_006a808c)(ppbVar41,0);
            (*(code *)PTR_X509_CRL_set_lastUpdate_006a81e4)(pbVar29,ppbVar41);
            iVar14 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                               (ppbVar41,local_370,local_36c * 0xe10 + local_3b8,0);
            if (iVar14 == 0) {
              iVar36 = 1;
              (*(code *)PTR_BIO_puts_006a8058)
                        (*(undefined4 *)puVar8,"error setting CRL nextUpdate\n");
              goto LAB_00430528;
            }
            ppiVar44 = &local_364;
            (*(code *)PTR_X509_CRL_set_nextUpdate_006a81e8)(pbVar29,ppbVar41);
            (*(code *)PTR_ASN1_TIME_free_006a8150)(ppbVar41);
            local_418 = (int *)0x0;
            for (local_424 = (undefined *)0x0;
                iVar14 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(pbVar40 + 4) + 4)),
                local_450 = puVar31, (int)local_424 < iVar14; local_424 = local_424 + 1) {
              ppcVar20 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                            (*(undefined4 *)(*(int *)(pbVar40 + 4) + 4),local_424);
              if (**ppcVar20 == 'R') {
                ppbVar41 = (byte **)(*(code *)PTR_X509_REVOKED_new_006a81ec)();
                if ((ppbVar41 == (byte **)0x0) ||
                   (iVar14 = make_revoked(ppbVar41,ppcVar20[2]), iVar14 == 0)) {
LAB_004336fc:
                  iVar36 = 1;
                  goto LAB_00430528;
                }
                if (iVar14 == 2) {
                  local_418 = (int *)0x1;
                }
                iVar14 = (*(code *)PTR_BN_hex2bn_006a81f0)(ppiVar44,ppcVar20[3]);
                if (iVar14 == 0) goto LAB_004336fc;
                iVar14 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(local_364,0);
                (*(code *)PTR_BN_free_006a811c)(local_364);
                local_364 = (int *)0x0;
                if (iVar14 == 0) goto LAB_004336fc;
                (*(code *)PTR_X509_REVOKED_set_serialNumber_006a81f8)(ppbVar41,iVar14);
                (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar14);
                (*(code *)PTR_X509_CRL_add0_revoked_006a81fc)(pbVar29,ppbVar41);
              }
            }
            (*(code *)PTR_X509_CRL_sort_006a8200)(pbVar29);
            if (iVar36 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"signing CRL\n");
            }
            if (local_3f0 == (byte *)0x0) {
              if (local_444 == (byte *)0x0) {
                if (local_418 != (int *)0x0) goto LAB_004336c0;
              }
              else {
                (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_348,pcVar37,0,0,pbVar29,0);
                (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_348,conf);
LAB_004334bc:
                iVar36 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(puVar31,0);
                if (iVar36 == 0) goto LAB_004322ec;
                (*(code *)PTR_X509_CRL_add1_ext_i2d_006a820c)(pbVar29,0x58,iVar36,0,0);
                (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar36);
                iVar36 = (*(code *)PTR_BN_add_word_006a81bc)(puVar31,1);
                if ((iVar36 == 0) ||
                   (iVar36 = (*(code *)PTR_X509_CRL_set_version_006a8208)(pbVar29,1), iVar36 == 0))
                goto LAB_004322ec;
                if (local_444 != (byte *)0x0) {
                  iVar36 = (*(code *)PTR_save_serial_006a81d0)(local_444,"new",puVar31,0);
                  goto joined_r0x0043355c;
                }
              }
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_348,pcVar37,0,0,pbVar29,0);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_348,conf);
              iVar36 = (*(code *)PTR_X509V3_EXT_CRL_add_nconf_006a8204)
                                 (conf,local_348,local_3f0,pbVar29);
              ppbVar41 = local_448;
              if (iVar36 == 0) goto LAB_004322ec;
              if (local_444 != (byte *)0x0) goto LAB_004334bc;
LAB_004336c0:
              iVar36 = (*(code *)PTR_X509_CRL_set_version_006a8208)(pbVar29,1);
joined_r0x0043355c:
              if (iVar36 == 0) goto LAB_004322ec;
            }
            if (puVar31 != (undefined1 *)0x0) {
              (*(code *)PTR_BN_free_006a811c)(puVar31);
            }
            iVar36 = do_X509_CRL_sign(*(undefined4 *)puVar8,pbVar29,local_440,local_3e0,local_420);
            if ((iVar36 == 0) ||
               (((*(code *)PTR_PEM_write_bio_X509_CRL_006a8214)(local_438,pbVar29),
                local_444 != (byte *)0x0 &&
                (iVar36 = (*(code *)PTR_rotate_serial_006a8218)(local_444,"new","old"), iVar36 == 0)
                ))) goto LAB_004322e8;
          }
          if (!bVar6) {
LAB_0043280c:
            puVar31 = (undefined1 *)0x0;
            iVar36 = 0;
            goto LAB_00430528;
          }
          if (local_3dc == (byte *)0x0) {
            puVar31 = (undefined1 *)0x0;
            iVar36 = 1;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"no input files\n");
            goto LAB_00430528;
          }
          iVar36 = (*(code *)PTR_load_cert_006a8178)
                             (*(undefined4 *)puVar8,local_3dc,3,0,uVar15,local_3dc);
          if ((iVar36 != 0) && (iVar14 = do_revoke(iVar36,pbVar40,local_3d8,local_3d4), 0 < iVar14))
          {
            (*(code *)PTR_X509_free_006a7f90)(iVar36);
            iVar36 = (*(code *)PTR_save_index_006a8190)(local_3e4,"new",pbVar40);
            if ((iVar36 != 0) &&
               (iVar36 = (*(code *)PTR_rotate_index_006a8194)(local_3e4,"new","old"), iVar36 != 0))
            {
              puVar31 = (undefined1 *)0x0;
              iVar36 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)PTR_bio_err_006a7f3c,"Data Base Updated\n");
              goto LAB_00430528;
            }
          }
          goto LAB_004322e8;
        }
      }
LAB_004322e4:
      pbVar29 = (byte *)0x0;
    }
  }
LAB_004322e8:
  puVar31 = (undefined1 *)0x0;
LAB_004322ec:
  iVar36 = 1;
  goto LAB_00430528;
}

