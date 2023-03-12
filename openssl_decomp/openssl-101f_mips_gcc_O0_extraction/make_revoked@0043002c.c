
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int make_revoked(int param_1)

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
  undefined4 ******ppppppuVar10;
  undefined4 ******ppppppuVar11;
  undefined4 ******ppppppuVar12;
  undefined4 ******ppppppuVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  int *piVar20;
  char **ppcVar21;
  byte *pbVar22;
  undefined4 uVar23;
  int iVar24;
  undefined4 ******ppppppuVar25;
  undefined4 *******pppppppuVar26;
  byte *pbVar27;
  undefined4 ******ppppppuVar28;
  undefined4 uVar29;
  undefined4 ******ppppppuVar30;
  uint *puVar31;
  undefined4 *****pppppuVar32;
  undefined1 *puVar33;
  undefined4 uVar34;
  undefined4 ******ppppppuVar35;
  undefined4 ******ppppppuVar36;
  char *pcVar37;
  char *pcVar38;
  char *pcVar39;
  undefined4 ******ppppppuVar40;
  undefined4 ******ppppppuVar41;
  undefined4 *******pppppppuVar42;
  code *pcVar43;
  undefined4 ******ppppppuVar44;
  undefined1 *puStack_498;
  undefined1 *puStack_494;
  undefined4 *******pppppppuStack_490;
  undefined4 ******ppppppuStack_48c;
  char *pcStack_488;
  int iStack_484;
  undefined4 ******ppppppuStack_480;
  int iStack_47c;
  undefined4 *******pppppppuStack_478;
  int iStack_474;
  int iStack_470;
  undefined *puStack_46c;
  int iStack_468;
  undefined4 ******ppppppuStack_460;
  undefined4 ******ppppppuStack_45c;
  undefined4 ******ppppppuStack_458;
  char *pcStack_454;
  undefined4 ******ppppppuStack_450;
  undefined4 ******ppppppuStack_44c;
  undefined4 ******ppppppuStack_448;
  int *piStack_440;
  undefined4 ******ppppppuStack_43c;
  undefined4 ******ppppppuStack_438;
  int iStack_434;
  undefined4 ******ppppppuStack_430;
  undefined4 ******ppppppuStack_42c;
  undefined4 ******ppppppuStack_428;
  undefined4 ******ppppppuStack_424;
  undefined4 uStack_420;
  undefined4 ******ppppppuStack_41c;
  int iStack_418;
  undefined4 ******ppppppuStack_410;
  undefined4 ******ppppppuStack_40c;
  undefined4 ******ppppppuStack_408;
  undefined4 ******ppppppuStack_404;
  int iStack_400;
  undefined4 ******ppppppuStack_3fc;
  undefined4 ******ppppppuStack_3f4;
  char *pcStack_3f0;
  undefined4 ******ppppppuStack_3e8;
  undefined4 ******ppppppuStack_3e4;
  undefined4 ******ppppppuStack_3bc;
  int iStack_3b8;
  int iStack_3b4;
  int iStack_3b0;
  undefined4 ******ppppppuStack_3ac;
  undefined4 ******ppppppuStack_3a8;
  undefined4 ******ppppppuStack_3a4;
  undefined4 ******ppppppuStack_3a0;
  undefined4 uStack_39c;
  undefined4 *****pppppuStack_398;
  undefined4 uStack_394;
  undefined4 auStack_390 [7];
  uint auStack_374 [3];
  char *pcStack_368;
  undefined4 uStack_364;
  undefined4 uStack_360;
  uint auStack_35c [122];
  undefined auStack_174 [256];
  undefined4 *****apppppuStack_74 [2];
  int iStack_6c;
  int iStack_68;
  undefined4 *******local_24;
  int local_20;
  int local_1c;
  undefined4 *******local_18;
  int local_14;
  
  apppppuStack_74[1] = (undefined4 *****)PTR___stack_chk_guard_006aabf0;
  pppppppuVar26 = &local_24;
  local_20 = 0;
  local_24 = (undefined4 *******)0xffffffff;
  local_1c = 0;
  local_18 = (undefined4 *******)0x0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar14 = unpack_revinfo(&local_18,pppppppuVar26,&local_20,&local_1c);
  if (iVar14 == 0) {
LAB_004300f4:
    iStack_68 = 0;
    iStack_6c = 0;
    goto LAB_00430100;
  }
  if (param_1 == 0) {
    iStack_68 = 0;
  }
  else {
    pppppppuVar26 = local_18;
    iVar14 = (*(code *)PTR_X509_REVOKED_set_revocationDate_006a8140)(param_1);
    if (iVar14 == 0) goto LAB_004300f4;
    if (local_24 != (undefined4 *******)0xffffffff) {
      iStack_68 = (*(code *)PTR_ASN1_ENUMERATED_new_006a8144)();
      if ((iStack_68 != 0) &&
         (pppppppuVar26 = local_24, iVar14 = (*(code *)PTR_ASN1_ENUMERATED_set_006a8148)(iStack_68),
         iVar14 != 0)) {
        pppppppuVar26 = (undefined4 *******)0x8d;
        iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a8154)(param_1,0x8d,iStack_68,0);
        if (iVar14 == 0) {
          iStack_6c = 0;
          goto LAB_00430100;
        }
        goto LAB_0043018c;
      }
LAB_004300e8:
      iStack_6c = 0;
      goto LAB_00430100;
    }
    iStack_68 = 0;
LAB_0043018c:
    if (local_1c != 0) {
      pppppppuVar26 = (undefined4 *******)0x8e;
      iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a8154)(param_1,0x8e,local_1c,0);
      if (iVar14 == 0) goto LAB_004300e8;
    }
    if (local_20 != 0) {
      pppppppuVar26 = (undefined4 *******)&DAT_000001ae;
      iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a8154)(param_1,0x1ae,local_20,0);
      if (iVar14 == 0) {
        iStack_6c = 0;
        goto LAB_00430100;
      }
    }
  }
  iStack_6c = 1;
  if (local_24 != (undefined4 *******)0xffffffff) {
    iStack_6c = 2;
  }
LAB_00430100:
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(local_20);
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(local_1c);
  (*(code *)PTR_ASN1_ENUMERATED_free_006a814c)(iStack_68);
  (*(code *)PTR_ASN1_TIME_free_006a8150)(local_18);
  if ((undefined4 ****)local_14 == *apppppuStack_74[1]) {
    return iStack_6c;
  }
  iVar14 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar9 = PTR___stack_chk_guard_006aabf0;
  puVar8 = PTR_bio_err_006a7f3c;
  iStack_3b0 = -1;
  ppppppuStack_3bc = (undefined4 ******)0x0;
  iStack_3b8 = 0;
  iStack_3b4 = 0;
  ppppppuStack_3ac = (undefined4 ******)0x0;
  ppppppuStack_3a8 = (undefined4 ******)0x0;
  ppppppuStack_3a4 = (undefined4 ******)0x0;
  ppppppuStack_3a0 = (undefined4 ******)0x0;
  uStack_39c = 0;
  pppppuStack_398 = (undefined4 *****)0x0;
  apppppuStack_74[0] = *(undefined4 ******)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  ppppppuStack_3bc = (undefined4 ******)0x0;
  pppppppuStack_490 = (undefined4 *******)&_ITM_registerTMCloneTable;
  conf = (undefined4 ******)0x0;
  puStack_498 = &_ITM_registerTMCloneTable;
  ppppppuStack_3e4 = (undefined4 ******)&_ITM_registerTMCloneTable;
  ppppppuStack_3e8 = (undefined4 ******)&_ITM_registerTMCloneTable;
  section = 0;
  preserve = 0;
  msie_hack = 0;
  if (*(int *)puVar8 == 0) {
    uVar16 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar15 = (*(code *)PTR_BIO_new_006a7fa4)(uVar16);
    *(int *)puVar8 = iVar15;
    if (iVar15 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar15,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  ppppppuVar44 = (undefined4 ******)(iVar14 + -1);
  ppppppuStack_480 = (undefined4 ******)0x0;
  pppppppuVar26 = pppppppuVar26 + 1;
  if ((int)ppppppuVar44 < 1) {
    iStack_418 = 0;
    bVar5 = false;
    ppppppuVar41 = (undefined4 ******)0x0;
    iStack_434 = 0;
    iVar14 = 0;
    puStack_46c = (undefined *)0x1001;
    ppppppuStack_450 = (undefined4 ******)0x0;
    pcStack_454 = (char *)0x0;
    pcStack_3f0 = (char *)0x3;
    ppppppuStack_41c = (undefined4 ******)0x0;
    uStack_420 = 0;
    ppppppuStack_438 = (undefined4 ******)0x0;
    ppppppuStack_458 = (undefined4 ******)0x0;
    ppppppuStack_48c = (undefined4 ******)0x0;
    ppppppuStack_428 = (undefined4 ******)0x0;
    ppppppuStack_45c = (undefined4 ******)0x0;
    ppppppuStack_44c = (undefined4 ******)0x0;
    ppppppuStack_408 = (undefined4 ******)0x0;
    ppppppuStack_42c = (undefined4 ******)0x0;
    ppppppuStack_404 = (undefined4 ******)0x0;
    ppppppuStack_430 = (undefined4 ******)0x0;
    ppppppuStack_424 = (undefined4 ******)0x0;
    ppppppuStack_40c = (undefined4 ******)0x0;
    ppppppuStack_410 = (undefined4 ******)0x0;
    ppppppuStack_448 = (undefined4 ******)0x0;
    ppppppuStack_43c = (undefined4 ******)0x0;
    iStack_400 = 0;
    ppppppuStack_3f4 = (undefined4 ******)0x0;
    bVar6 = false;
    bVar4 = false;
    bVar3 = true;
    ppppppuStack_460 = (undefined4 ******)0x0;
    ppppppuStack_3fc = (undefined4 ******)0x0;
    iStack_468 = 0;
    piStack_440 = (int *)0x0;
    goto LAB_00430448;
  }
  iStack_468 = 0;
  iStack_418 = 0;
  bVar5 = false;
  puStack_46c = (undefined *)0x1001;
  iStack_434 = 0;
  ppppppuVar41 = (undefined4 ******)0x0;
  ppppppuStack_450 = (undefined4 ******)0x0;
  iVar14 = 0;
  pcStack_3f0 = (char *)0x3;
  pcStack_454 = (char *)0x0;
  puVar33 = (undefined1 *)0x630000;
  ppppppuStack_41c = (undefined4 ******)0x0;
  pcVar37 = "-config";
  bVar3 = true;
  uStack_420 = 0;
  pcVar39 = "-name";
  ppppppuStack_438 = (undefined4 ******)0x0;
  ppppppuStack_458 = (undefined4 ******)0x0;
  ppppppuStack_48c = (undefined4 ******)0x0;
  ppppppuStack_428 = (undefined4 ******)0x0;
  ppppppuStack_45c = (undefined4 ******)0x0;
  ppppppuStack_44c = (undefined4 ******)0x0;
  ppppppuStack_408 = (undefined4 ******)0x0;
  ppppppuStack_42c = (undefined4 ******)0x0;
  ppppppuStack_404 = (undefined4 ******)0x0;
  ppppppuStack_430 = (undefined4 ******)0x0;
  ppppppuStack_424 = (undefined4 ******)0x0;
  ppppppuStack_40c = (undefined4 ******)0x0;
  ppppppuStack_410 = (undefined4 ******)0x0;
  ppppppuStack_448 = (undefined4 ******)0x0;
  ppppppuStack_43c = (undefined4 ******)0x0;
  iStack_400 = 0;
  ppppppuStack_3f4 = (undefined4 ******)0x0;
  bVar6 = false;
  bVar4 = false;
  piStack_440 = (int *)0x0;
  ppppppuStack_460 = (undefined4 ******)0x0;
  ppppppuStack_3fc = (undefined4 ******)0x0;
  puStack_494 = (undefined1 *)0x630000;
  pcStack_488 = "-utf8";
  iStack_484 = 0x630000;
  do {
    do {
      ppppppuVar30 = *pppppppuVar26;
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,puVar33 + 0x2894);
      if (iVar15 != 0) {
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,pcVar37);
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuVar41 = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,pcVar39);
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          pppppppuVar42 = pppppppuVar26 + 1;
          pppppppuVar26 = pppppppuVar26 + 1;
          *(undefined4 *******)(puStack_498 + -0x4df8) = *pppppppuVar42;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,puStack_494 + 0x31a4);
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuStack_48c = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,pcStack_488);
        if (iVar15 == 0) {
          puStack_46c = (undefined *)0x1000;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,iStack_484 + 0x6410);
        if (iVar15 == 0) {
          ppppppuStack_460 = (undefined4 ******)0x1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-multivalue-rdn");
        if (iVar15 == 0) {
          ppppppuStack_458 = (undefined4 ******)0x1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-startdate");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          pcStack_454 = (char *)pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-enddate");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuStack_450 = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-days");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          pppppppuVar42 = pppppppuVar26 + 1;
          pppppppuVar26 = pppppppuVar26 + 1;
          ppppppuStack_3a8 = (undefined4 ******)(*(code *)PTR_strtol_006aaa68)(*pppppppuVar42,0,10);
          goto LAB_00430410;
        }
        iStack_47c = 0x2d - (uint)*(byte *)ppppppuVar30;
        if ((((iStack_47c == 0) && (*(byte *)((int)ppppppuVar30 + 1) == 0x6d)) &&
            (*(byte *)((int)ppppppuVar30 + 2) == 100)) && (*(byte *)((int)ppppppuVar30 + 3) == 0)) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuStack_43c = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-policy");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuStack_448 = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-keyfile");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          ppppppuStack_410 = pppppppuVar26[1];
          pppppppuVar26 = pppppppuVar26 + 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-keyform");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
          pppppppuVar26 = pppppppuVar26 + 1;
          pcStack_3f0 = (char *)(*(code *)PTR_str2fmt_006a7f4c)(*pppppppuVar26);
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-passin");
        pppppppuVar42 = pppppppuVar26;
        if (iVar15 != 0) goto LAB_0043165c;
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 == (undefined4 ******)0x0) goto LAB_00430804;
        ppppppuStack_3fc = pppppppuVar26[1];
        pppppppuVar26 = pppppppuVar26 + 1;
        goto LAB_00430410;
      }
      ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
      iVar14 = 1;
      pppppppuVar26 = pppppppuVar26 + 1;
    } while (ppppppuVar44 != (undefined4 ******)0x0);
LAB_00430448:
    do {
      ppppppuVar36 = ppppppuStack_404;
      (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
      if (((ppppppuVar41 == (undefined4 ******)0x0) &&
          (ppppppuVar41 = (undefined4 ******)(*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF"),
          ppppppuVar41 == (undefined4 ******)0x0)) &&
         (ppppppuVar41 = (undefined4 ******)(*(code *)PTR_getenv_006aab6c)("SSLEAY_CONF"),
         ppppppuVar41 == (undefined4 ******)0x0)) {
        uVar16 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
        iVar15 = (*(code *)PTR_strlen_006aab30)(uVar16);
        iVar15 = iVar15 + 0xd;
        ppppppuVar30 = (undefined4 ******)
                       (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar15,&DAT_00635b2c,0x254);
        (*(code *)PTR_BUF_strlcpy_006a8064)(ppppppuVar30,uVar16,iVar15);
        (*(code *)PTR_BUF_strlcat_006a8068)(ppppppuVar30,&DAT_0063ba98,iVar15);
        (*(code *)PTR_BUF_strlcat_006a8068)(ppppppuVar30,"openssl.cnf",iVar15);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Using configuration from %s\n",ppppppuVar30);
        conf = (undefined4 ******)(*(code *)PTR_NCONF_new_006a7f58)(0);
        iVar15 = (*(code *)PTR_NCONF_load_006a7f5c)(conf,ppppppuVar30,&iStack_3b0);
        ppppppuVar41 = ppppppuVar30;
        if (0 < iVar15) {
          if (ppppppuVar30 != (undefined4 ******)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(ppppppuVar30);
          }
          goto LAB_004309a0;
        }
LAB_004304b4:
        if (iStack_3b0 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"error loading the config file \'%s\'\n",ppppppuVar41);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"error on line %ld of config file \'%s\'\n",iStack_3b0,
                     ppppppuVar41);
        }
        if (ppppppuVar30 != (undefined4 ******)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(ppppppuVar30);
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Using configuration from %s\n",ppppppuVar41);
        conf = (undefined4 ******)(*(code *)PTR_NCONF_new_006a7f58)(0);
        iVar15 = (*(code *)PTR_NCONF_load_006a7f5c)(conf,ppppppuVar41,&iStack_3b0);
        if (iVar15 < 1) {
          ppppppuVar30 = (undefined4 ******)0x0;
          goto LAB_004304b4;
        }
LAB_004309a0:
        puVar7 = PTR_bio_err_006a7f3c;
        iVar15 = (*(code *)PTR_load_config_006a7f64)(*(undefined4 *)puVar8,conf);
        if (iVar15 != 0) {
          uVar16 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar7,ppppppuStack_480,0);
          if ((*(int *)(puStack_498 + -0x4df8) != 0) ||
             (section = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","default_ca"),
             section != 0)) {
            if (conf != (undefined4 ******)0x0) {
              iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,0,"oid_file");
              if ((iVar15 == 0) ||
                 (iVar15 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar15,"r"), iVar15 == 0)) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else {
                (*(code *)PTR_OBJ_create_objects_006a7fb0)(iVar15);
                (*(code *)PTR_BIO_free_006a7f70)(iVar15);
              }
              iVar15 = (*(code *)PTR_add_oid_section_006a7f60)(*(undefined4 *)puVar8,conf);
              if (iVar15 == 0) {
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                goto LAB_004304ec;
              }
            }
            iStack_474 = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","RANDFILE");
            if (iStack_474 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            (*(code *)PTR_app_RAND_load_file_006a7fcc)(iStack_474,*(undefined4 *)puVar8,0);
            iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"string_mask");
            if (iVar15 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a7fc0)(iVar15);
              if (iVar17 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "Invalid global string mask setting %s\n",iVar15);
                goto LAB_004304f0;
              }
            }
            if (puStack_46c == (undefined *)0x1000) {
LAB_00430b5c:
              puStack_46c = (undefined *)0x1000;
            }
            else {
              pcVar39 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (conf,*(undefined4 *)(puStack_498 + -0x4df8),&DAT_00633b60
                                          );
              if (pcVar39 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else if ((((*pcVar39 == 'y') && (pcVar39[1] == 'e')) && (pcVar39[2] == 's')) &&
                      (pcVar39[3] == '\0')) goto LAB_00430b5c;
            }
            uStack_394 = 1;
            iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"unique_subject");
            if (iVar15 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              uStack_394 = (*(code *)PTR_parse_yesno_006a8168)(iVar15,1);
            }
            uVar18 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iStack_470 = (*(code *)PTR_BIO_new_006a7fa4)(uVar18);
            uVar18 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iStack_47c = (*(code *)PTR_BIO_new_006a7fa4)(uVar18);
            uVar18 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            ppppppuStack_480 = (undefined4 ******)(*(code *)PTR_BIO_new_006a7fa4)(uVar18);
            uVar18 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            pppppppuStack_478 = (undefined4 *******)(*(code *)PTR_BIO_new_006a7fa4)(uVar18);
            if (((iStack_470 == 0) || (iStack_47c == 0)) ||
               ((ppppppuStack_480 == (undefined4 ******)0x0 ||
                (pppppppuStack_478 == (undefined4 *******)0x0)))) {
              ppppppuVar41 = (undefined4 ******)0x0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
              goto LAB_0043050c;
            }
            if (ppppppuStack_42c != (undefined4 ******)0x0) {
              iVar14 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                 (conf,*(undefined4 *)(puStack_498 + -0x4df8),"database");
              if (iVar14 != 0) {
                ppppppuVar41 = (undefined4 ******)
                               (*(code *)PTR_load_index_006a816c)(iVar14,&uStack_394);
                if (ppppppuVar41 == (undefined4 ******)0x0) goto LAB_0043050c;
                iVar14 = (*(code *)PTR_index_index_006a8170)(ppppppuVar41);
                if (iVar14 == 0) goto LAB_0043050c;
                puVar31 = auStack_374;
                auStack_374[0] = 0;
                auStack_374[1] = 0;
                auStack_374[2] = 0;
                pcStack_368 = (char *)0x0;
                uStack_364 = 0;
                uStack_360 = 0;
                iVar14 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_42c);
                pcVar39 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                            (iVar14 + 2,&DAT_00635b2c,0x9eb);
                pcStack_368 = pcVar39;
                if (pcVar39 == (char *)0x0) {
                  iVar14 = -1;
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Malloc failure\n");
                }
                else {
                  uVar19 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_42c);
                  puVar7 = PTR_strlen_006aab30;
                  if ((uVar19 & 1) == 0) {
                    (*(code *)PTR_memcpy_006aabf4)(pcVar39,ppppppuStack_42c,uVar19);
                    iVar14 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_42c);
                    pcStack_368[iVar14] = '\0';
                  }
                  else {
                    *pcVar39 = '0';
                    uVar16 = (*(code *)puVar7)(ppppppuStack_42c);
                    (*(code *)PTR_memcpy_006aabf4)(pcStack_368 + 1,ppppppuStack_42c,uVar16);
                    iVar14 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_42c);
                    pcStack_368[iVar14 + 1] = '\0';
                  }
                  pcVar39 = pcStack_368;
                  uVar19 = (uint)*pcStack_368;
                  if (uVar19 != 0) {
                    piVar20 = (int *)(*(code *)PTR___ctype_toupper_loc_006aac30)();
                    iVar14 = 0;
                    do {
                      iVar14 = iVar14 + 1;
                      *pcVar39 = (char)*(undefined4 *)(*piVar20 + (uVar19 & 0xff) * 4);
                      pcVar39 = pcStack_368 + iVar14;
                      uVar19 = (uint)*pcVar39;
                    } while (uVar19 != 0);
                  }
                  ppcVar21 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)
                                                (ppppppuVar41[1],3,puVar31);
                  if (ppcVar21 == (char **)0x0) {
                    iVar14 = -1;
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar8,"Serial %s not present in db.\n",pcStack_368);
                  }
                  else {
                    cVar1 = **ppcVar21;
                    if (cVar1 == 'V') {
                      iVar14 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Valid (%c)\n",pcStack_368,0x56);
                    }
                    else if (cVar1 == 'R') {
                      iVar14 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Revoked (%c)\n",pcStack_368,0x52);
                    }
                    else if (cVar1 == 'E') {
                      iVar14 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Expired (%c)\n",pcStack_368,0x45);
                    }
                    else if (cVar1 == 'S') {
                      iVar14 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Suspended (%c)\n",pcStack_368,0x53);
                    }
                    else {
                      iVar14 = -1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar8,"%s=Unknown (%c).\n",pcStack_368);
                    }
                  }
                }
                do {
                  if (*puVar31 != 0) {
                    (*(code *)PTR_CRYPTO_free_006a7f88)();
                  }
                  puVar31 = puVar31 + 1;
                } while (puVar31 != auStack_35c);
                if (iVar14 == 1) goto LAB_0043050c;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Error verifying serial %s!\n",ppppppuStack_42c);
                goto LAB_0043050c;
              }
              pcVar39 = "database";
LAB_004315b4:
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,pcVar39
                        );
              ppppppuVar41 = (undefined4 ******)0x0;
              goto LAB_0043050c;
            }
            if ((ppppppuStack_410 == (undefined4 ******)0x0) &&
               (ppppppuStack_410 =
                     (undefined4 ******)
                     (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"private_key"),
               ppppppuStack_410 == (undefined4 ******)0x0)) {
              pcVar39 = "private_key";
              goto LAB_004315b4;
            }
            if (ppppppuStack_3bc == (undefined4 ******)0x0) {
              iVar15 = (*(code *)PTR_app_passwd_006a7f54)
                                 (*(undefined4 *)puVar8,ppppppuStack_3fc,0,&ppppppuStack_3bc,0);
              if (iVar15 == 0) {
                pcVar37 = (char *)0x0;
                ppppppuVar30 = (undefined4 ******)0x0;
                ppppppuVar41 = (undefined4 ******)0x0;
                pcVar39 = (char *)0x0;
                puVar33 = (undefined1 *)0x0;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,"Error getting password\n");
                iVar14 = 1;
                pcStack_488 = (char *)0x0;
                iStack_484 = 1;
                goto LAB_00430528;
              }
              iStack_484 = 1;
            }
            else {
              iStack_484 = 0;
            }
            pcStack_488 = (char *)(*(code *)PTR_load_key_006a7fc8)
                                            (*(undefined4 *)puVar8,ppppppuStack_410,pcStack_3f0,0,
                                             ppppppuStack_3bc,uVar16,"CA private key");
            ppppppuVar41 = ppppppuStack_3bc;
            if (ppppppuStack_3bc != (undefined4 ******)0x0) {
              uVar18 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_3bc);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(ppppppuVar41,uVar18);
            }
            if (pcStack_488 == (char *)0x0) {
LAB_004317b0:
              pcVar37 = (char *)0x0;
              ppppppuVar30 = (undefined4 ******)0x0;
              ppppppuVar41 = (undefined4 ******)0x0;
              pcVar39 = (char *)0x0;
              puVar33 = (undefined1 *)0x0;
              iVar14 = 1;
              goto LAB_00430528;
            }
            if ((((iStack_418 == 0) || (ppppppuStack_430 != (undefined4 ******)0x0)) ||
                (ppppppuStack_404 != (undefined4 ******)0x0)) || (bVar4)) {
              if ((ppppppuStack_40c == (undefined4 ******)0x0) &&
                 (ppppppuStack_40c =
                       (undefined4 ******)
                       (*(code *)PTR_NCONF_get_string_006a7fa8)
                                 (conf,*(undefined4 *)(puStack_498 + -0x4df8),"certificate"),
                 ppppppuStack_40c == (undefined4 ******)0x0)) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,
                           "certificate");
                goto LAB_004317b0;
              }
              pcVar39 = (char *)(*(code *)PTR_load_cert_006a8178)
                                          (*(undefined4 *)puVar8,ppppppuStack_40c,3,0,uVar16,
                                           "CA certificate");
              if ((undefined4 ******)pcVar39 == (undefined4 ******)0x0) goto LAB_00431744;
              iVar15 = (*(code *)PTR_X509_check_private_key_006a817c)(pcVar39,pcStack_488);
              if (iVar15 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "CA certificate and CA private key do not match\n");
                goto LAB_00431744;
              }
              ppppppuStack_3fc = (undefined4 ******)pcVar39;
              if (iStack_418 != 0) goto LAB_00431524;
            }
            else {
              pcVar39 = (char *)0x0;
LAB_00431524:
              ppppppuStack_3fc = (undefined4 ******)0x0;
            }
            pbVar22 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","preserve");
            if (pbVar22 == (byte *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else if ((*pbVar22 & 0xdf) == 0x59) {
              ppppppuStack_3e4[-0x137f] = (undefined4 *****)0x1;
            }
            pbVar22 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"ca","msie_hack");
            if (pbVar22 == (byte *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else if ((*pbVar22 & 0xdf) == 0x59) {
              ppppppuStack_3e8[-0x1380] = (undefined4 *****)0x1;
            }
            iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"name_opt");
            if (iVar15 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              ppppppuStack_410 = (undefined4 ******)0x1;
            }
            else {
              iVar17 = (*(code *)PTR_set_name_ex_006a80ac)(&ppppppuStack_3a4,iVar15);
              if (iVar17 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid name options: \"%s\"\n",iVar15);
                goto LAB_00431744;
              }
              ppppppuStack_410 = (undefined4 ******)0x0;
            }
            iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"cert_opt");
            if (iVar15 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_set_cert_ex_006a80b0)(&ppppppuStack_3a0,iVar15);
              if (iVar17 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid certificate options: \"%s\"\n",iVar15);
                goto LAB_00431744;
              }
              ppppppuStack_410 = (undefined4 ******)0x0;
            }
            iVar15 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"copy_extensions");
            if (iVar15 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_set_ext_copy_006a8180)(&uStack_39c,iVar15);
              if (iVar17 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Invalid extension copy option: \"%s\"\n",iVar15);
                goto LAB_00431744;
              }
            }
            if ((ppppppuStack_44c == (undefined4 ******)0x0) && (piStack_440 != (int *)0x0)) {
              ppppppuStack_44c =
                   (undefined4 ******)
                   (*(code *)PTR_NCONF_get_string_006a7fa8)
                             (conf,*(undefined4 *)(puStack_498 + -0x4df8),"new_certs_dir");
              if (ppppppuStack_44c == (undefined4 ******)0x0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,
                           "there needs to be defined a directory for new certificate to be placed in\n"
                          );
                goto LAB_00431744;
              }
              iVar15 = (*(code *)PTR_access_006aaad8)(ppppppuStack_44c,7);
              if (iVar15 != 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"I am unable to access the %s directory\n",
                           ppppppuStack_44c);
                (*(code *)PTR_perror_006aab88)(ppppppuStack_44c);
                goto LAB_00431744;
              }
              iVar15 = (*(code *)PTR_app_isdir_006a8188)(ppppppuStack_44c);
              if (iVar15 < 1) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"%s need to be a directory\n",ppppppuStack_44c);
                (*(code *)PTR_perror_006aab88)(ppppppuStack_44c);
                goto LAB_00431744;
              }
            }
            ppppppuStack_42c =
                 (undefined4 ******)
                 (*(code *)PTR_NCONF_get_string_006a7fa8)
                           (conf,*(undefined4 *)(puStack_498 + -0x4df8),"database");
            if (ppppppuStack_42c == (undefined4 ******)0x0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,
                         "database");
LAB_00431744:
              pcVar37 = (char *)0x0;
              ppppppuVar30 = (undefined4 ******)0x0;
              ppppppuVar41 = (undefined4 ******)0x0;
              puVar33 = (undefined1 *)0x0;
              iVar14 = 1;
              goto LAB_00430528;
            }
            ppppppuVar41 = (undefined4 ******)
                           (*(code *)PTR_load_index_006a816c)(ppppppuStack_42c,&uStack_394);
            if (ppppppuVar41 == (undefined4 ******)0x0) goto LAB_004314a8;
            iVar15 = 0;
            goto LAB_004313b0;
          }
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar7,"variable lookup failed for %s::%s\n","ca","default_ca");
        }
      }
LAB_004304ec:
      iStack_474 = 0;
LAB_004304f0:
      pppppppuStack_478 = (undefined4 *******)0x0;
      ppppppuStack_480 = (undefined4 ******)0x0;
      ppppppuVar41 = (undefined4 ******)0x0;
      iStack_47c = 0;
      iStack_470 = 0;
LAB_0043050c:
      pcVar37 = (char *)0x0;
      ppppppuVar30 = (undefined4 ******)0x0;
      pcStack_488 = (char *)0x0;
      pcVar39 = (char *)0x0;
      iStack_484 = 0;
      puVar33 = (undefined1 *)0x0;
      iVar14 = 1;
LAB_00430528:
      puStack_494 = &_ITM_registerTMCloneTable;
      (*(code *)PTR_BIO_free_all_006a7f74)(pppppppuStack_478);
      (*(code *)PTR_BIO_free_all_006a7f74)(ppppppuStack_480);
      (*(code *)PTR_BIO_free_all_006a7f74)(iStack_47c);
      (*(code *)PTR_BIO_free_all_006a7f74)(iStack_470);
      if (pcVar37 != (char *)0x0) {
        (*(code *)PTR_sk_pop_free_006a8158)(pcVar37,PTR_X509_free_006a7f90);
      }
      if (iVar14 != 0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
      }
      (*(code *)PTR_app_RAND_write_file_006a804c)(iStack_474,*(undefined4 *)puVar8);
      if ((iStack_484 != 0) && (ppppppuStack_3bc != (undefined4 ******)0x0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      (*(code *)PTR_BN_free_006a811c)(ppppppuStack_3ac);
      (*(code *)PTR_BN_free_006a811c)(puVar33);
      (*(code *)PTR_free_index_006a815c)(ppppppuVar41);
      if (iStack_468 != 0) {
        (*(code *)PTR_sk_free_006a7f80)(iStack_468);
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(pcStack_488);
      if ((undefined4 ******)pcVar39 != (undefined4 ******)0x0) {
        (*(code *)PTR_X509_free_006a7f90)(pcVar39);
      }
      (*(code *)PTR_X509_CRL_free_006a8160)(ppppppuVar30);
      (*(code *)PTR_NCONF_free_006a7f6c)(conf);
      (*(code *)PTR_NCONF_free_006a7f6c)(extconf);
      (*(code *)PTR_OBJ_cleanup_006a7f98)();
      if (apppppuStack_74[0] == *(undefined4 ******)puVar9) {
        return iVar14;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      pppppppuVar42 = pppppppuVar26;
LAB_0043165c:
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,&DAT_006330b4);
      pppppppuVar26 = pppppppuVar42;
      if (iVar15 == 0) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          ppppppuStack_3bc = pppppppuVar42[1];
          pppppppuVar26 = pppppppuVar42 + 1;
          goto LAB_00430410;
        }
LAB_00430804:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"unknown option %s\n",ppppppuVar30)
        ;
        if (ca_usage._0_4_ == 0) goto LAB_004304ec;
        puVar33 = ca_usage;
        do {
          puVar33 = (undefined1 *)((int)puVar33 + 4);
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"%s");
        } while (*(int *)puVar33 != 0);
        iStack_474 = 0;
        goto LAB_004304f0;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-cert");
      if (iVar15 == 0) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          ppppppuStack_40c = pppppppuVar42[1];
          pppppppuVar26 = pppppppuVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-selfsign");
      if (iVar15 == 0) {
        iStack_418 = 1;
        goto LAB_00430410;
      }
      if ((((iStack_47c == 0) && (*(byte *)((int)ppppppuVar30 + 1) == 0x69)) &&
          (*(byte *)((int)ppppppuVar30 + 2) == 0x6e)) && (*(byte *)((int)ppppppuVar30 + 3) == 0)) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          ppppppuStack_424 = pppppppuVar42[1];
          piStack_440 = (int *)0x1;
          pppppppuVar26 = pppppppuVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,&DAT_00632edc);
      if (iVar15 == 0) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          ppppppuStack_408 = pppppppuVar42[1];
          pppppppuVar26 = pppppppuVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-outdir");
      if (iVar15 == 0) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          ppppppuStack_44c = pppppppuVar42[1];
          pppppppuVar26 = pppppppuVar42 + 1;
          goto LAB_00430410;
        }
        goto LAB_00430804;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-sigopt");
      if (iVar15 == 0) {
        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
        if (ppppppuVar44 != (undefined4 ******)0x0) {
          if ((iStack_468 == 0) &&
             (iStack_468 = (*(code *)PTR_sk_new_null_006a80a4)(), iStack_468 == 0)) {
            ppppppuVar30 = *pppppppuVar42;
          }
          else {
            pppppppuVar26 = pppppppuVar42 + 1;
            iVar15 = (*(code *)PTR_sk_push_006a80a8)(iStack_468,pppppppuVar42[1]);
            if (iVar15 != 0) goto LAB_00430410;
            ppppppuVar30 = pppppppuVar42[1];
            pppppppuVar26 = pppppppuVar42;
          }
        }
        goto LAB_00430804;
      }
      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-notext");
      if (iVar15 != 0) {
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-batch");
        if (iVar15 == 0) {
          iStack_434 = 1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-preserveDN");
        if (iVar15 == 0) {
          ppppppuStack_3e4[-0x137f] = (undefined4 *****)0x1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-noemailDN");
        if (iVar15 == 0) {
          bVar3 = false;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-gencrl");
        if (iVar15 == 0) {
          bVar4 = true;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-msie_hack");
        if (iVar15 == 0) {
          ppppppuStack_3e8[-0x1380] = (undefined4 *****)0x1;
          goto LAB_00430410;
        }
        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crldays");
        if (iVar15 == 0) {
          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
          if (ppppppuVar44 != (undefined4 ******)0x0) {
            iStack_3b8 = (*(code *)PTR_strtol_006aaa68)(pppppppuVar42[1],0,10);
            pppppppuVar26 = pppppppuVar42 + 1;
            goto LAB_00430410;
          }
        }
        else {
          iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crlhours");
          if (iVar15 == 0) {
            ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
            if (ppppppuVar44 != (undefined4 ******)0x0) {
              iStack_3b4 = (*(code *)PTR_strtol_006aaa68)(pppppppuVar42[1],0,10);
              pppppppuVar26 = pppppppuVar42 + 1;
              goto LAB_00430410;
            }
          }
          else {
            iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crlsec");
            if (iVar15 == 0) {
              ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
              if (ppppppuVar44 != (undefined4 ******)0x0) {
                iStack_400 = (*(code *)PTR_strtol_006aaa68)(pppppppuVar42[1],0,10);
                pppppppuVar26 = pppppppuVar42 + 1;
                goto LAB_00430410;
              }
            }
            else {
              iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-infiles");
              if (iVar15 == 0) {
                ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                pppppppuVar26 = pppppppuVar42 + 1;
                piStack_440 = (int *)0x1;
                goto LAB_00430448;
              }
              iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-ss_cert");
              if (iVar15 == 0) {
                ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                if (ppppppuVar44 != (undefined4 ******)0x0) {
                  ppppppuStack_404 = pppppppuVar42[1];
                  piStack_440 = (int *)0x1;
                  pppppppuVar26 = pppppppuVar42 + 1;
                  goto LAB_00430410;
                }
              }
              else {
                iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-spkac");
                if (iVar15 == 0) {
                  ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                  if (ppppppuVar44 != (undefined4 ******)0x0) {
                    ppppppuStack_430 = pppppppuVar42[1];
                    piStack_440 = (int *)0x1;
                    pppppppuVar26 = pppppppuVar42 + 1;
                    goto LAB_00430410;
                  }
                }
                else {
                  iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-revoke");
                  if (iVar15 == 0) {
                    ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                    if (ppppppuVar44 != (undefined4 ******)0x0) {
                      ppppppuStack_424 = pppppppuVar42[1];
                      bVar6 = true;
                      pppppppuVar26 = pppppppuVar42 + 1;
                      goto LAB_00430410;
                    }
                  }
                  else {
                    iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-extensions");
                    if (iVar15 == 0) {
                      ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                      if (ppppppuVar44 != (undefined4 ******)0x0) {
                        ppppppuStack_45c = pppppppuVar42[1];
                        pppppppuVar26 = pppppppuVar42 + 1;
                        goto LAB_00430410;
                      }
                    }
                    else {
                      iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-extfile");
                      if (iVar15 == 0) {
                        ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                        if (ppppppuVar44 != (undefined4 ******)0x0) {
                          ppppppuStack_428 = pppppppuVar42[1];
                          pppppppuVar26 = pppppppuVar42 + 1;
                          goto LAB_00430410;
                        }
                      }
                      else {
                        iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-status");
                        if (iVar15 == 0) {
                          ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                          if (ppppppuVar44 != (undefined4 ******)0x0) {
                            ppppppuStack_42c = pppppppuVar42[1];
                            pppppppuVar26 = pppppppuVar42 + 1;
                            goto LAB_00430410;
                          }
                        }
                        else {
                          iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-updatedb");
                          if (iVar15 == 0) {
                            ppppppuStack_3f4 = (undefined4 ******)0x1;
                            goto LAB_00430410;
                          }
                          iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crlexts");
                          if (iVar15 == 0) {
                            ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                            if (ppppppuVar44 != (undefined4 ******)0x0) {
                              ppppppuStack_438 = pppppppuVar42[1];
                              pppppppuVar26 = pppppppuVar42 + 1;
                              goto LAB_00430410;
                            }
                          }
                          else {
                            iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crl_reason");
                            if (iVar15 == 0) {
                              ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                              if (ppppppuVar44 != (undefined4 ******)0x0) {
                                ppppppuStack_41c = pppppppuVar42[1];
                                uStack_420 = 1;
                                pppppppuVar26 = pppppppuVar42 + 1;
                                goto LAB_00430410;
                              }
                            }
                            else {
                              iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-crl_hold");
                              if (iVar15 == 0) {
                                ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                                if (ppppppuVar44 != (undefined4 ******)0x0) {
                                  ppppppuStack_41c = pppppppuVar42[1];
                                  uStack_420 = 2;
                                  pppppppuVar26 = pppppppuVar42 + 1;
                                  goto LAB_00430410;
                                }
                              }
                              else {
                                iVar15 = (*(code *)PTR_strcmp_006aac20)
                                                   (ppppppuVar30,"-crl_compromise");
                                if (iVar15 == 0) {
                                  ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                                  if (ppppppuVar44 != (undefined4 ******)0x0) {
                                    ppppppuStack_41c = pppppppuVar42[1];
                                    uStack_420 = 3;
                                    pppppppuVar26 = pppppppuVar42 + 1;
                                    goto LAB_00430410;
                                  }
                                }
                                else {
                                  iVar15 = (*(code *)PTR_strcmp_006aac20)
                                                     (ppppppuVar30,"-crl_CA_compromise");
                                  if (iVar15 == 0) {
                                    ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
                                    if (ppppppuVar44 != (undefined4 ******)0x0) {
                                      ppppppuStack_41c = pppppppuVar42[1];
                                      uStack_420 = 4;
                                      pppppppuVar26 = pppppppuVar42 + 1;
                                      goto LAB_00430410;
                                    }
                                  }
                                  else {
                                    iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuVar30,"-engine");
                                    if ((iVar15 == 0) &&
                                       (ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1),
                                       ppppppuVar44 != (undefined4 ******)0x0)) {
                                      ppppppuStack_480 = pppppppuVar42[1];
                                      pppppppuVar26 = pppppppuVar42 + 1;
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
      ppppppuVar44 = (undefined4 ******)((int)ppppppuVar44 + -1);
      pppppppuVar26 = pppppppuVar26 + 1;
    } while (ppppppuVar44 == (undefined4 ******)0x0);
  } while( true );
LAB_004313b0:
  iVar17 = (*(code *)PTR_sk_num_006a7f2c)(ppppppuVar41[1][1]);
  if (iVar17 <= iVar15) goto LAB_00431a68;
  ppcVar21 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppppppuVar41[1][1],iVar15);
  if (**ppcVar21 == 'R') {
    iVar17 = make_revoked(0,ppcVar21[2]);
    if (iVar17 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8," in entry %d\n",iVar15 + 1);
      goto LAB_004314a8;
    }
  }
  else if (*ppcVar21[2] != '\0') {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: not revoked yet, but has a revocation date\n",
               iVar15 + 1);
    goto LAB_004314a8;
  }
  iVar17 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,ppcVar21[1]);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: invalid expiry date\n",iVar15 + 1);
    goto LAB_004314a8;
  }
  pcVar38 = ppcVar21[3];
  uVar19 = (*(code *)PTR_strlen_006aab30)(pcVar38);
  pcVar37 = pcVar38;
  if (*pcVar38 == '-') {
    uVar19 = uVar19 - 1;
    pcVar37 = pcVar38 + 1;
  }
  if (((uVar19 & 1) != 0) || ((int)uVar19 < 2)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"entry %d: bad serial number length (%d)\n",iVar15 + 1,uVar19);
    goto LAB_004314a8;
  }
  while( true ) {
    uVar19 = (uint)*pcVar37;
    if (uVar19 == 0) break;
    if ((9 < (uVar19 & 0xff) - 0x30) && (5 < (uVar19 & 0xdf) - 0x41)) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",iVar15 + 1
                 ,(int)pcVar37 - (int)pcVar38,uVar19);
      goto LAB_004314a8;
    }
    pcVar37 = pcVar37 + 1;
  }
  iVar15 = iVar15 + 1;
  goto LAB_004313b0;
LAB_00431a68:
  if (iVar14 != 0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(iStack_47c,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
    (*(code *)PTR_TXT_DB_write_006a818c)(iStack_47c,ppppppuVar41[1]);
    uVar34 = *(undefined4 *)puVar8;
    uVar18 = (*(code *)PTR_sk_num_006a7f2c)(ppppppuVar41[1][1]);
    (*(code *)PTR_BIO_printf_006a7f38)(uVar34,"%d entries loaded from the database\n",uVar18);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"generating index\n");
  }
  iVar15 = (*(code *)PTR_index_index_006a8170)(ppppppuVar41);
  if (iVar15 == 0) {
LAB_004314a8:
    pcVar37 = (char *)0x0;
    ppppppuVar30 = (undefined4 ******)0x0;
    puVar33 = (undefined1 *)0x0;
    iVar14 = 1;
    goto LAB_00430528;
  }
  if (ppppppuStack_3f4 != (undefined4 ******)0x0) {
    if (iVar14 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Updating %s ...\n",ppppppuStack_42c)
      ;
    }
    uVar18 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
    ppppppuVar30 = (undefined4 ******)(*(code *)PTR_X509_gmtime_adj_006a808c)(uVar18,0);
    iVar15 = (*(code *)PTR_CRYPTO_malloc_006a8108)((int)*ppppppuVar30 + 1,&DAT_00635b2c,0xa44);
    if (iVar15 == 0) {
      (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(ppppppuVar30);
      (*(code *)PTR_CRYPTO_free_006a7f88)(0);
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Malloc failure\n");
      goto LAB_004314a8;
    }
    (*(code *)PTR_memcpy_006aabf4)(iVar15,ppppppuVar30[2],*ppppppuVar30);
    puVar7 = PTR_strncmp_006aaa7c;
    ppppppuStack_3e8 = (undefined4 ******)&DAT_00636944;
    *(undefined *)(iVar15 + (int)*ppppppuVar30) = 0;
    ppppppuStack_3f4 = (undefined4 ******)(*(code *)puVar7)(iVar15,&DAT_00636944,2);
    puStack_494 = (undefined1 *)0x0;
    pcStack_3f0 = "%s=Expired\n";
    for (ppppppuStack_40c = (undefined4 ******)0x0;
        iVar17 = (*(code *)PTR_sk_num_006a7f2c)(ppppppuVar41[1][1]), (int)ppppppuStack_40c < iVar17;
        ppppppuStack_40c = (undefined4 ******)((int)ppppppuStack_40c + 1)) {
      ppcVar21 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppppppuVar41[1][1],ppppppuStack_40c);
      pcVar37 = *ppcVar21;
      if (*pcVar37 == 'V') {
        pcVar38 = ppcVar21[1];
        iVar17 = (*(code *)PTR_strncmp_006aaa7c)(pcVar38,&DAT_00636944,2);
        if (iVar17 < 1) {
          if ((int)ppppppuStack_3f4 < 1) {
LAB_00433c70:
            iVar17 = (*(code *)PTR_strcmp_006aac20)(pcVar38,iVar15);
            if (iVar17 < 1) {
              *pcVar37 = 'E';
              pcVar37 = *ppcVar21;
              goto LAB_00433bb8;
            }
          }
        }
        else {
          if (0 < (int)ppppppuStack_3f4) goto LAB_00433c70;
          *pcVar37 = 'E';
          pcVar37 = *ppcVar21;
LAB_00433bb8:
          puVar7 = PTR_BIO_printf_006a7f38;
          puStack_494 = (undefined1 *)((int)puStack_494 + 1);
          pcVar37[1] = '\0';
          (*(code *)puVar7)(*(undefined4 *)puVar8,"%s=Expired\n",ppcVar21[3]);
        }
      }
    }
    (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(ppppppuVar30);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar15);
    ppppppuStack_3e4 = ppppppuVar30;
    if (puStack_494 == (undefined1 *)0x0) {
      if (iVar14 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"No entries found to mark expired\n");
      }
    }
    else {
      iVar15 = (*(code *)PTR_save_index_006a8190)(ppppppuStack_42c,"new",ppppppuVar41);
      if ((iVar15 == 0) ||
         (iVar15 = (*(code *)PTR_rotate_index_006a8194)(ppppppuStack_42c,"new","old"), iVar15 == 0))
      goto LAB_004314a8;
      if (iVar14 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Done. %d entries marked as expired\n",puStack_494);
      }
    }
  }
  if (ppppppuStack_428 != (undefined4 ******)0x0) {
    extconf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar15 = (*(code *)PTR_NCONF_load_006a7f5c)(extconf,ppppppuStack_428,&iStack_3b0);
    if (0 < iVar15) {
      if (iVar14 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Successfully loaded extensions file %s\n",ppppppuStack_428
                  );
      }
      if (ppppppuStack_45c == (undefined4 ******)0x0) {
        ppppppuVar30 = (undefined4 ******)
                       (*(code *)PTR_NCONF_get_string_006a7fa8)(extconf,"default","extensions");
        ppppppuStack_45c = (undefined4 ******)0x66fa44;
        if (ppppppuVar30 != (undefined4 ******)0x0) {
          ppppppuStack_45c = ppppppuVar30;
        }
      }
      goto LAB_00431d50;
    }
    uVar16 = *(undefined4 *)puVar8;
    if (0 < iStack_3b0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (uVar16,"ERROR: on line %ld of config file \'%s\'\n",iStack_3b0,ppppppuStack_428);
      goto LAB_004320fc;
    }
    pcVar37 = "ERROR: loading the config file \'%s\'\n";
    ppppppuVar30 = ppppppuStack_428;
LAB_00432ce8:
    (*(code *)PTR_BIO_printf_006a7f38)(uVar16,pcVar37,ppppppuVar30);
LAB_004320fc:
    pcVar37 = (char *)0x0;
    ppppppuVar30 = (undefined4 ******)0x0;
    puVar33 = (undefined1 *)0x0;
    iVar14 = 1;
    goto LAB_00430528;
  }
LAB_00431d50:
  if ((piStack_440 != (int *)0x0) || (bVar4)) {
    if (ppppppuStack_408 == (undefined4 ******)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)
                (ppppppuStack_480,0x6a,0x10,*(undefined4 *)PTR_stdout_006aaad4);
    }
    else {
      iVar15 = (*(code *)PTR_BIO_ctrl_006a7f18)(ppppppuStack_480,0x6c,5,ppppppuStack_408);
      if (iVar15 < 1) {
        (*(code *)PTR_perror_006aab88)(ppppppuStack_408);
        goto LAB_004320fc;
      }
    }
  }
  if ((ppppppuStack_43c == (undefined4 ******)0x0) &&
     (ppppppuStack_43c =
           (undefined4 ******)
           (*(code *)PTR_NCONF_get_string_006a7fa8)
                     (conf,*(undefined4 *)(puStack_498 + -0x4df8),"default_md"),
     ppppppuStack_43c == (undefined4 ******)0x0)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,"default_md");
    goto LAB_004320fc;
  }
  iVar15 = (*(code *)PTR_strcmp_006aac20)(ppppppuStack_43c,"default");
  if (iVar15 == 0) {
    iVar15 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a8198)(pcStack_488,auStack_390);
    if (iVar15 < 1) {
      (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar8,"no default digest\n");
      goto LAB_004320fc;
    }
    ppppppuStack_43c = (undefined4 ******)(*(code *)PTR_OBJ_nid2sn_006a819c)(auStack_390[0]);
  }
  ppppppuStack_428 =
       (undefined4 ******)(*(code *)PTR_EVP_get_digestbyname_006a802c)(ppppppuStack_43c);
  if (ppppppuStack_428 == (undefined4 ******)0x0) {
    uVar16 = *(undefined4 *)puVar8;
    pcVar37 = "%s is an unsupported message digest type\n";
    ppppppuVar30 = ppppppuStack_43c;
    goto LAB_00432ce8;
  }
  pcVar37 = (char *)0x0;
  if (piStack_440 == (int *)0x0) goto LAB_004330e0;
  if ((bVar3 != false) &&
     (pbVar22 = (byte *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                  (conf,*(undefined4 *)(puStack_498 + -0x4df8),"email_in_dn"),
     pbVar22 != (byte *)0x0)) {
    iVar15 = 0x6e - (uint)*pbVar22;
    if ((iVar15 == 0) && (iVar15 = 0x6f - (uint)pbVar22[1], iVar15 == 0)) {
      iVar15 = -(uint)pbVar22[2];
    }
    bVar3 = iVar15 != 0;
  }
  if (iVar14 == 0) {
    if ((ppppppuStack_448 == (undefined4 ******)0x0) &&
       (ppppppuStack_448 =
             (undefined4 ******)
             (*(code *)PTR_NCONF_get_string_006a7fa8)
                       (conf,*(undefined4 *)(puStack_498 + -0x4df8),"policy"),
       ppppppuStack_448 == (undefined4 ******)0x0)) {
LAB_004339a0:
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",
                 *(undefined4 *)(puStack_498 + -0x4df8),"policy");
      goto LAB_004320fc;
    }
  }
  else {
    uVar34 = *(undefined4 *)puVar8;
    uVar18 = (*(code *)PTR_OBJ_nid2ln_006a821c)(*ppppppuStack_428);
    (*(code *)PTR_BIO_printf_006a7f38)(uVar34,"message digest is %s\n",uVar18);
    if ((ppppppuStack_448 == (undefined4 ******)0x0) &&
       (ppppppuStack_448 =
             (undefined4 ******)
             (*(code *)PTR_NCONF_get_string_006a7fa8)
                       (conf,*(undefined4 *)(puStack_498 + -0x4df8),"policy"),
       ppppppuStack_448 == (undefined4 ******)0x0)) goto LAB_004339a0;
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"policy is %s\n",ppppppuStack_448);
  }
  ppppppuStack_40c =
       (undefined4 ******)
       (*(code *)PTR_NCONF_get_string_006a7fa8)
                 (conf,*(undefined4 *)(puStack_498 + -0x4df8),"serial");
  if (ppppppuStack_40c == (undefined4 ******)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"variable lookup failed for %s::%s\n",section,"serial");
    goto LAB_004320fc;
  }
  if (extconf == 0) {
    if ((ppppppuStack_45c == (undefined4 ******)0x0) &&
       (ppppppuStack_45c =
             (undefined4 ******)
             (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,section,"x509_extensions"),
       ppppppuStack_45c == (undefined4 ******)0x0)) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
    }
    else {
      (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_390,0,0,0,0,1);
      (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_390,conf);
      iVar15 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(conf,auStack_390,ppppppuStack_45c,0);
      if (iVar15 == 0) {
        uVar16 = *(undefined4 *)puVar8;
        pcVar37 = "Error Loading extension section %s\n";
        ppppppuVar30 = ppppppuStack_45c;
        goto LAB_00432ce8;
      }
    }
  }
  if (((undefined4 ******)pcStack_454 == (undefined4 ******)0x0) &&
     (pcStack_454 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (conf,*(undefined4 *)(puStack_498 + -0x4df8),
                                       "default_startdate"),
     (undefined4 ******)pcStack_454 == (undefined4 ******)0x0)) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    pcStack_454 = "today";
  }
  else {
    iVar15 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,pcStack_454);
    if (iVar15 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
      goto LAB_004320fc;
    }
  }
  if ((ppppppuStack_450 == (undefined4 ******)0x0) &&
     (ppppppuStack_450 =
           (undefined4 ******)
           (*(code *)PTR_NCONF_get_string_006a7fa8)
                     (conf,*(undefined4 *)(puStack_498 + -0x4df8),"default_enddate"),
     ppppppuStack_450 == (undefined4 ******)0x0)) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  else {
    iVar15 = (*(code *)PTR_ASN1_TIME_set_string_006a8184)(0,ppppppuStack_450);
    if (iVar15 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,
                 "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n");
      goto LAB_004320fc;
    }
  }
  if (ppppppuStack_3a8 == (undefined4 ******)0x0) {
    iVar15 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                       (conf,*(undefined4 *)(puStack_498 + -0x4df8),"default_days",&ppppppuStack_3a8
                       );
    if (iVar15 == 0) {
      ppppppuStack_3a8 = (undefined4 ******)0x0;
      ppppppuVar30 = ppppppuStack_450;
    }
    else {
      ppppppuVar30 = ppppppuStack_3a8;
      if (ppppppuStack_450 != (undefined4 ******)0x0) goto LAB_00431ebc;
    }
    if (ppppppuVar30 == (undefined4 ******)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"cannot lookup how many days to certify for\n");
      goto LAB_004320fc;
    }
  }
LAB_00431ebc:
  ppppppuStack_3ac =
       (undefined4 ******)(*(code *)PTR_load_serial_006a81a0)(ppppppuStack_40c,ppppppuStack_460,0);
  if (ppppppuStack_3ac == (undefined4 ******)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"error while loading serial number\n");
    goto LAB_004320fc;
  }
  if (iVar14 != 0) {
    if (ppppppuStack_3ac[1] == (undefined4 *****)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"next serial number is 00\n");
    }
    else {
      iVar15 = (*(code *)PTR_BN_bn2hex_006a8118)(ppppppuStack_3ac);
      if (iVar15 == 0) goto LAB_004320fc;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"next serial number is %s\n",iVar15);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar15);
    }
  }
  ppppppuStack_43c =
       (undefined4 ******)(*(code *)PTR_NCONF_get_section_006a7fd4)(conf,ppppppuStack_448);
  if (ppppppuStack_43c == (undefined4 ******)0x0) {
    uVar16 = *(undefined4 *)puVar8;
    pcVar37 = "unable to find \'section\' for %s\n";
    ppppppuVar30 = ppppppuStack_448;
    goto LAB_00432ce8;
  }
  pcVar37 = (char *)(*(code *)PTR_sk_new_null_006a80a4)();
  uVar18 = uStack_39c;
  ppppppuVar10 = ppppppuStack_3a0;
  ppppppuVar40 = ppppppuStack_3a4;
  ppppppuVar13 = ppppppuStack_3a8;
  ppppppuVar25 = ppppppuStack_3ac;
  ppppppuVar30 = conf;
  if (pcVar37 == (char *)0x0) {
    uVar16 = *(undefined4 *)puVar8;
    pcVar38 = "Memory allocation failure\n";
    goto LAB_004329a0;
  }
  if (ppppppuStack_430 == (undefined4 ******)0x0) {
    piStack_440 = (int *)0x0;
    ppppppuVar30 = (undefined4 ******)0x0;
    ppppppuStack_3f4 = (undefined4 ******)&SUB_00000002;
    ppppppuStack_430 = (undefined4 ******)&SUB_00000002;
    ppppppuStack_448 = (undefined4 ******)0x1;
    ppppppuStack_460 = (undefined4 ******)0x1;
    ppppppuVar25 = (undefined4 ******)0x0;
    goto LAB_00432364;
  }
  pcStack_3f0 = (char *)ppppppuStack_3a8;
  ppppppuStack_3f4 = ppppppuStack_3ac;
  ppppppuStack_3e8 = conf;
  ppppppuStack_3e4 = ppppppuStack_3a0;
  ppppppuStack_460 =
       (undefined4 ******)(*(code *)PTR_CONF_load_006a81a4)(0,ppppppuStack_430,auStack_390);
  if (ppppppuStack_460 == (undefined4 ******)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar8,"error on line %ld of %s\n",auStack_390[0],ppppppuStack_430);
    ppppppuVar28 = *(undefined4 *******)puVar8;
    pcVar43 = (code *)PTR_ERR_print_errors_006a7f40;
LAB_00432c2c:
    ppppppuVar30 = (undefined4 ******)0x0;
    (*pcVar43)(ppppppuVar28);
  }
  else {
    uVar34 = (*(code *)PTR_CONF_get_section_006a81a8)(ppppppuStack_460,"default");
    iVar15 = (*(code *)PTR_sk_num_006a7f2c)(uVar34);
    ppppppuVar28 = ppppppuStack_460;
    if (iVar15 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"no name/value pairs found in %s\n",ppppppuStack_430);
      (*(code *)PTR_CONF_free_006a81b4)(ppppppuStack_460);
      pcVar43 = (code *)PTR_CONF_free_006a81b4;
      goto LAB_00432c2c;
    }
    piVar20 = (int *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
    if (piVar20 == (int *)0x0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
      pcVar43 = (code *)PTR_CONF_free_006a81b4;
      goto LAB_00432c2c;
    }
    iVar15 = 0;
    ppppppuStack_448 = (undefined4 ******)0x0;
    uVar23 = *(undefined4 *)(*piVar20 + 0x10);
    for (; iVar17 = (*(code *)PTR_sk_num_006a7f2c)(uVar34), puVar7 = PTR_bio_err_006a7f3c,
        piStack_440 = piVar20, (int)ppppppuStack_448 < iVar17;
        ppppppuStack_448 = (undefined4 ******)((int)ppppppuStack_448 + 1)) {
      iVar17 = (*(code *)PTR_sk_value_006a7f24)(uVar34,ppppppuStack_448);
      pbVar27 = *(byte **)(iVar17 + 4);
      bVar2 = *pbVar27;
      pbVar22 = pbVar27;
      while (bVar2 != 0) {
        if ((bVar2 == 0x3a) || ((bVar2 & 0xfd) == 0x2c)) {
          if (*(byte *)((int)pbVar22 + 1) != 0) {
            pbVar27 = (byte *)((int)pbVar22 + 1);
          }
          break;
        }
        pbVar22 = (byte *)((int)pbVar22 + 1);
        bVar2 = *pbVar22;
      }
      uVar29 = *(undefined4 *)(iVar17 + 8);
      iVar24 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pbVar27);
      if (iVar24 == 0) {
        iVar24 = (*(code *)PTR_strcmp_006aac20)(pbVar27,"SPKAC");
        if ((iVar24 == 0) &&
           (iVar15 = (*(code *)PTR_NETSCAPE_SPKI_b64_decode_006a81d4)
                               (*(undefined4 *)(iVar17 + 8),0xffffffff), iVar15 == 0)) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar8,"unable to load Netscape SPKAC structure\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar8);
          ppppppuStack_448 = (undefined4 ******)0xffffffff;
          goto LAB_00432264;
        }
      }
      else {
        iVar17 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a806c)
                           (uVar23,iVar24,puStack_46c,uVar29,0xffffffff,0xffffffff,0);
        if (iVar17 == 0) {
          ppppppuStack_448 = (undefined4 ******)0xffffffff;
          goto LAB_00432264;
        }
      }
    }
    if (iVar15 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"Netscape SPKAC structure not found in %s\n",ppppppuStack_430
                );
      ppppppuStack_448 = (undefined4 ******)0xffffffff;
    }
    else {
      piStack_440 = (int *)PTR_bio_err_006a7f3c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar8,"Check that the SPKAC request matches the signature\n");
      iVar17 = (*(code *)PTR_NETSCAPE_SPKI_get_pubkey_006a81ac)(iVar15);
      if (iVar17 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"error unpacking SPKAC public key\n");
        ppppppuStack_448 = (undefined4 ******)0xffffffff;
      }
      else {
        iVar24 = (*(code *)PTR_NETSCAPE_SPKI_verify_006a81b0)(iVar15,iVar17);
        if (iVar24 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar7,"signature verification failed on SPKAC public key\n");
          ppppppuStack_448 = (undefined4 ******)0xffffffff;
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"Signature ok\n");
          (*(code *)PTR_X509_REQ_set_pubkey_006a8030)(piVar20,iVar17);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar17);
          ppppppuStack_448 =
               (undefined4 ******)
               do_body(&pppppuStack_398,pcStack_488,pcVar39,ppppppuStack_428,iStack_468,
                       ppppppuStack_43c,ppppppuVar41,ppppppuVar25,ppppppuStack_48c,puStack_46c,
                       ppppppuStack_458,bVar3,pcStack_454,ppppppuStack_450,ppppppuVar13,1,iVar14,
                       piVar20,ppppppuStack_45c,ppppppuVar30,ppppppuVar10,ppppppuVar40,
                       ppppppuStack_410,uVar18,0);
        }
      }
    }
LAB_00432264:
    (*(code *)PTR_X509_REQ_free_006a7f8c)(piVar20);
    (*(code *)PTR_CONF_free_006a81b4)(ppppppuStack_460);
    if (iVar15 != 0) {
      (*(code *)PTR_NETSCAPE_SPKI_free_006a81b8)(iVar15);
      ppppppuStack_460 = ppppppuStack_448;
    }
    ppppppuVar30 = (undefined4 ******)0x0;
    if (-1 < (int)ppppppuStack_448) {
      if (ppppppuStack_448 != (undefined4 ******)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
        iVar15 = (*(code *)PTR_BN_add_word_006a81bc)(ppppppuStack_3ac,1);
        if (iVar15 == 0) goto LAB_004322e4;
        iVar15 = (*(code *)PTR_sk_push_006a80a8)(pcVar37,pppppuStack_398);
        if (iVar15 != 0) {
          ppppppuVar30 = (undefined4 ******)0x1;
          ppppppuStack_3f4 = (undefined4 ******)0x3;
          ppppppuStack_430 = (undefined4 ******)0x3;
          if (ppppppuStack_408 != (undefined4 ******)0x0) {
            iStack_434 = 1;
          }
          ppppppuStack_448 = (undefined4 ******)&SUB_00000002;
          ppppppuStack_460 = (undefined4 ******)&SUB_00000002;
          piStack_440 = (int *)(uint)(ppppppuStack_408 != (undefined4 ******)0x0);
          ppppppuVar25 = (undefined4 ******)0x1;
          goto LAB_00432364;
        }
LAB_0043298c:
        pcVar38 = "Memory allocation failure\n";
        uVar16 = *(undefined4 *)PTR_bio_err_006a7f3c;
LAB_004329a0:
        ppppppuVar30 = (undefined4 ******)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar16,pcVar38);
        puVar33 = (undefined1 *)0x0;
        iVar14 = 1;
        goto LAB_00430528;
      }
      piStack_440 = (int *)0x0;
      ppppppuVar30 = (undefined4 ******)0x0;
      ppppppuStack_3f4 = (undefined4 ******)&SUB_00000002;
      ppppppuStack_430 = (undefined4 ******)0x3;
      ppppppuStack_448 = (undefined4 ******)0x1;
      ppppppuStack_460 = (undefined4 ******)&SUB_00000002;
      ppppppuVar25 = (undefined4 ******)0x1;
LAB_00432364:
      uVar18 = uStack_39c;
      ppppppuVar12 = ppppppuStack_3a0;
      ppppppuVar11 = ppppppuStack_3a4;
      ppppppuVar28 = ppppppuStack_3a8;
      ppppppuVar10 = ppppppuStack_3ac;
      ppppppuVar40 = ppppppuStack_448;
      ppppppuVar13 = conf;
      ppppppuVar35 = ppppppuStack_460;
      if (ppppppuStack_404 == (undefined4 ******)0x0) goto LAB_004324fc;
      ppppppuStack_408 = ppppppuStack_3ac;
      ppppppuStack_404 = ppppppuStack_3a8;
      pcStack_3f0 = (char *)conf;
      ppppppuStack_3e8 = ppppppuStack_3a0;
      ppppppuStack_3e4 = ppppppuStack_3a4;
      iVar15 = (*(code *)PTR_load_cert_006a8178)
                         (*(undefined4 *)puVar8,ppppppuVar36,3,0,uVar16,ppppppuVar36);
      if (iVar15 != 0) {
        if (iVar14 != 0) {
          (*(code *)PTR_X509_print_006a81c0)(*(undefined4 *)PTR_bio_err_006a7f3c,iVar15);
        }
        puVar7 = PTR_bio_err_006a7f3c;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar8,"Check that the request matches the signature\n");
        iVar17 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar15);
        if (iVar17 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"error unpacking public key\n");
          ppppppuStack_408 = (undefined4 ******)0xffffffff;
        }
        else {
          iVar24 = (*(code *)PTR_X509_verify_006a81c4)(iVar15,iVar17);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar17);
          if (iVar24 < 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar7,"Signature verification problems....\n");
            ppppppuStack_408 = (undefined4 ******)0x0;
          }
          else if (iVar24 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar7,"Signature did not match the certificate\n");
            ppppppuStack_408 = (undefined4 ******)0x0;
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"Signature ok\n");
            uVar34 = (*(code *)PTR_EVP_md5_006a81c8)();
            iVar17 = (*(code *)PTR_X509_to_X509_REQ_006a81cc)(iVar15,0,uVar34);
            if (iVar17 == 0) {
              ppppppuStack_408 = (undefined4 ******)0xffffffff;
            }
            else {
              ppppppuStack_408 =
                   (undefined4 ******)
                   do_body(&pppppuStack_398,pcStack_488,pcVar39,ppppppuStack_428,iStack_468,
                           ppppppuStack_43c,ppppppuVar41,ppppppuVar10,ppppppuStack_48c,puStack_46c,
                           ppppppuStack_458,bVar3,pcStack_454,ppppppuStack_450,ppppppuVar28,
                           iStack_434,iVar14,iVar17,ppppppuStack_45c,ppppppuVar13,ppppppuVar12,
                           ppppppuVar11,ppppppuStack_410,uVar18,0);
              (*(code *)PTR_X509_REQ_free_006a7f8c)(iVar17);
            }
          }
        }
        (*(code *)PTR_X509_free_006a7f90)(iVar15);
        if (-1 < (int)ppppppuStack_408) {
          ppppppuVar35 = ppppppuStack_430;
          ppppppuVar25 = ppppppuStack_460;
          if (ppppppuStack_408 != (undefined4 ******)0x0) {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
            iVar15 = (*(code *)PTR_BN_add_word_006a81bc)(ppppppuStack_3ac,1);
            if (iVar15 == 0) goto LAB_004322e4;
            iVar15 = (*(code *)PTR_sk_push_006a80a8)(pcVar37,pppppuStack_398);
            if (iVar15 == 0) goto LAB_0043298c;
            ppppppuStack_448 = ppppppuStack_3f4;
            ppppppuVar30 = ppppppuVar40;
          }
LAB_004324fc:
          ppppppuStack_460 = ppppppuVar25;
          ppppppuVar36 = ppppppuStack_460;
          if (ppppppuStack_424 != (undefined4 ******)0x0) {
            iVar15 = certify(&pppppuStack_398,ppppppuStack_424,pcStack_488,ppppppuStack_3fc,
                             ppppppuStack_428,iStack_468,ppppppuStack_43c,ppppppuVar41,
                             ppppppuStack_3ac,ppppppuStack_48c,puStack_46c,ppppppuStack_458,bVar3,
                             pcStack_454,ppppppuStack_450,ppppppuStack_3a8,iStack_434,
                             ppppppuStack_45c,conf,iVar14,ppppppuStack_3a0,ppppppuStack_3a4,
                             ppppppuStack_410,uStack_39c,iStack_418);
            if (iVar15 < 0) goto LAB_004322e4;
            ppppppuVar36 = ppppppuVar35;
            if (iVar15 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
              iVar15 = (*(code *)PTR_BN_add_word_006a81bc)(ppppppuStack_3ac,1);
              if (iVar15 == 0) goto LAB_004322e4;
              iVar15 = (*(code *)PTR_sk_push_006a80a8)(pcVar37,pppppuStack_398);
              ppppppuVar30 = ppppppuStack_448;
              if (iVar15 == 0) goto LAB_0043298c;
            }
          }
          ppppppuStack_460 = (undefined4 ******)((int)ppppppuVar36 + (int)ppppppuVar44);
          ppppppuVar25 = ppppppuVar36;
          if (0 < (int)ppppppuVar44) {
            ppppppuVar44 = &pppppuStack_398;
            ppppppuStack_448 = (undefined4 ******)0x63bac8;
            do {
              ppppppuVar36 = (undefined4 ******)((int)ppppppuVar36 + 1);
              iVar15 = certify(ppppppuVar44,*pppppppuVar26,pcStack_488,ppppppuStack_3fc,
                               ppppppuStack_428,iStack_468,ppppppuStack_43c,ppppppuVar41,
                               ppppppuStack_3ac,ppppppuStack_48c,puStack_46c,ppppppuStack_458,bVar3,
                               pcStack_454,ppppppuStack_450,ppppppuStack_3a8,iStack_434,
                               ppppppuStack_45c,conf,iVar14,ppppppuStack_3a0,ppppppuStack_3a4,
                               ppppppuStack_410,uStack_39c,iStack_418);
              if (iVar15 < 0) goto LAB_004322e4;
              if (iVar15 != 0) {
                ppppppuVar30 = (undefined4 ******)((int)ppppppuVar30 + 1);
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"\n");
                iVar15 = (*(code *)PTR_BN_add_word_006a81bc)(ppppppuStack_3ac,1);
                if (iVar15 == 0) goto LAB_004322e4;
                iVar15 = (*(code *)PTR_sk_push_006a80a8)(pcVar37,pppppuStack_398);
                if (iVar15 == 0) goto LAB_0043298c;
              }
              pppppppuVar26 = pppppppuVar26 + 1;
              ppppppuVar25 = ppppppuStack_460;
            } while (ppppppuStack_460 != ppppppuVar36);
          }
          ppppppuStack_460 = ppppppuVar25;
          iVar15 = (*(code *)PTR_sk_num_006a7f2c)(pcVar37);
          puVar7 = PTR_bio_err_006a7f3c;
          if (0 < iVar15) {
            if (iStack_434 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar8,
                         "\n%d out of %d certificate requests certified, commit? [y/n]",ppppppuVar30
                         ,ppppppuStack_460);
              (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar8,0xb,0,0);
              auStack_374[0] = auStack_374[0] & 0xffffff;
              iVar15 = (*(code *)PTR_fgets_006aabe8)
                                 (auStack_374,10,*(undefined4 *)PTR_stdin_006aab20);
              if (iVar15 == 0) {
                uVar16 = *(undefined4 *)puVar7;
                pcVar38 = "CERTIFICATION CANCELED: I/O error\n";
              }
              else {
                if ((auStack_374[0]._0_1_ & 0xdf) == 0x59) goto LAB_00432a08;
                uVar16 = *(undefined4 *)puVar7;
                pcVar38 = "CERTIFICATION CANCELED\n";
              }
              ppppppuVar30 = (undefined4 ******)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar16,pcVar38);
              goto LAB_0043280c;
            }
LAB_00432a08:
            uVar34 = *(undefined4 *)puVar8;
            uVar18 = (*(code *)PTR_sk_num_006a7f2c)(pcVar37);
            (*(code *)PTR_BIO_printf_006a7f38)
                      (uVar34,"Write out database with %d new entries\n",uVar18);
            iVar15 = (*(code *)PTR_save_serial_006a81d0)(ppppppuStack_40c,"new",ppppppuStack_3ac,0);
            if ((iVar15 == 0) ||
               (iVar15 = (*(code *)PTR_save_index_006a8190)(ppppppuStack_42c,"new",ppppppuVar41),
               iVar15 == 0)) goto LAB_004322e4;
          }
          if (iVar14 != 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"writing new certificates\n");
          }
          puStack_46c = &DAT_0063ba98;
          ppppppuStack_460 = (undefined4 ******)&DAT_00635448;
          ppppppuStack_45c = (undefined4 ******)0x630000;
          for (iVar15 = 0; iVar17 = (*(code *)PTR_sk_num_006a7f2c)(pcVar37),
              pppppppuVar26 = pppppppuStack_478, ppppppuStack_48c = (undefined4 ******)pcVar39,
              iVar15 < iVar17; iVar15 = iVar15 + 1) {
            pppppuStack_398 = (undefined4 *****)(*(code *)PTR_sk_value_006a7f24)(pcVar37,iVar15);
            ppppppuVar44 = (undefined4 ******)*(*pppppuStack_398)[1];
            ppppppuVar30 = (undefined4 ******)(*pppppuStack_398)[1][2];
            uVar19 = (*(code *)PTR_strlen_006aab30)(ppppppuStack_44c);
            if (ppppppuVar44 == (undefined4 ******)0x0) {
              if (0xf7 < uVar19) goto LAB_00433018;
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_174,ppppppuStack_44c,uVar19 + 1,0x100);
              (*(code *)PTR_BUF_strlcat_006a8068)(auStack_174,&DAT_0063ba98,0x100);
              iVar17 = (*(code *)PTR_strlen_006aab30)(auStack_174);
              ppppppuVar36 = (undefined4 ******)(auStack_174 + iVar17);
LAB_00432f54:
              ppppppuVar25 = (undefined4 ******)((int)ppppppuVar36 + 2);
              auStack_174[iVar17] = 0x30;
              *(byte *)((int)ppppppuVar36 + 1) = 0x30;
            }
            else {
              if ((uint)((0x7d - (int)ppppppuVar44) * 2) <= uVar19) {
LAB_00433018:
                uVar16 = *(undefined4 *)puVar8;
                pcVar38 = "certificate file name too long\n";
                goto LAB_004329a0;
              }
              (*(code *)PTR___memcpy_chk_006aab54)(auStack_174,ppppppuStack_44c,uVar19 + 1,0x100);
              (*(code *)PTR_BUF_strlcat_006a8068)(auStack_174,&DAT_0063ba98,0x100);
              iVar17 = (*(code *)PTR_strlen_006aab30)(auStack_174);
              ppppppuVar25 = (undefined4 ******)(auStack_174 + iVar17);
              ppppppuVar36 = ppppppuVar25;
              if ((int)ppppppuVar44 < 1) goto LAB_00432f54;
              if (ppppppuVar25 < apppppuStack_74) {
                pcStack_454 = (char *)((int)ppppppuVar30 + (int)ppppppuVar44);
                ppppppuVar44 = (undefined4 ******)
                               ((int)ppppppuVar30 +
                               ((uint)((int)apppppuStack_74 + (1 - (int)(auStack_174 + iVar17 + 2)))
                               >> 1) + 1);
                ppppppuVar13 = (undefined4 ******)(auStack_174 + iVar17 + 2);
                do {
                  ppppppuVar25 = ppppppuVar13;
                  ppppppuVar40 = (undefined4 ******)((int)ppppppuVar30 + 1);
                  (*(code *)PTR_BIO_snprintf_006a8060)
                            (ppppppuVar36,(int)apppppuStack_74 - (int)ppppppuVar36,&DAT_00635448,
                             *(byte *)ppppppuVar30);
                  ppppppuStack_458 = apppppuStack_74;
                  ppppppuStack_450 = ppppppuVar25;
                  if (ppppppuVar40 == (undefined4 ******)pcStack_454) break;
                  ppppppuVar36 = ppppppuVar25;
                  ppppppuVar13 = (undefined4 ******)((int)ppppppuVar25 + 2);
                  ppppppuVar30 = ppppppuVar40;
                } while (ppppppuVar44 != ppppppuVar40);
              }
            }
            ppppppuVar28 = (undefined4 ******)auStack_174;
            *(byte *)(ppppppuVar25 + 1) = 0;
            *(byte *)ppppppuVar25 = 0x2e;
            *(byte *)((int)ppppppuVar25 + 1) = 0x70;
            *(byte *)((int)ppppppuVar25 + 2) = 0x65;
            *(byte *)((int)ppppppuVar25 + 3) = 0x6d;
            if (iVar14 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"writing %s\n",ppppppuVar28);
            }
            iVar17 = (*(code *)PTR_BIO_ctrl_006a7f18)(pppppppuStack_478,0x6c,5,ppppppuVar28);
            pppppuVar32 = pppppuStack_398;
            pcVar43 = (code *)PTR_perror_006aab88;
            if (iVar17 < 1) goto LAB_00432c2c;
            if (bVar5) {
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(pppppppuStack_478,pppppuStack_398);
              pppppuVar32 = pppppuStack_398;
              if (piStack_440 == (int *)0x0) goto LAB_00432ffc;
LAB_00433030:
              (*(code *)PTR_i2d_X509_bio_006a801c)(ppppppuStack_480,pppppuStack_398);
            }
            else {
              (*(code *)PTR_X509_print_006a81c0)(pppppppuStack_478,pppppuStack_398);
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(pppppppuStack_478,pppppuVar32);
              pppppuVar32 = pppppuStack_398;
              if (piStack_440 != (int *)0x0) goto LAB_00433030;
              (*(code *)PTR_X509_print_006a81c0)(ppppppuStack_480,pppppuStack_398);
LAB_00432ffc:
              (*(code *)PTR_PEM_write_bio_X509_006a8020)(ppppppuStack_480,pppppuVar32);
            }
          }
          iVar15 = (*(code *)PTR_sk_num_006a7f2c)(pcVar37);
          if (iVar15 != 0) {
            iVar15 = (*(code *)PTR_rotate_serial_006a8218)(ppppppuStack_40c,"new","old");
            if ((iVar15 == 0) ||
               (iVar15 = (*(code *)PTR_rotate_index_006a8194)(ppppppuStack_42c,"new","old"),
               iVar15 == 0)) goto LAB_004322e4;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"Data Base Updated\n");
          }
LAB_004330e0:
          ppppppuVar30 = (undefined4 ******)0x0;
          if (bVar4) {
            if ((ppppppuStack_438 == (undefined4 ******)0x0) &&
               (ppppppuStack_438 =
                     (undefined4 ******)
                     (*(code *)PTR_NCONF_get_string_006a7fa8)
                               (conf,*(undefined4 *)(puStack_498 + -0x4df8),"crl_extensions"),
               ppppppuStack_438 == (undefined4 ******)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_390,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_390,conf);
              iVar15 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                 (conf,auStack_390,ppppppuStack_438,0);
              if (iVar15 == 0) {
                ppppppuVar30 = (undefined4 ******)0x0;
                puVar33 = (undefined1 *)0x0;
                iVar14 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"Error Loading CRL extension section %s\n",
                           ppppppuStack_438);
                goto LAB_00430528;
              }
            }
            ppppppuStack_48c =
                 (undefined4 ******)
                 (*(code *)PTR_NCONF_get_string_006a7fa8)
                           (conf,*(undefined4 *)(puStack_498 + -0x4df8),"crlnumber");
            if (ppppppuStack_48c == (undefined4 ******)0x0) {
              puVar33 = (undefined1 *)0x0;
            }
            else {
              puVar33 = (undefined1 *)(*(code *)PTR_load_serial_006a81a0)(ppppppuStack_48c,0,0);
              if (puVar33 == (undefined1 *)0x0) {
                ppppppuVar30 = (undefined4 ******)0x0;
                iVar14 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,"error while loading CRL number\n");
                goto LAB_00430528;
              }
            }
            if (((iStack_3b8 == 0) && (iStack_3b4 == 0)) && (iStack_400 == 0)) {
              iVar15 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                 (conf,*(undefined4 *)(puStack_498 + -0x4df8),"default_crl_days",
                                  &iStack_3b8);
              if (iVar15 == 0) {
                iStack_3b8 = 0;
              }
              iVar15 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                 (conf,*(undefined4 *)(puStack_498 + -0x4df8),"default_crl_hours",
                                  &iStack_3b4);
              if (iVar15 == 0) {
                iStack_3b4 = 0;
              }
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              if ((iStack_3b8 == 0) && (iStack_3b4 == 0)) {
                ppppppuVar30 = (undefined4 ******)0x0;
                iVar14 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar8,
                           "cannot lookup how long until the next CRL is issued\n");
                goto LAB_00430528;
              }
            }
            if (iVar14 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"making CRL\n");
            }
            ppppppuVar30 = (undefined4 ******)(*(code *)PTR_X509_CRL_new_006a81d8)();
            if (ppppppuVar30 == (undefined4 ******)0x0) goto LAB_004322ec;
            uVar18 = (*(code *)PTR_X509_get_subject_name_006a8000)(pcVar39);
            iVar15 = (*(code *)PTR_X509_CRL_set_issuer_name_006a81dc)(ppppppuVar30,uVar18);
            if ((iVar15 == 0) ||
               (pppppppuVar26 = (undefined4 *******)(*(code *)PTR_ASN1_TIME_new_006a81e0)(),
               pppppppuVar26 == (undefined4 *******)0x0)) goto LAB_004322ec;
            (*(code *)PTR_X509_gmtime_adj_006a808c)(pppppppuVar26,0);
            (*(code *)PTR_X509_CRL_set_lastUpdate_006a81e4)(ppppppuVar30,pppppppuVar26);
            iVar15 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                               (pppppppuVar26,iStack_3b8,iStack_3b4 * 0xe10 + iStack_400,0);
            if (iVar15 == 0) {
              iVar14 = 1;
              (*(code *)PTR_BIO_puts_006a8058)
                        (*(undefined4 *)puVar8,"error setting CRL nextUpdate\n");
              goto LAB_00430528;
            }
            ppppppuVar44 = &ppppppuStack_3ac;
            (*(code *)PTR_X509_CRL_set_nextUpdate_006a81e8)(ppppppuVar30,pppppppuVar26);
            (*(code *)PTR_ASN1_TIME_free_006a8150)(pppppppuVar26);
            ppppppuStack_460 = (undefined4 ******)0x0;
            for (puStack_46c = (undefined *)0x0;
                iVar15 = (*(code *)PTR_sk_num_006a7f2c)(ppppppuVar41[1][1]), puStack_498 = puVar33,
                (int)puStack_46c < iVar15; puStack_46c = puStack_46c + 1) {
              ppcVar21 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppppppuVar41[1][1],puStack_46c);
              if (**ppcVar21 == 'R') {
                pppppppuVar26 = (undefined4 *******)(*(code *)PTR_X509_REVOKED_new_006a81ec)();
                if ((pppppppuVar26 == (undefined4 *******)0x0) ||
                   (iVar15 = make_revoked(pppppppuVar26,ppcVar21[2]), iVar15 == 0)) {
LAB_004336fc:
                  iVar14 = 1;
                  goto LAB_00430528;
                }
                if (iVar15 == 2) {
                  ppppppuStack_460 = (undefined4 ******)0x1;
                }
                iVar15 = (*(code *)PTR_BN_hex2bn_006a81f0)(ppppppuVar44,ppcVar21[3]);
                if (iVar15 == 0) goto LAB_004336fc;
                iVar15 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(ppppppuStack_3ac,0);
                (*(code *)PTR_BN_free_006a811c)(ppppppuStack_3ac);
                ppppppuStack_3ac = (undefined4 ******)0x0;
                if (iVar15 == 0) goto LAB_004336fc;
                (*(code *)PTR_X509_REVOKED_set_serialNumber_006a81f8)(pppppppuVar26,iVar15);
                (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar15);
                (*(code *)PTR_X509_CRL_add0_revoked_006a81fc)(ppppppuVar30,pppppppuVar26);
              }
            }
            (*(code *)PTR_X509_CRL_sort_006a8200)(ppppppuVar30);
            if (iVar14 != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"signing CRL\n");
            }
            if (ppppppuStack_438 == (undefined4 ******)0x0) {
              if (ppppppuStack_48c == (undefined4 ******)0x0) {
                if (ppppppuStack_460 != (undefined4 ******)0x0) goto LAB_004336c0;
              }
              else {
                (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_390,pcVar39,0,0,ppppppuVar30,0);
                (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_390,conf);
LAB_004334bc:
                iVar14 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(puVar33,0);
                if (iVar14 == 0) goto LAB_004322ec;
                (*(code *)PTR_X509_CRL_add1_ext_i2d_006a820c)(ppppppuVar30,0x58,iVar14,0,0);
                (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar14);
                iVar14 = (*(code *)PTR_BN_add_word_006a81bc)(puVar33,1);
                if ((iVar14 == 0) ||
                   (iVar14 = (*(code *)PTR_X509_CRL_set_version_006a8208)(ppppppuVar30,1),
                   iVar14 == 0)) goto LAB_004322ec;
                if (ppppppuStack_48c != (undefined4 ******)0x0) {
                  iVar14 = (*(code *)PTR_save_serial_006a81d0)(ppppppuStack_48c,"new",puVar33,0);
                  goto joined_r0x0043355c;
                }
              }
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_390,pcVar39,0,0,ppppppuVar30,0);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_390,conf);
              iVar14 = (*(code *)PTR_X509V3_EXT_CRL_add_nconf_006a8204)
                                 (conf,auStack_390,ppppppuStack_438,ppppppuVar30);
              pppppppuVar26 = pppppppuStack_490;
              if (iVar14 == 0) goto LAB_004322ec;
              if (ppppppuStack_48c != (undefined4 ******)0x0) goto LAB_004334bc;
LAB_004336c0:
              iVar14 = (*(code *)PTR_X509_CRL_set_version_006a8208)(ppppppuVar30,1);
joined_r0x0043355c:
              if (iVar14 == 0) goto LAB_004322ec;
            }
            if (puVar33 != (undefined1 *)0x0) {
              (*(code *)PTR_BN_free_006a811c)(puVar33);
            }
            iVar14 = do_X509_CRL_sign(*(undefined4 *)puVar8,ppppppuVar30,pcStack_488,
                                      ppppppuStack_428,iStack_468);
            if ((iVar14 == 0) ||
               (((*(code *)PTR_PEM_write_bio_X509_CRL_006a8214)(ppppppuStack_480,ppppppuVar30),
                ppppppuStack_48c != (undefined4 ******)0x0 &&
                (iVar14 = (*(code *)PTR_rotate_serial_006a8218)(ppppppuStack_48c,"new","old"),
                iVar14 == 0)))) goto LAB_004322e8;
          }
          if (!bVar6) {
LAB_0043280c:
            puVar33 = (undefined1 *)0x0;
            iVar14 = 0;
            goto LAB_00430528;
          }
          if (ppppppuStack_424 == (undefined4 ******)0x0) {
            puVar33 = (undefined1 *)0x0;
            iVar14 = 1;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar8,"no input files\n");
            goto LAB_00430528;
          }
          iVar14 = (*(code *)PTR_load_cert_006a8178)
                             (*(undefined4 *)puVar8,ppppppuStack_424,3,0,uVar16,ppppppuStack_424);
          if ((iVar14 != 0) &&
             (iVar15 = do_revoke(iVar14,ppppppuVar41,uStack_420,ppppppuStack_41c), 0 < iVar15)) {
            (*(code *)PTR_X509_free_006a7f90)(iVar14);
            iVar14 = (*(code *)PTR_save_index_006a8190)(ppppppuStack_42c,"new",ppppppuVar41);
            if ((iVar14 != 0) &&
               (iVar14 = (*(code *)PTR_rotate_index_006a8194)(ppppppuStack_42c,"new","old"),
               iVar14 != 0)) {
              puVar33 = (undefined1 *)0x0;
              iVar14 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)PTR_bio_err_006a7f3c,"Data Base Updated\n");
              goto LAB_00430528;
            }
          }
          goto LAB_004322e8;
        }
      }
LAB_004322e4:
      ppppppuVar30 = (undefined4 ******)0x0;
    }
  }
LAB_004322e8:
  puVar33 = (undefined1 *)0x0;
LAB_004322ec:
  iVar14 = 1;
  goto LAB_00430528;
}

