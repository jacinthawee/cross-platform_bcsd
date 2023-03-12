
/* WARNING: Type propagation algorithm not settling */

uint do_X509_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  byte *pbVar25;
  int iVar26;
  char *pcVar27;
  int iVar28;
  undefined4 *puVar29;
  byte bVar30;
  undefined4 uVar31;
  char **ppcVar32;
  int *piVar33;
  byte *pbVar34;
  char **ppcVar35;
  char *pcVar36;
  uint uVar37;
  int *piVar38;
  char *pcVar39;
  code *pcVar40;
  char *pcStack_638;
  int iStack_630;
  undefined4 *puStack_624;
  char *pcStack_620;
  char *pcStack_61c;
  undefined4 *puStack_618;
  int iStack_614;
  int iStack_60c;
  char *pcStack_608;
  char *pcStack_5fc;
  char *pcStack_5f8;
  int iStack_5f4;
  char *pcStack_5ec;
  char *pcStack_5e8;
  char *pcStack_5e0;
  char *pcStack_5dc;
  char *pcStack_5d8;
  char *pcStack_5d4;
  int iStack_5c8;
  int iStack_5c4;
  char *pcStack_5c0;
  char *pcStack_5bc;
  char *pcStack_5b8;
  int iStack_5a8;
  int iStack_5a4;
  undefined4 uStack_5a0;
  char *pcStack_59c;
  char *pcStack_594;
  undefined4 uStack_590;
  undefined4 uStack_58c;
  int iStack_588;
  int iStack_584;
  int iStack_580;
  int iStack_57c;
  int iStack_578;
  int iStack_574;
  char *pcStack_570;
  undefined4 auStack_56c [7];
  undefined auStack_550 [99];
  char acStack_4ed [1025];
  int iStack_ec;
  uint uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 *puStack_dc;
  undefined *puStack_d8;
  undefined4 *puStack_d4;
  int iStack_d0;
  undefined4 uStack_a0;
  undefined4 auStack_9c [6];
  int iStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  code *pcStack_64;
  undefined4 local_50;
  undefined *local_48;
  undefined4 local_40;
  undefined4 auStack_3c [6];
  int local_24;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  puStack_74 = auStack_3c;
  local_48 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_74);
  local_40 = 0;
  (**(code **)(local_48 + -0x7fc4))(puStack_74);
  uVar31 = 0;
  puStack_d4 = &local_40;
  local_50 = param_3;
  iVar17 = (**(code **)(local_48 + -0x7fc0))(puStack_74,puStack_d4,param_4,0);
  if (iVar17 == 0) {
LAB_00424130:
    uStack_80 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (**(code **)(local_48 + -0x7fb4))(param_5), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_3 = (**(code **)(local_48 + -0x7fbc))(param_5,iVar17);
      iVar18 = (**(code **)(local_48 + -0x7fb8))(local_40,param_3);
      if (iVar18 < 1) {
        puStack_d4 = (undefined4 *)0x633dc4;
        param_4 = param_3;
        (**(code **)(local_48 + -0x7fa8))(param_1);
        (**(code **)(local_48 + -0x7fa0))(**(undefined4 **)(local_48 + -0x7fa4));
        goto LAB_00424130;
      }
    }
    puStack_d4 = puStack_74;
    iVar17 = (**(code **)(local_48 + -0x7fb0))(param_2);
    uStack_80 = (uint)(0 < iVar17);
  }
  (**(code **)(local_48 + -0x7fac))(puStack_74);
  if (local_24 == *(int *)puStack_70) {
    return uStack_80;
  }
  pcStack_64 = do_X509_REQ_sign;
  iStack_d0 = local_24;
  (**(code **)(local_48 + -0x5330))();
  uStack_e4 = local_50;
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  puStack_dc = auStack_9c;
  uStack_7c = param_5;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_78 = param_3;
  uStack_6c = param_2;
  uStack_68 = param_1;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_dc);
  uStack_a0 = 0;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_dc);
  puVar29 = &uStack_a0;
  iVar17 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(puStack_dc,puVar29,uVar31,0);
  if (iVar17 == 0) {
LAB_004242c8:
    uStack_e8 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (*(code *)PTR_sk_num_006a6e2c)(uStack_e4), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_4 = (*(code *)PTR_sk_value_006a6e24)(uStack_e4,iVar17);
      iVar18 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(uStack_a0,param_4);
      if (iVar18 < 1) {
        puVar29 = (undefined4 *)0x633dc4;
        (*(code *)PTR_BIO_printf_006a6e38)(iStack_d0,"parameter error \"%s\"\n",param_4);
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_004242c8;
      }
    }
    puVar29 = puStack_dc;
    iVar17 = (*(code *)PTR_X509_REQ_sign_ctx_006a6e44)(puStack_d4);
    uStack_e8 = (uint)(0 < iVar17);
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puStack_dc);
  if (iStack_84 == *(int *)puStack_d8) {
    return uStack_e8;
  }
  iVar17 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar15 = PTR___stack_chk_guard_006a9ae8;
  puVar13 = PTR_bio_err_006a6e3c;
  iStack_580 = -1;
  iStack_57c = -1;
  req_conf = 0;
  uStack_590 = 0;
  uStack_58c = 0;
  iStack_588 = 0;
  iStack_584 = 0;
  iStack_578 = 0;
  iStack_574 = 0;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_e0 = param_4;
  iStack_5c8 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar13 == 0) {
    uVar31 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar31);
    *(int *)puVar13 = iVar18;
    if (iVar18 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  uVar31 = *puVar29;
  iVar17 = iVar17 + -1;
  ppcVar32 = (char **)(puVar29 + 1);
  iStack_5f4 = 0x1001;
  if (iVar17 < 1) {
    pcStack_5b8 = (char *)0x0;
    pcStack_5e0 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_61c = (char *)0x0;
    piVar38 = (int *)0x3;
    uStack_5a0 = 3;
    pcStack_620 = (char *)0x0;
    pcStack_594 = (char *)0x0;
    bVar9 = false;
    iStack_614 = 0;
    pcStack_5e8 = (char *)0x0;
    pcStack_5ec = (char *)0x0;
    pcStack_638 = (char *)0x0;
    pcStack_5d4 = (char *)0x0;
    pcStack_5fc = (char *)0x0;
    pcStack_608 = (char *)0x0;
    pcStack_5d8 = (char *)0x0;
    pcStack_5bc = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_59c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_5dc = (char *)0x0;
    pcStack_5f8 = (char *)0x0;
    puStack_618 = (undefined4 *)0x0;
    puStack_624 = (undefined4 *)0x0;
    pcStack_5c0 = (char *)0x0;
    iStack_5a4 = 0x1e;
    bVar5 = false;
    iStack_630 = 0;
    iStack_5c4 = 0;
    iStack_5a8 = 0;
  }
  else {
    iStack_5c4 = 0;
    iStack_5a8 = 0;
    pcStack_5b8 = (char *)0x0;
    uStack_5a0 = 3;
    pcStack_5e0 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_61c = (char *)0x0;
    piVar38 = (int *)0x3;
    iStack_5a4 = 0x1e;
    pcStack_620 = (char *)0x0;
    pcStack_594 = (char *)0x0;
    bVar9 = false;
    iStack_614 = 0;
    pcStack_5e8 = (char *)0x0;
    pcStack_5ec = (char *)0x0;
    pcStack_638 = (char *)0x0;
    pcStack_5d4 = (char *)0x0;
    pcStack_5fc = (char *)0x0;
    pcStack_608 = (char *)0x0;
    pcStack_5d8 = (char *)0x0;
    pcStack_5bc = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_59c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_5dc = (char *)0x0;
    pcStack_5f8 = (char *)0x0;
    puStack_618 = (undefined4 *)0x0;
    puStack_624 = (undefined4 *)0x0;
    pcStack_5c0 = (char *)0x0;
    bVar5 = false;
    iStack_630 = 0;
LAB_004244a8:
    do {
      pcVar36 = *ppcVar32;
      iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-inform");
      iVar18 = iStack_5c4;
      if (iVar19 == 0) {
        iVar17 = iVar17 + -1;
        if (iVar17 != 0) {
          piVar38 = (int *)(*(code *)PTR_str2fmt_006a6e4c)(ppcVar32[1]);
          ppcVar35 = ppcVar32 + 1;
          goto LAB_0042449c;
        }
LAB_0042485c:
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"%s [options] <infile >outfile\n",uVar31);
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"where options  are\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -inform arg    input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -outform arg   output format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -in arg        input file\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -out arg       output file\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -text          text form of request\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -pubkey        output public key\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -noout         do not output REQ\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -verify        verify signature on REQ\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -modulus       RSA modulus\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -nodes         don\'t encrypt the output key\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -engine e      use engine e, possibly a hardware device\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -subject       output the request\'s subject\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -passin        private key password source\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -key file      use the private key contained in file\n")
        ;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -keyform arg   key file format\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -keyout arg    file to send the key to\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   "                load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"                the random number generator\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -config file   request template file.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -subj arg      set or modify request subject\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -multivalue-rdn enable support for multivalued RDNs\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13," -new           new request.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -batch         do not ask anything during request generation\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -x509          output a x509 structure instead of a cert. req.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -newhdr        output \"NEW\" in the header lines\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"                have been reported as requiring\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,
                   " -utf8          input characters are UTF8 (default ASCII)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -nameopt arg    - various certificate name options\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13," -reqopt arg    - various request text options\n\n");
        goto LAB_00424800;
      }
      iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-outform");
      if (iVar19 != 0) {
        iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-engine");
        if (iVar19 == 0) {
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) goto LAB_0042485c;
          pcStack_638 = ppcVar32[1];
          ppcVar35 = ppcVar32 + 1;
        }
        else {
          iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keygen_engine");
          if (iVar19 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_0042485c;
            iStack_630 = (*(code *)PTR_ENGINE_by_id_006a6e9c)(ppcVar32[1]);
            ppcVar35 = ppcVar32 + 1;
            if (iStack_630 == 0) {
              pcVar36 = ppcVar32[1];
              uVar31 = *(undefined4 *)puVar13;
              pcVar27 = "Can\'t find keygen engine %s\n";
              goto LAB_004247f4;
            }
          }
          else {
            iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_006326ec);
            if (iVar19 == 0) {
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_0042485c;
              pcStack_608 = ppcVar32[1];
              ppcVar35 = ppcVar32 + 1;
            }
            else {
              iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-pubkey");
              ppcVar35 = ppcVar32;
              if (iVar19 == 0) {
                bVar11 = true;
              }
              else {
                iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_006326fc);
                if (iVar19 == 0) {
                  pcStack_5f8 = (char *)0x1;
                }
                else {
                  iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-config");
                  if (iVar19 == 0) {
                    iVar17 = iVar17 + -1;
                    if (iVar17 == 0) goto LAB_0042485c;
                    pcStack_5fc = ppcVar32[1];
                    ppcVar35 = ppcVar32 + 1;
                  }
                  else {
                    iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keyform");
                    if (iVar19 == 0) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042485c;
                      uStack_5a0 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar32[1]);
                      ppcVar35 = ppcVar32 + 1;
                    }
                    else if ((((*pcVar36 == '-') && (pcVar36[1] == 'i')) && (pcVar36[2] == 'n')) &&
                            (pcVar36[3] == '\0')) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042485c;
                      pcStack_5bc = ppcVar32[1];
                      ppcVar35 = ppcVar32 + 1;
                    }
                    else {
                      iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,&DAT_00632514);
                      if (iVar19 == 0) {
                        iVar17 = iVar17 + -1;
                        if (iVar17 == 0) goto LAB_0042485c;
                        pcStack_5d8 = ppcVar32[1];
                        ppcVar35 = ppcVar32 + 1;
                      }
                      else {
                        iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-keyout");
                        if (iVar19 == 0) {
                          iVar17 = iVar17 + -1;
                          if (iVar17 == 0) goto LAB_0042485c;
                          pcStack_5d4 = ppcVar32[1];
                          ppcVar35 = ppcVar32 + 1;
                        }
                        else {
                          iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-passin");
                          if (iVar19 == 0) {
                            iVar17 = iVar17 + -1;
                            if (iVar17 == 0) goto LAB_0042485c;
                            pcStack_620 = ppcVar32[1];
                            ppcVar35 = ppcVar32 + 1;
                          }
                          else {
                            iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-passout");
                            if (iVar19 == 0) {
                              iVar17 = iVar17 + -1;
                              if (iVar17 == 0) goto LAB_0042485c;
                              pcStack_61c = ppcVar32[1];
                              ppcVar35 = ppcVar32 + 1;
                            }
                            else {
                              iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-rand");
                              if (iVar19 == 0) {
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042485c;
                                pcStack_594 = ppcVar32[1];
                                ppcVar35 = ppcVar32 + 1;
                              }
                              else {
                                iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-newkey");
                                if (iVar19 != 0) {
                                  iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-pkeyopt");
                                  if (iVar19 == 0) {
                                    if (iVar17 != 1) {
                                      puVar29 = puStack_624;
                                      pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                      if (puStack_624 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a6fa4)();
                                        puStack_624 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a6fa8;
joined_r0x00427498:
                                        PTR_sk_push_006a6fa8 = pcVar40;
                                        if (puVar29 == (undefined4 *)0x0) goto LAB_0042485c;
                                      }
LAB_00427414:
                                      iVar19 = (*pcVar40)(puVar29,ppcVar32[1]);
joined_r0x004277e0:
                                      iVar17 = iVar17 + -1;
                                      ppcVar35 = ppcVar32 + 1;
                                      if (iVar19 != 0) goto LAB_0042449c;
                                    }
                                  }
                                  else {
                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-sigopt");
                                    if (iVar19 != 0) {
                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-batch");
                                      if (iVar19 == 0) {
                                        batch = 1;
                                      }
                                      else {
                                        iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar36,"-newhdr");
                                        if (iVar19 == 0) {
                                          bVar12 = true;
                                        }
                                        else {
                                          iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                             (pcVar36,"-modulus");
                                          if (iVar19 == 0) {
                                            bVar9 = true;
                                          }
                                          else {
                                            iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar36,"-verify");
                                            if (iVar19 == 0) {
                                              bVar6 = true;
                                            }
                                            else {
                                              iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (pcVar36,"-nodes");
                                              if (iVar19 == 0) {
                                                pcStack_59c = (char *)0x1;
                                              }
                                              else {
                                                iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (pcVar36,"-noout");
                                                if (iVar19 == 0) {
                                                  bVar7 = true;
                                                }
                                                else {
                                                  iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar36,"-verbose");
                                                  if (iVar19 == 0) {
                                                    pcStack_5dc = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-utf8");
                                                    if (iVar19 != 0) {
                                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-nameopt");
                                                      if (iVar19 == 0) {
                                                        if (iVar17 != 1) {
                                                          puVar29 = &uStack_590;
                                                          pcVar40 = (code *)PTR_set_name_ex_006a6fac
                                                          ;
                                                          goto LAB_00427414;
                                                        }
                                                      }
                                                      else {
                                                        iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar36,"-reqopt");
                                                        if (iVar19 != 0) {
                                                          iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar36,"-subject");
                                                          if (iVar19 == 0) {
                                                            bVar10 = true;
                                                          }
                                                          else {
                                                            iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar36,"-text");
                                                            if (iVar19 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar19 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(pcVar36,"-x509");
                                                              if (iVar19 == 0) {
                                                                bVar5 = true;
                                                              }
                                                              else {
                                                                iVar19 = (*(code *)
                                                  PTR_strcmp_006a9b18)(pcVar36,"-asn1-kludge");
                                                  if (iVar19 == 0) {
                                                    bVar4 = true;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-no-asn1-kludge");
                                                    if (iVar19 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-subj");
                                                      if (iVar19 == 0) {
                                                        iVar17 = iVar17 + -1;
                                                        if (iVar17 == 0) goto LAB_0042485c;
                                                        pcStack_5e0 = ppcVar32[1];
                                                        ppcVar35 = ppcVar32 + 1;
                                                      }
                                                      else {
                                                        iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar36,
                                                  "-multivalue-rdn");
                                                  if (iVar19 == 0) {
                                                    pcStack_5b8 = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-days");
                                                    if (iVar19 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042485c;
                                                      ppcVar35 = ppcVar32 + 1;
                                                      iVar19 = (*(code *)PTR_strtol_006a9958)
                                                                         (ppcVar32[1],0,10);
                                                      iStack_5a4 = 0x1e;
                                                      if (iVar19 != 0) {
                                                        iStack_5a4 = iVar19;
                                                      }
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar36,"-set_serial");
                                                      if (iVar19 == 0) {
                                                        if (iVar17 == 1) goto LAB_0042485c;
                                                        iStack_614 = (*(code *)
                                                  PTR_s2i_ASN1_INTEGER_006a6fb4)(0,ppcVar32[1]);
                                                  iVar19 = iStack_614;
                                                  goto joined_r0x004277e0;
                                                  }
                                                  iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar36,"-extensions");
                                                  if (iVar19 == 0) {
                                                    iVar17 = iVar17 + -1;
                                                    if (iVar17 == 0) goto LAB_0042485c;
                                                    pcStack_5ec = ppcVar32[1];
                                                    ppcVar35 = ppcVar32 + 1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar36,"-reqexts");
                                                    if (iVar19 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042485c;
                                                      pcStack_5e8 = ppcVar32[1];
                                                      ppcVar35 = ppcVar32 + 1;
                                                    }
                                                    else {
                                                      iStack_5a8 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar36 + 1);
                                                  iVar18 = iStack_5a8;
                                                  if (iStack_5a8 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar13,
                                                               "unknown option %s\n",*ppcVar32);
                                                    goto LAB_0042485c;
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
                                                  goto LAB_0042449c;
                                                  }
                                                  if (iVar17 != 1) {
                                                    puVar29 = &uStack_58c;
                                                    pcVar40 = (code *)PTR_set_cert_ex_006a6fb0;
                                                    goto LAB_00427414;
                                                  }
                                                  }
                                                  goto LAB_0042485c;
                                                  }
                                                  iStack_5f4 = 0x1000;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_0042449c;
                                    }
                                    if (iVar17 != 1) {
                                      puVar29 = puStack_618;
                                      pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                      if (puStack_618 == (undefined4 *)0x0) {
                                        puVar29 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a6fa4)();
                                        puStack_618 = puVar29;
                                        pcVar40 = (code *)PTR_sk_push_006a6fa8;
                                        goto joined_r0x00427498;
                                      }
                                      goto LAB_00427414;
                                    }
                                  }
                                  goto LAB_0042485c;
                                }
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042485c;
                                pcStack_5c0 = ppcVar32[1];
                                pcStack_5f8 = (char *)0x1;
                                ppcVar35 = ppcVar32 + 1;
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
LAB_0042449c:
        iStack_5c4 = iVar18;
        iVar17 = iVar17 + -1;
        ppcVar32 = ppcVar35 + 1;
        if (iVar17 == 0) break;
        goto LAB_004244a8;
      }
      if (iVar17 == 1) goto LAB_0042485c;
      ppcVar35 = ppcVar32 + 1;
      iVar17 = iVar17 + -2;
      ppcVar32 = ppcVar32 + 2;
      pcVar39 = (char *)(*(code *)PTR_str2fmt_006a6e4c)(*ppcVar35);
    } while (iVar17 != 0);
  }
  puVar14 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  iVar17 = (*(code *)PTR_app_passwd_006a6e54)
                     (*(undefined4 *)puVar13,pcStack_620,pcStack_61c,&iStack_578,&iStack_574);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"Error getting passwords\n");
  }
  else {
    if (pcStack_5fc == (char *)0x0) {
      req_conf = *(int *)PTR_config_006a6e68;
      if (req_conf == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar14,"Unable to load config info from %s\n",
                   *(undefined4 *)PTR_default_config_file_006a6edc);
        if (pcStack_5f8 != (char *)0x0) {
          iVar18 = 0;
          iVar17 = 0;
          goto LAB_004245c0;
        }
LAB_00424594:
        if (req_conf != 0) goto LAB_004245a8;
LAB_00424e14:
        iVar17 = (*(code *)PTR_add_oid_section_006a6e60)(*(undefined4 *)puVar13,req_conf);
        if (iVar17 != 0) {
          if (iStack_5a8 == 0) {
            iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,&DAT_00631a94,"default_md");
            if (iVar17 == 0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              iVar17 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(iVar17);
              if (iVar17 != 0) {
                iStack_5c4 = iVar17;
              }
            }
          }
          if ((pcStack_5ec == (char *)0x0) &&
             (pcStack_5ec = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                              (req_conf,&DAT_00631a94,"x509_extensions"),
             pcStack_5ec == (char *)0x0)) {
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_00424ea4:
            piVar33 = (int *)0x630000;
            if ((iStack_578 == 0) &&
               (iStack_578 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                       (req_conf,&DAT_00631a94,"input_password"), iStack_578 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            if ((iStack_574 == 0) &&
               (iStack_574 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                       (req_conf,&DAT_00631a94,"output_password"), iStack_574 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                        (req_conf,&DAT_00631a94,"string_mask");
            if (pcVar36 == (char *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a6ec0)(pcVar36);
              if (iVar17 == 0) {
                uVar31 = *(undefined4 *)puVar13;
                pcVar27 = "Invalid global string mask setting %s\n";
                goto LAB_004247f4;
              }
            }
            if (iStack_5f4 == 0x1000) {
LAB_00424f5c:
              iStack_5f4 = 0x1000;
            }
            else {
              pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                          (req_conf,&DAT_00631a94,&DAT_00633198);
              if (pcVar36 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a6ee0)();
              }
              else if ((((*pcVar36 == 'y') && (pcVar36[1] == 'e')) && (pcVar36[2] == 's')) &&
                      (pcVar36[3] == '\0')) goto LAB_00424f5c;
            }
            if ((pcStack_5e8 == (char *)0x0) &&
               (pcStack_5e8 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                (req_conf,&DAT_00631a94,"req_extensions"),
               pcStack_5e8 == (char *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_56c,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_56c,req_conf);
              iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                 (req_conf,auStack_56c,pcStack_5e8,0);
              if (iVar17 == 0) {
                uVar31 = *(undefined4 *)puVar13;
                pcVar27 = "Error Loading request extension section %s\n";
                pcVar36 = pcStack_5e8;
                goto LAB_004247f4;
              }
            }
            uVar31 = (*(code *)PTR_BIO_s_file_006a6ea0)();
            iVar17 = (*(code *)PTR_BIO_new_006a6ea4)(uVar31);
            uVar31 = (*(code *)PTR_BIO_s_file_006a6ea0)();
            iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar31);
            if ((iVar17 != 0) && (iVar18 != 0)) {
              uVar31 = (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar13,pcStack_638,0);
              if (pcStack_608 == (char *)0x0) goto LAB_004250bc;
              iStack_584 = (*(code *)PTR_load_key_006a6ec8)
                                     (*(undefined4 *)PTR_bio_err_006a6e3c,pcStack_608,uStack_5a0,0,
                                      iStack_578,uVar31,"Private Key");
              if (iStack_584 != 0) {
                iVar19 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,&DAT_00631a94,"RANDFILE")
                ;
                if (iVar19 == 0) goto LAB_00425c40;
                goto LAB_004250a4;
              }
            }
            goto LAB_004245c0;
          }
          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_56c,0,0,0,0,1);
          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_56c,req_conf);
          iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)(req_conf,auStack_56c,pcStack_5ec,0);
          if (iVar17 != 0) goto LAB_00424ea4;
          uVar31 = *(undefined4 *)puVar13;
          pcVar27 = "Error Loading extension section %s\n";
          pcVar36 = pcStack_5ec;
LAB_004247f4:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar31,pcVar27,pcVar36);
          goto LAB_00424800;
        }
      }
      else {
        if (pcStack_5dc != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar14,"Using configuration from %s\n",
                     *(undefined4 *)PTR_default_config_file_006a6edc);
          goto LAB_00424594;
        }
LAB_004245a8:
        iVar17 = (*(code *)PTR_load_config_006a6e64)(*(undefined4 *)puVar13);
        if (iVar17 != 0) {
          iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,0,"oid_file");
          if (iVar17 == 0) {
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
          }
          else {
            iVar17 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar17,"r");
            if (iVar17 != 0) {
              (*(code *)PTR_OBJ_create_objects_006a6eb0)(iVar17);
              (*(code *)PTR_BIO_free_006a6e70)(iVar17);
            }
          }
          goto LAB_00424e14;
        }
      }
      iVar18 = 0;
      iVar17 = 0;
      goto LAB_004245c0;
    }
    auStack_56c[0] = 0xffffffff;
    if (pcStack_5dc != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar14,"Using configuration from %s\n",pcStack_5fc);
    }
    req_conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar17 = (*(code *)PTR_NCONF_load_006a6e5c)(req_conf,pcStack_5fc,auStack_56c);
    if (iVar17 != 0) goto LAB_00424594;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar13,"error on line %ld of %s\n",auStack_56c[0],pcStack_5fc);
  }
LAB_00424800:
  iVar18 = 0;
  iVar17 = 0;
LAB_004245c0:
  iVar19 = 0;
LAB_004245c8:
  piVar38 = (int *)0x0;
  piVar33 = (int *)0x0;
LAB_004245cc:
  uVar37 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
  do {
    if ((req_conf != 0) && (req_conf != *(int *)PTR_config_006a6e68)) {
      (*(code *)PTR_NCONF_free_006a6e6c)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar17);
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar18);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_584);
    if (iVar19 != 0) {
      (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar19);
    }
    if (puStack_624 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a6e80)(puStack_624);
    }
    if (puStack_618 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a6e80)(puStack_618);
    }
    if (iStack_630 != 0) {
      (*(code *)PTR_ENGINE_free_006a6e84)(iStack_630);
    }
    if (iStack_588 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_X509_REQ_free_006a6e8c)(piVar38);
    (*(code *)PTR_X509_free_006a6e90)(piVar33);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iStack_614);
    if ((pcStack_620 != (char *)0x0) && (iStack_578 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if ((pcStack_61c != (char *)0x0) && (iStack_574 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    if (iStack_ec == *(int *)puVar15) {
      return uVar37;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00425c40:
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_004250a4:
    (*(code *)PTR_app_RAND_load_file_006a6ecc)(iVar19,*(undefined4 *)puVar13,0);
LAB_004250bc:
    if (pcStack_5f8 != (char *)0x0) {
      if (iStack_584 == 0) {
        iVar20 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,piVar33 + 0x6a5,"RANDFILE");
        if (iVar20 == 0) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(iVar20,*(undefined4 *)puVar13,0);
        if (pcStack_594 != (char *)0x0) {
          (*(code *)PTR_app_RAND_load_files_006a6f38)(pcStack_594);
        }
        iVar19 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                           (req_conf,piVar33 + 0x6a5,"default_bits",&iStack_57c);
        if (iVar19 == 0) {
          iStack_57c = 0x200;
          if (pcStack_5c0 == (char *)0x0) {
LAB_00425fcc:
            iVar19 = set_keygen_ctx(*(undefined4 *)puVar13,0,&iStack_580,&iStack_57c,&iStack_588,
                                    iStack_630);
            if (iVar19 == 0) goto LAB_004245c8;
          }
          else {
LAB_00425f0c:
            iVar19 = set_keygen_ctx(*(undefined4 *)puVar13,pcStack_5c0,&iStack_580,&iStack_57c,
                                    &iStack_588,iStack_630);
            if (iVar19 == 0) goto LAB_004245c8;
            if (iStack_57c < 0x180) goto LAB_00425f48;
          }
        }
        else {
          if (pcStack_5c0 != (char *)0x0) goto LAB_00425f0c;
          if (0x17f < iStack_57c) goto LAB_00425fcc;
          iVar19 = 0;
LAB_00425f48:
          if ((iStack_580 == 6) || (iStack_580 == 0x74)) {
            piVar38 = (int *)0x0;
            piVar33 = (int *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"private key length is too short,\n");
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"it needs to be at least %d bits, not %ld\n",0x180,
                       iStack_57c);
            goto LAB_004245cc;
          }
          if (iVar19 == 0) goto LAB_00425fcc;
        }
        iVar21 = 0;
        if (puStack_624 != (undefined4 *)0x0) {
          for (; iVar22 = (*(code *)PTR_sk_num_006a6e2c)(puStack_624), iVar21 < iVar22;
              iVar21 = iVar21 + 1) {
            uVar31 = (*(code *)PTR_sk_value_006a6e24)(puStack_624,iVar21);
            iVar22 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(iVar19,uVar31);
            if (iVar22 < 1) {
              piVar38 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"parameter error \"%s\"\n",uVar31);
              piVar33 = (int *)0x0;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
              goto LAB_004245cc;
            }
          }
        }
        puVar14 = PTR_bio_err_006a6e3c;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"Generating a %ld bit %s private key\n",iStack_57c,
                   iStack_588);
        (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a6f40)(iVar19,genpkey_cb);
        (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a6f44)(iVar19,*(undefined4 *)puVar13);
        iVar21 = (*(code *)PTR_EVP_PKEY_keygen_006a6f48)(iVar19,&iStack_584);
        if (iVar21 < 1) {
          piVar33 = (int *)0x0;
          piVar38 = (int *)0x0;
          (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar14,"Error Generating Key\n");
          goto LAB_004245cc;
        }
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar19);
        (*(code *)PTR_app_RAND_write_file_006a6f4c)(iVar20,*(undefined4 *)puVar14);
        if ((pcStack_5d4 == (char *)0x0) &&
           (pcStack_5d4 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                            (req_conf,piVar33 + 0x6a5,"default_keyfile"),
           pcStack_5d4 == (char *)0x0)) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar14,"writing new private key to stdout\n");
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"writing new private key to \'%s\'\n",pcStack_5d4);
          iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,5,pcStack_5d4);
          pcVar36 = pcStack_5d4;
          if (iVar19 < 1) goto LAB_0042633c;
        }
        pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                    (req_conf,piVar33 + 0x6a5,"encrypt_rsa_key");
        if (pcVar36 == (char *)0x0) {
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                      (req_conf,piVar33 + 0x6a5,"encrypt_key");
          if (pcVar36 != (char *)0x0) goto LAB_004261ac;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        else {
LAB_004261ac:
          if (((*pcVar36 == 'n') && (pcVar36[1] == 'o')) && (pcVar36[2] == '\0')) {
            iStack_5c8 = 0;
          }
        }
        iVar19 = 4;
        if (pcStack_59c != (char *)0x0) {
          iStack_5c8 = 0;
        }
        while (iVar20 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)
                                  (iVar18,iStack_584,iStack_5c8,0,0,0,iStack_574), iVar20 == 0) {
          uVar37 = (*(code *)PTR_ERR_peek_error_006a6f54)();
          if (((uVar37 & 0xfff) != 0x6d) || (iVar19 = iVar19 + -1, iVar19 == 0)) goto LAB_004245c0;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"-----\n");
        if (iStack_584 == 0) {
LAB_00425634:
          iVar19 = 0;
          piVar33 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"you need to specify a private key\n");
          goto LAB_004245cc;
        }
      }
      piVar38 = (int *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
      iVar19 = iStack_584;
      if (piVar38 != (int *)0x0) {
        iStack_5c8 = iStack_584;
        pcVar36 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                    (req_conf,piVar33 + 0x6a5,"prompt");
        if (pcVar36 == (char *)0x0) {
          bVar2 = false;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        else {
          bVar2 = *pcVar36 == 'n';
          if ((*pcVar36 == 'n') && (bVar2 = pcVar36[1] == 'o', pcVar36[1] == 'o')) {
            bVar2 = pcVar36[2] == '\0';
          }
        }
        iVar20 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                           (req_conf,piVar33 + 0x6a5,"distinguished_name");
        pcVar36 = pcVar39;
        if (iVar20 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"unable to find \'%s\' in config\n","distinguished_name"
                    );
        }
        else {
          iVar21 = (*(code *)PTR_NCONF_get_section_006a6ed4)(req_conf,iVar20);
          if (iVar21 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar20);
          }
          else {
            iVar22 = (*(code *)PTR_NCONF_get_string_006a6ea8)(req_conf,piVar33 + 0x6a5,"attributes")
            ;
            if (iVar22 == 0) {
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              pcStack_5fc = (char *)0x0;
            }
            else {
              pcStack_5fc = (char *)(*(code *)PTR_NCONF_get_section_006a6ed4)(req_conf,iVar22);
              if (pcStack_5fc == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar22);
                goto LAB_00425214;
              }
            }
            iVar23 = (*(code *)PTR_X509_REQ_set_version_006a6ed8)(piVar38,0);
            if (iVar23 != 0) {
              if (bVar2) {
                uVar31 = *(undefined4 *)(*piVar38 + 0x10);
                for (iVar20 = 0; iVar22 = (*(code *)PTR_sk_num_006a6e2c)(iVar21), iVar20 < iVar22;
                    iVar20 = iVar20 + 1) {
                  iVar22 = (*(code *)PTR_sk_value_006a6e24)(iVar21,iVar20);
                  pbVar25 = *(byte **)(iVar22 + 4);
                  bVar30 = *pbVar25;
                  pbVar34 = pbVar25;
                  while (bVar30 != 0) {
                    if ((bVar30 == 0x3a) || ((bVar30 & 0xfd) == 0x2c)) {
                      bVar30 = pbVar34[1];
                      if (bVar30 != 0) {
                        pbVar25 = pbVar34 + 1;
                      }
                      break;
                    }
                    pbVar34 = pbVar34 + 1;
                    bVar30 = *pbVar34;
                  }
                  iVar22 = (*(code *)PTR_X509_NAME_add_entry_by_txt_006a6f6c)
                                     (uVar31,pbVar25,iStack_5f4,*(undefined4 *)(iVar22 + 8),
                                      0xffffffff,0xffffffff,-(uint)(bVar30 == 0x2b));
                  if (iVar22 == 0) goto LAB_00425214;
                }
                iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a6f70)(uVar31);
                if (iVar20 != 0) {
                  if (!bVar5) {
                    for (iVar20 = 0; iVar21 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_5fc),
                        iVar20 < iVar21; iVar20 = iVar20 + 1) {
                      iVar21 = (*(code *)PTR_sk_value_006a6e24)(pcStack_5fc,iVar20);
                      iVar21 = (*(code *)PTR_X509_REQ_add1_attr_by_txt_006a6f74)
                                         (piVar38,*(undefined4 *)(iVar21 + 4),iStack_5f4,
                                          *(undefined4 *)(iVar21 + 8),0xffffffff);
                      if (iVar21 == 0) goto LAB_00425214;
                    }
                  }
                  goto LAB_00425d60;
                }
LAB_00426a90:
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"error, no objects specified in config file\n");
                pcVar36 = pcVar39;
              }
              else if (pcStack_5e0 == (char *)0x0) {
                pcStack_5f8 = *(char **)(*piVar38 + 0x10);
                if (batch == 0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "You are about to be asked to enter information that will be incorporated\n"
                            );
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,"into your certificate request.\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                            );
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "There are quite a few fields but you can leave some blank\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "For some fields there will be a default value,\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar13,
                             "If you enter \'.\', the field will be left blank.\n");
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"-----\n");
                }
                iVar23 = (*(code *)PTR_sk_num_006a6e2c)(iVar21);
                if (iVar23 != 0) {
                  pcStack_5e0 = (char *)0xffffffff;
                  pcStack_5b8 = "";
                  pcStack_59c = "%s [%s]:";
                  pcStack_5dc = "\n";
LAB_00426478:
                  pcStack_5e0 = pcStack_5e0 + 1;
                  iVar23 = (*(code *)PTR_sk_num_006a6e2c)(iVar21);
                  pcStack_594 = pcVar39;
                  if ((int)pcStack_5e0 < iVar23) {
                    iVar23 = (*(code *)PTR_sk_value_006a6e24)(iVar21,pcStack_5e0);
                    pbVar34 = *(byte **)(iVar23 + 4);
                    iVar24 = check_end(pbVar34,&DAT_0063354c);
                    if ((((iVar24 != 0) && (iVar24 = check_end(pbVar34,&DAT_00633554), iVar24 != 0))
                        && (iVar24 = check_end(pbVar34,"_default"), iVar24 != 0)) &&
                       (iVar24 = check_end(pbVar34,"_value"), iVar24 != 0)) {
                      bVar30 = *pbVar34;
                      if (bVar30 == 0) {
LAB_00426588:
                        pcVar36 = (char *)0x0;
                      }
                      else if ((bVar30 == 0x3a) || (pbVar25 = pbVar34, (bVar30 & 0xfd) == 0x2c)) {
                        pbVar25 = pbVar34;
                        bVar1 = pbVar34[1];
                        if (pbVar34[1] != 0) goto LAB_00426574;
                        pcVar36 = (char *)0x0;
                      }
                      else {
                        do {
                          pbVar3 = pbVar25;
                          pbVar25 = pbVar3 + 1;
                          bVar1 = *pbVar25;
                          if (bVar1 == 0) goto LAB_0042657c;
                        } while ((bVar1 != 0x3a) && ((bVar1 & 0xfd) != 0x2c));
                        bVar1 = pbVar3[2];
                        if (bVar1 != 0) {
LAB_00426574:
                          bVar30 = bVar1;
                          pbVar34 = pbVar25 + 1;
                        }
LAB_0042657c:
                        if (bVar30 != 0x2b) goto LAB_00426588;
                        pbVar34 = pbVar34 + 1;
                        pcVar36 = (char *)0xffffffff;
                      }
                      iVar24 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(pbVar34);
                      if (iVar24 != 0) {
                        iVar26 = (*(code *)PTR_BIO_snprintf_006a6f60)
                                           (auStack_550,100,"%s_default",*(undefined4 *)(iVar23 + 4)
                                           );
                        if (iVar26 < 100) {
                          pcVar27 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                      (req_conf,iVar20,auStack_550);
                          if (pcVar27 == (char *)0x0) {
                            pcVar27 = "";
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_550,100,"%s_value",*(undefined4 *)(iVar23 + 4));
                          iVar26 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                             (req_conf,iVar20,auStack_550);
                          if (iVar26 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_550,100,"%s_min",*(undefined4 *)(iVar23 + 4));
                          iVar28 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                             (req_conf,iVar20,auStack_550,&pcStack_570);
                          if (iVar28 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                            pcStack_570 = (char *)0xffffffff;
                          }
                          (*(code *)PTR_BIO_snprintf_006a6f60)
                                    (auStack_550,100,"%s_max",*(undefined4 *)(iVar23 + 4));
                          iVar28 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                             (req_conf,iVar20,auStack_550,auStack_56c);
                          if (iVar28 == 0) {
                            (*(code *)PTR_ERR_clear_error_006a6ee0)();
                            auStack_56c[0] = 0xffffffff;
                          }
                          uVar31 = auStack_56c[0];
                          pcVar16 = pcStack_570;
                          pcStack_5bc = "";
                          pcStack_5c0 = *(char **)(iVar23 + 8);
                          if (batch == 0) goto LAB_00426808;
                          do {
                            (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar13,0xb,0,0);
                            if (iVar26 == 0) {
                              acStack_4ed[1] = '\0';
                              if (batch == 0) {
                                iVar23 = (*(code *)PTR_fgets_006a9ae0)
                                                   (acStack_4ed + 1,0x400,
                                                    *(undefined4 *)PTR_stdin_006a9a14);
                                if (iVar23 != 0) goto LAB_00426794;
                                goto LAB_00426a74;
                              }
                              acStack_4ed[2] = '\0';
                              acStack_4ed[1] = '\n';
LAB_00426a00:
                              if (*pcVar27 == '\0') goto LAB_00426478;
                              (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_4ed + 1,pcVar27,0x400);
                              (*(code *)PTR_BUF_strlcat_006a6f68)(acStack_4ed + 1,"\n",0x400);
                            }
                            else {
                              (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_4ed + 1,iVar26,0x400);
                              (*(code *)PTR_BUF_strlcat_006a6f68)(acStack_4ed + 1,"\n",0x400);
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)PTR_bio_err_006a6e3c,"%s\n",iVar26);
LAB_00426794:
                              if (acStack_4ed[1] == '\0') goto LAB_00426a74;
                              if (acStack_4ed[1] == '\n') goto LAB_00426a00;
                              if ((acStack_4ed[1] == '.') && (acStack_4ed[2] == '\n'))
                              goto LAB_00426478;
                            }
                            iVar23 = (*(code *)PTR_strlen_006a9a24)(acStack_4ed + 1);
                            if (acStack_4ed[iVar23] != '\n') goto LAB_00426aac;
                            acStack_4ed[iVar23] = '\0';
                            iVar23 = req_check_len(iVar23 + -1,pcVar16,uVar31);
                            if (iVar23 != 0) goto LAB_00426a40;
                            if ((batch != 0) || (iVar26 != 0)) goto LAB_00426a74;
LAB_00426808:
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",pcStack_5c0,pcVar27);
                          } while( true );
                        }
                        uVar31 = *(undefined4 *)(iVar23 + 4);
                        goto LAB_00426928;
                      }
                    }
                    goto LAB_00426478;
                  }
                  iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a6f70)(pcStack_5f8);
                  if (iVar20 == 0) goto LAB_00426a90;
                  if ((!bVar5) && (pcStack_5fc != (char *)0x0)) {
                    iVar20 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_5fc);
                    if ((0 < iVar20) && (batch == 0)) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,
                                 "\nPlease enter the following \'extra\' attributes\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"to be sent with your certificate request\n"
                                );
                    }
                    iStack_60c = 0;
                    pcStack_5c0 = "";
                    pcStack_5b8 = "%s [%s]:";
                    pcStack_5f8 = "\n";
LAB_00426bc4:
                    pcStack_5bc = "";
                    iVar20 = (*(code *)PTR_sk_num_006a6e2c)(pcStack_5fc);
                    if (iStack_60c < iVar20) {
                      iVar20 = (*(code *)PTR_sk_value_006a6e24)(pcStack_5fc,iStack_60c);
                      uVar31 = *(undefined4 *)(iVar20 + 4);
                      pcVar36 = (char *)(*(code *)PTR_OBJ_txt2nid_006a6f5c)(uVar31);
                      if (pcVar36 == (char *)0x0) goto LAB_00426c1c;
                      iVar21 = (*(code *)PTR_BIO_snprintf_006a6f60)
                                         (auStack_550,100,"%s_default",uVar31);
                      if (iVar21 < 100) {
                        pcVar27 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                    (req_conf,iVar22,auStack_550);
                        if (pcVar27 == (char *)0x0) {
                          pcVar27 = "";
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_550,100,"%s_value",uVar31);
                        iVar21 = (*(code *)PTR_NCONF_get_string_006a6ea8)
                                           (req_conf,iVar22,auStack_550);
                        if (iVar21 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_550,100,"%s_min",uVar31);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                           (req_conf,iVar22,auStack_550,&pcStack_570);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          pcStack_570 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_550,100,"%s_max",uVar31);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                           (req_conf,iVar22,auStack_550,auStack_56c);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          auStack_56c[0] = 0xffffffff;
                        }
                        uVar31 = auStack_56c[0];
                        pcVar16 = pcStack_570;
                        puVar14 = PTR_bio_err_006a6e3c;
                        pcStack_5e0 = *(char **)(iVar20 + 8);
                        pcStack_5dc = pcStack_570;
                        if (batch == 0) goto LAB_00426ea4;
                        do {
                          (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (iVar21 == 0) {
                            buf_16723[0] = '\0';
                            if (batch == 0) {
                              iVar20 = (*(code *)PTR_fgets_006a9ae0)
                                                 (buf_16723,0x400,*(undefined4 *)PTR_stdin_006a9a14)
                              ;
                              if (iVar20 != 0) goto LAB_00426e34;
                              goto LAB_00426a74;
                            }
                            buf_16723[0] = '\n';
                            buf_16723[1] = '\0';
LAB_00426f74:
                            if (*pcVar27 == '\0') goto LAB_00426c1c;
                            (*(code *)PTR_BUF_strlcpy_006a6f64)(buf_16723,pcVar27,0x400);
                            (*(code *)PTR_BUF_strlcat_006a6f68)(buf_16723,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a6f64)(buf_16723,iVar21,0x400);
                            (*(code *)PTR_BUF_strlcat_006a6f68)(buf_16723,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"%s\n",iVar21)
                            ;
LAB_00426e34:
                            if (buf_16723[0] == '\0') goto LAB_00426a74;
                            if (buf_16723[0] == '\n') goto LAB_00426f74;
                            if ((buf_16723[0] == '.') && (buf_16723[1] == '\n')) goto LAB_00426c1c;
                          }
                          pcStack_5bc = "";
                          iVar20 = (*(code *)PTR_strlen_006a9a24)(buf_16723);
                          if ((&DAT_006a9c0f)[iVar20] != '\n') goto LAB_00426aac;
                          (&DAT_006a9c0f)[iVar20] = '\0';
                          iVar20 = req_check_len(iVar20 + -1,pcVar16,uVar31);
                          if (iVar20 != 0) goto LAB_00426ee4;
                          if ((batch != 0) || (iVar21 != 0)) goto LAB_00426a74;
LAB_00426ea4:
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar13,"%s [%s]:",pcStack_5e0,pcVar27);
                        } while( true );
                      }
                      uVar31 = *(undefined4 *)(iVar20 + 4);
LAB_00426928:
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"Name \'%s\' too long\n",uVar31);
                      goto LAB_00425214;
                    }
                  }
                  goto LAB_00425d60;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"No template, please set one up.\n");
              }
              else {
                iVar20 = build_subject(piVar38,pcStack_5e0,iStack_5f4);
                if (iVar20 != 0) {
LAB_00425d60:
                  iVar19 = (*(code *)PTR_X509_REQ_set_pubkey_006a6f30)(piVar38,iVar19);
                  pcVar36 = pcVar39;
                  if (iVar19 != 0) {
                    if ((bVar4) &&
                       (iVar19 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*piVar38 + 0x18)),
                       iVar19 == 0)) {
                      (*(code *)PTR_sk_free_006a6e80)(*(undefined4 *)(*piVar38 + 0x18));
                      *(undefined4 *)(*piVar38 + 0x18) = 0;
                    }
                    if (bVar5) {
                      pcStack_5e0 = (char *)0x0;
                      goto LAB_004255cc;
                    }
                    (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_56c,0,0,piVar38,0,0);
                    (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_56c,req_conf);
                    if ((pcStack_5e8 == (char *)0x0) ||
                       (iVar19 = (*(code *)PTR_X509V3_EXT_REQ_add_nconf_006a6f34)
                                           (req_conf,auStack_56c,pcStack_5e8,piVar38), iVar19 != 0))
                    {
                      iVar19 = do_X509_REQ_sign(*(undefined4 *)puVar13,piVar38,iStack_584,iStack_5c4
                                                ,puStack_618);
                      if (iVar19 != 0) goto LAB_00425688;
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar13,"Error Loading extension section %s\n",
                                 pcStack_5e8);
                    }
                    goto LAB_00425e60;
                  }
                }
              }
            }
          }
        }
        goto LAB_00425214;
      }
LAB_00425e60:
      iVar19 = 0;
      piVar33 = (int *)0x0;
      goto LAB_004245cc;
    }
    if (pcStack_5bc == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar17,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
    }
    else {
      iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar17,0x6c,3,pcStack_5bc);
      pcVar36 = pcStack_5bc;
      if (iVar19 < 1) {
LAB_0042633c:
        iVar19 = 0;
        (*(code *)PTR_perror_006a9a80)(pcVar36);
        piVar38 = (int *)0x0;
        piVar33 = (int *)0x0;
        goto LAB_004245cc;
      }
    }
    if (piVar38 == (int *)0x1) {
      piVar38 = (int *)(*(code *)PTR_d2i_X509_REQ_bio_006a6f80)(iVar17,0);
    }
    else {
      if (piVar38 != (int *)0x3) {
        iVar19 = 0;
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"bad input format specified for X509 request\n");
        piVar33 = (int *)0x0;
        goto LAB_004245cc;
      }
      piVar38 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a6ee4)(iVar17,0,0,0);
    }
    if (piVar38 == (int *)0x0) {
      iVar19 = 0;
      piVar33 = (int *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"unable to load X509 request\n");
      goto LAB_004245cc;
    }
    if (bVar5) {
      if (iStack_584 == 0) goto LAB_00425634;
LAB_004255cc:
      piVar33 = (int *)(*(code *)PTR_X509_new_006a6ee8)();
      if ((piVar33 != (int *)0x0) &&
         ((pcStack_5ec == (char *)0x0 ||
          (iVar19 = (*(code *)PTR_X509_set_version_006a6eec)(piVar33,2), iVar19 != 0)))) {
        if (iStack_614 == 0) {
          uVar31 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(piVar33);
          iVar19 = (*(code *)PTR_rand_serial_006a6fa0)(0,uVar31);
          if (iVar19 != 0) {
            iVar19 = *piVar38;
            goto LAB_00427178;
          }
        }
        else {
          iVar19 = (*(code *)PTR_X509_set_serialNumber_006a6f84)(piVar33,iStack_614);
          if (iVar19 != 0) {
            iVar19 = *piVar38;
LAB_00427178:
            iVar19 = (*(code *)PTR_X509_set_issuer_name_006a6f88)
                               (piVar33,*(undefined4 *)(iVar19 + 0x10));
            if ((((iVar19 != 0) &&
                 (iVar19 = (*(code *)PTR_X509_gmtime_adj_006a6f8c)
                                     (**(undefined4 **)(*piVar33 + 0x10),0), iVar19 != 0)) &&
                (iVar19 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                    (*(undefined4 *)(*(int *)(*piVar33 + 0x10) + 4),iStack_5a4,0,0),
                iVar19 != 0)) &&
               (((iVar19 = (*(code *)PTR_X509_set_subject_name_006a6f94)
                                     (piVar33,*(undefined4 *)(*piVar38 + 0x10)), iVar19 != 0 &&
                 (iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38), iVar19 != 0)) &&
                (iVar20 = (*(code *)PTR_X509_set_pubkey_006a6f98)(piVar33,iVar19), iVar20 != 0)))) {
              (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar19);
              (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_56c,piVar33,piVar33,0,0,0);
              (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_56c,req_conf);
              if ((pcStack_5ec == (char *)0x0) ||
                 (iVar19 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                     (req_conf,auStack_56c,pcStack_5ec,piVar33), iVar19 != 0)) {
                puVar14 = PTR_bio_err_006a6e3c;
                iVar19 = do_X509_sign(*(undefined4 *)puVar13,piVar33,iStack_584,iStack_5c4,
                                      puStack_618);
                if (iVar19 != 0) {
                  if (pcStack_5e0 == (char *)0x0) goto LAB_004256e4;
                  iVar19 = 0;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar14,"Cannot modifiy certificate subject\n");
                  goto LAB_004245cc;
                }
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar14);
              }
              else {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar13,"Error Loading extension section %s\n",pcStack_5ec
                          );
              }
            }
          }
        }
      }
LAB_00425604:
      iVar19 = 0;
      goto LAB_004245cc;
    }
    if (pcStack_5e0 != (char *)0x0) {
      if (pcStack_5dc == (char *)0x0) {
        iVar19 = build_subject(piVar38,pcStack_5e0,iStack_5f4);
        if (iVar19 == 0) goto LAB_00426fc8;
        *(undefined4 *)(*piVar38 + 8) = 1;
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Modifying Request\'s Subject\n");
        (*(code *)PTR_print_name_006a6f04)
                  (*(undefined4 *)puVar13,"old subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_590
                  );
        iVar19 = build_subject(piVar38,pcStack_5e0,iStack_5f4,pcStack_5b8);
        puVar14 = PTR_print_name_006a6f04;
        if (iVar19 == 0) {
LAB_00426fc8:
          iVar19 = 0;
          piVar33 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"ERROR: cannot modify subject\n");
          goto LAB_004245cc;
        }
        iVar19 = *piVar38;
        uVar31 = *(undefined4 *)PTR_bio_err_006a6e3c;
        *(undefined4 *)(iVar19 + 8) = 1;
        (*(code *)puVar14)(uVar31,"new subject=",*(undefined4 *)(iVar19 + 0x10),uStack_590);
      }
    }
LAB_00425688:
    piVar33 = (int *)0x0;
    if (bVar6) {
      if (iStack_584 == 0) {
        iStack_584 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        if (iStack_584 == 0) goto LAB_00425e60;
        iVar19 = (*(code *)PTR_X509_REQ_verify_006a6ef0)(piVar38,iStack_584);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_584);
        iStack_584 = 0;
      }
      else {
        iVar19 = (*(code *)PTR_X509_REQ_verify_006a6ef0)(piVar38);
      }
      if (iVar19 < 0) goto LAB_00425e60;
      if (iVar19 == 0) {
        piVar33 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
      }
      else {
        piVar33 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"verify OK\n");
      }
    }
LAB_004256e4:
    if ((((!bVar7) || (bVar8)) || (bVar9)) || ((bVar10 || (bVar11)))) {
      if (pcStack_5d8 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
      }
      else {
        if ((pcStack_5d4 == (char *)0x0) ||
           (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcStack_5d8,pcStack_5d4), iVar19 != 0)) {
          uVar31 = 5;
        }
        else {
          uVar31 = 9;
        }
        iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,uVar31,pcStack_5d8);
        if (iVar19 == 0) {
          iVar19 = 0;
          (*(code *)PTR_perror_006a9a80)(pcStack_5d8);
          goto LAB_004245cc;
        }
      }
      if (bVar11) {
        iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        if (iVar19 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Error getting public key\n");
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
          goto LAB_004245cc;
        }
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a6f28)(iVar18,iVar19);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar19);
      }
      if (bVar8) {
        if (bVar5) {
          (*(code *)PTR_X509_print_ex_006a6efc)(iVar18,piVar33,uStack_590,uStack_58c);
          if (bVar10) goto LAB_004257b4;
          if (!bVar9) goto LAB_00425884;
LAB_004257ec:
          iVar19 = (*(code *)PTR_X509_get_pubkey_006a6f08)(piVar33);
        }
        else {
          (*(code *)PTR_X509_REQ_print_ex_006a6ef8)(iVar18,piVar38,uStack_590,uStack_58c);
          if (bVar10) {
LAB_00425a34:
            (*(code *)PTR_print_name_006a6f04)
                      (iVar18,"subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_590);
          }
          if (!bVar9) goto LAB_00425884;
LAB_00425a64:
          iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(piVar38);
        }
        puVar14 = PTR_stdout_006a99c8;
        if (iVar19 == 0) {
          (*(code *)PTR_fwrite_006a9a74)
                    ("Modulus=unavailable\n",1,0x14,*(undefined4 *)PTR_stdout_006a99c8);
          goto LAB_004245cc;
        }
        (*(code *)PTR_fwrite_006a9a74)("Modulus=",1,8,*(undefined4 *)PTR_stdout_006a99c8);
        iVar20 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(iVar19);
        if (iVar20 == 6) {
          (*(code *)PTR_BN_print_006a6f24)(iVar18,*(undefined4 *)(*(int *)(iVar19 + 0x14) + 0x10));
        }
        else {
          (*(code *)PTR_fwrite_006a9a74)("Wrong Algorithm type",1,0x14,*(undefined4 *)puVar14);
        }
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar19);
        (*(code *)PTR_fputc_006a99a4)(10,*(undefined4 *)puVar14);
      }
      else if (bVar10) {
        if (!bVar5) goto LAB_00425a34;
LAB_004257b4:
        uVar31 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar33);
        (*(code *)PTR_print_name_006a6f04)(iVar18,"subject=",uVar31,uStack_590);
        if (bVar9) goto LAB_004257ec;
      }
      else if (bVar9) {
        if (bVar5) goto LAB_004257ec;
        goto LAB_00425a64;
      }
LAB_00425884:
      if (!bVar7) {
        if (bVar5) {
          if (piVar33 != (int *)0x0) {
            if (pcVar39 == (char *)0x1) {
              iVar19 = (*(code *)PTR_i2d_X509_bio_006a6f1c)(iVar18,piVar33);
            }
            else {
              if (pcVar39 != (char *)0x3) goto LAB_0042590c;
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar18,piVar33);
            }
            if (iVar19 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"unable to write X509 certificate\n");
              goto LAB_00425604;
            }
          }
        }
        else {
          if (pcVar39 == (char *)0x1) {
            iVar19 = (*(code *)PTR_i2d_X509_REQ_bio_006a6f10)(iVar18,piVar38);
          }
          else {
            if (pcVar39 != (char *)0x3) {
LAB_0042590c:
              iVar19 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar13,"bad output format specified for outfile\n");
              goto LAB_004245cc;
            }
            if (bVar12) {
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_REQ_NEW_006a6f18)(iVar18,piVar38);
            }
            else {
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_REQ_006a6f14)(iVar18,piVar38);
            }
          }
          if (iVar19 == 0) goto LAB_004258dc;
        }
      }
    }
    iVar19 = 0;
    uVar37 = 0;
  } while( true );
LAB_00426a40:
  iVar23 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a6f78)
                     (pcStack_5f8,iVar24,iStack_5f4,acStack_4ed + 1,0xffffffff,0xffffffff,pcVar36);
  if (iVar23 == 0) goto LAB_00426a74;
  goto LAB_00426478;
LAB_00426aac:
  pcStack_5bc = "";
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"weird input :-(\n");
  goto LAB_00425214;
LAB_00426ee4:
  iVar20 = (*(code *)PTR_X509_REQ_add1_attr_by_NID_006a6f7c)
                     (piVar38,pcVar36,iStack_5f4,buf_16723,0xffffffff);
  if (iVar20 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Error adding attribute\n");
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
    goto LAB_00425214;
  }
LAB_00426c1c:
  iStack_60c = iStack_60c + 1;
  goto LAB_00426bc4;
LAB_00426a74:
  pcStack_5bc = "";
LAB_00425214:
  if ((bVar4) &&
     (iVar19 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*piVar38 + 0x18)), iVar19 == 0)) {
    (*(code *)PTR_sk_free_006a6e80)(*(undefined4 *)(*piVar38 + 0x18));
    *(undefined4 *)(*piVar38 + 0x18) = 0;
  }
  iVar19 = 0;
  piVar33 = (int *)0x0;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"problems making Certificate Request\n")
  ;
  pcVar39 = pcVar36;
  goto LAB_004245cc;
LAB_004258dc:
  iVar19 = 0;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"unable to write X509 request\n");
  goto LAB_004245cc;
}

