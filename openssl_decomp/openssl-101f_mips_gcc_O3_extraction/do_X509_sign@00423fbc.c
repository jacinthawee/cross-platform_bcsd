
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
  undefined4 *puVar28;
  byte bVar29;
  undefined4 uVar30;
  char **ppcVar31;
  int *piVar32;
  byte *pbVar33;
  char **ppcVar34;
  char *pcVar35;
  uint uVar36;
  undefined4 uVar37;
  int *piVar38;
  char *pcVar39;
  code *pcVar40;
  undefined4 uVar41;
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
  undefined4 uStack_5bc;
  int iStack_5ac;
  int iStack_5a8;
  char *pcStack_5a4;
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
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  puStack_74 = auStack_3c;
  local_48 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_74);
  local_40 = 0;
  (**(code **)(local_48 + -0x7fc4))(puStack_74);
  uVar30 = 0;
  puStack_d4 = &local_40;
  local_50 = param_3;
  iVar17 = (**(code **)(local_48 + -0x7fc0))(puStack_74,puStack_d4,param_4,0);
  if (iVar17 == 0) {
LAB_00424140:
    uStack_80 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (**(code **)(local_48 + -0x7fb4))(param_5), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_3 = (**(code **)(local_48 + -0x7fbc))(param_5,iVar17);
      iVar18 = (**(code **)(local_48 + -0x7fb8))(local_40,param_3);
      if (iVar18 < 1) {
        puStack_d4 = (undefined4 *)0x634730;
        param_4 = param_3;
        (**(code **)(local_48 + -0x7fa8))(param_1);
        (**(code **)(local_48 + -0x7fa0))(**(undefined4 **)(local_48 + -0x7fa4));
        goto LAB_00424140;
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
  (**(code **)(local_48 + -0x5328))();
  uStack_e4 = local_50;
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  puStack_dc = auStack_9c;
  uStack_7c = param_5;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_78 = param_3;
  uStack_6c = param_2;
  uStack_68 = param_1;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_dc);
  uStack_a0 = 0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_dc);
  puVar28 = &uStack_a0;
  iVar17 = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(puStack_dc,puVar28,uVar30,0);
  if (iVar17 == 0) {
LAB_004242d8:
    uStack_e8 = 0;
  }
  else {
    for (iVar17 = 0; iVar18 = (*(code *)PTR_sk_num_006a7f2c)(uStack_e4), iVar17 < iVar18;
        iVar17 = iVar17 + 1) {
      param_4 = (*(code *)PTR_sk_value_006a7f24)(uStack_e4,iVar17);
      iVar18 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(uStack_a0,param_4);
      if (iVar18 < 1) {
        puVar28 = (undefined4 *)0x634730;
        (*(code *)PTR_BIO_printf_006a7f38)(iStack_d0,"parameter error \"%s\"\n",param_4);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004242d8;
      }
    }
    puVar28 = puStack_dc;
    iVar17 = (*(code *)PTR_X509_REQ_sign_ctx_006a7f44)(puStack_d4);
    uStack_e8 = (uint)(0 < iVar17);
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(puStack_dc);
  if (iStack_84 == *(int *)puStack_d8) {
    return uStack_e8;
  }
  iVar17 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  puVar13 = PTR_bio_err_006a7f3c;
  iStack_580 = -1;
  iStack_57c = -1;
  req_conf = 0;
  uStack_590 = 0;
  uStack_58c = 0;
  iStack_588 = 0;
  iStack_584 = 0;
  iStack_578 = 0;
  iStack_574 = 0;
  iStack_ec = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_e0 = param_4;
  iStack_5c8 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar13 == 0) {
    uVar30 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar30);
    *(int *)puVar13 = iVar18;
    if (iVar18 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  uVar30 = *puVar28;
  iVar17 = iVar17 + -1;
  ppcVar31 = (char **)(puVar28 + 1);
  iStack_5f4 = 0x1001;
  if (iVar17 < 1) {
    uStack_5bc = 0;
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
    pcStack_5dc = (char *)0x0;
    pcStack_5fc = (char *)0x0;
    pcStack_608 = (char *)0x0;
    pcStack_5d4 = (char *)0x0;
    pcStack_5c0 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_59c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_5d8 = (char *)0x0;
    pcStack_5f8 = (char *)0x0;
    puStack_618 = (undefined4 *)0x0;
    puStack_624 = (undefined4 *)0x0;
    pcStack_5a4 = (char *)0x0;
    iStack_5a8 = 0x1e;
    bVar5 = false;
    iStack_630 = 0;
    iStack_5c4 = 0;
    iStack_5ac = 0;
  }
  else {
    iStack_5c4 = 0;
    iStack_5ac = 0;
    uStack_5bc = 0;
    uStack_5a0 = 3;
    pcStack_5e0 = (char *)0x0;
    pcVar39 = (char *)0x3;
    pcStack_61c = (char *)0x0;
    piVar38 = (int *)0x3;
    iStack_5a8 = 0x1e;
    pcStack_620 = (char *)0x0;
    pcStack_594 = (char *)0x0;
    bVar9 = false;
    iStack_614 = 0;
    pcStack_5e8 = (char *)0x0;
    pcStack_5ec = (char *)0x0;
    pcStack_638 = (char *)0x0;
    pcStack_5dc = (char *)0x0;
    pcStack_5fc = (char *)0x0;
    pcStack_608 = (char *)0x0;
    pcStack_5d4 = (char *)0x0;
    pcStack_5c0 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar12 = false;
    bVar4 = false;
    pcStack_59c = (char *)0x0;
    bVar8 = false;
    bVar7 = false;
    bVar6 = false;
    pcStack_5d8 = (char *)0x0;
    pcStack_5f8 = (char *)0x0;
    puStack_618 = (undefined4 *)0x0;
    puStack_624 = (undefined4 *)0x0;
    pcStack_5a4 = (char *)0x0;
    bVar5 = false;
    iStack_630 = 0;
LAB_004244b8:
    do {
      pcVar35 = *ppcVar31;
      iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-inform");
      iVar18 = iStack_5c4;
      if (iVar19 == 0) {
        iVar17 = iVar17 + -1;
        if (iVar17 != 0) {
          piVar38 = (int *)(*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
          ppcVar34 = ppcVar31 + 1;
          goto LAB_004244ac;
        }
LAB_0042486c:
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"%s [options] <infile >outfile\n",uVar30);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"where options  are\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -inform arg    input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -outform arg   output format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -in arg        input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -out arg       output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -text          text form of request\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -pubkey        output public key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -noout         do not output REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -verify        verify signature on REQ\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -modulus       RSA modulus\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nodes         don\'t encrypt the output key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -engine e      use engine e, possibly a hardware device\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subject       output the request\'s subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -passin        private key password source\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -key file      use the private key contained in file\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyform arg   key file format\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -keyout arg    file to send the key to\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   "                load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                the random number generator\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -config file   request template file.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -subj arg      set or modify request subject\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -multivalue-rdn enable support for multivalued RDNs\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13," -new           new request.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -batch         do not ask anything during request generation\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -x509          output a x509 structure instead of a cert. req.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -newhdr        output \"NEW\" in the header lines\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"                have been reported as requiring\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,
                   " -utf8          input characters are UTF8 (default ASCII)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -nameopt arg    - various certificate name options\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13," -reqopt arg    - various request text options\n\n");
        goto LAB_00424810;
      }
      iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-outform");
      if (iVar19 != 0) {
        iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-engine");
        if (iVar19 == 0) {
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) goto LAB_0042486c;
          pcStack_638 = ppcVar31[1];
          ppcVar34 = ppcVar31 + 1;
        }
        else {
          iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keygen_engine");
          if (iVar19 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_0042486c;
            iStack_630 = (*(code *)PTR_ENGINE_by_id_006a7f9c)(ppcVar31[1]);
            ppcVar34 = ppcVar31 + 1;
            if (iStack_630 == 0) {
              pcVar35 = ppcVar31[1];
              uVar30 = *(undefined4 *)puVar13;
              pcVar27 = "Can\'t find keygen engine %s\n";
              goto LAB_00424804;
            }
          }
          else {
            iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330b4);
            if (iVar19 == 0) {
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_0042486c;
              pcStack_608 = ppcVar31[1];
              ppcVar34 = ppcVar31 + 1;
            }
            else {
              iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pubkey");
              ppcVar34 = ppcVar31;
              if (iVar19 == 0) {
                bVar11 = true;
              }
              else {
                iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_006330c4);
                if (iVar19 == 0) {
                  pcStack_5f8 = (char *)0x1;
                }
                else {
                  iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-config");
                  if (iVar19 == 0) {
                    iVar17 = iVar17 + -1;
                    if (iVar17 == 0) goto LAB_0042486c;
                    pcStack_5fc = ppcVar31[1];
                    ppcVar34 = ppcVar31 + 1;
                  }
                  else {
                    iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyform");
                    if (iVar19 == 0) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042486c;
                      uStack_5a0 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar31[1]);
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else if ((((*pcVar35 == '-') && (pcVar35[1] == 'i')) && (pcVar35[2] == 'n')) &&
                            (pcVar35[3] == '\0')) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_0042486c;
                      pcStack_5c0 = ppcVar31[1];
                      ppcVar34 = ppcVar31 + 1;
                    }
                    else {
                      iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,&DAT_00632edc);
                      if (iVar19 == 0) {
                        iVar17 = iVar17 + -1;
                        if (iVar17 == 0) goto LAB_0042486c;
                        pcStack_5d4 = ppcVar31[1];
                        ppcVar34 = ppcVar31 + 1;
                      }
                      else {
                        iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-keyout");
                        if (iVar19 == 0) {
                          iVar17 = iVar17 + -1;
                          if (iVar17 == 0) goto LAB_0042486c;
                          pcStack_5dc = ppcVar31[1];
                          ppcVar34 = ppcVar31 + 1;
                        }
                        else {
                          iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passin");
                          if (iVar19 == 0) {
                            iVar17 = iVar17 + -1;
                            if (iVar17 == 0) goto LAB_0042486c;
                            pcStack_620 = ppcVar31[1];
                            ppcVar34 = ppcVar31 + 1;
                          }
                          else {
                            iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-passout");
                            if (iVar19 == 0) {
                              iVar17 = iVar17 + -1;
                              if (iVar17 == 0) goto LAB_0042486c;
                              pcStack_61c = ppcVar31[1];
                              ppcVar34 = ppcVar31 + 1;
                            }
                            else {
                              iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-rand");
                              if (iVar19 == 0) {
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042486c;
                                pcStack_594 = ppcVar31[1];
                                ppcVar34 = ppcVar31 + 1;
                              }
                              else {
                                iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newkey");
                                if (iVar19 != 0) {
                                  iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-pkeyopt");
                                  if (iVar19 == 0) {
                                    if (iVar17 != 1) {
                                      puVar28 = puStack_624;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (puStack_624 == (undefined4 *)0x0) {
                                        puVar28 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        puStack_624 = puVar28;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
joined_r0x00427474:
                                        PTR_sk_push_006a80a8 = pcVar40;
                                        if (puVar28 == (undefined4 *)0x0) goto LAB_0042486c;
                                      }
LAB_004273f0:
                                      iVar19 = (*pcVar40)(puVar28,ppcVar31[1]);
joined_r0x004277bc:
                                      iVar17 = iVar17 + -1;
                                      ppcVar34 = ppcVar31 + 1;
                                      if (iVar19 != 0) goto LAB_004244ac;
                                    }
                                  }
                                  else {
                                    iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-sigopt");
                                    if (iVar19 != 0) {
                                      iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-batch");
                                      if (iVar19 == 0) {
                                        batch = 1;
                                      }
                                      else {
                                        iVar19 = (*(code *)PTR_strcmp_006aac20)(pcVar35,"-newhdr");
                                        if (iVar19 == 0) {
                                          bVar12 = true;
                                        }
                                        else {
                                          iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                             (pcVar35,"-modulus");
                                          if (iVar19 == 0) {
                                            bVar9 = true;
                                          }
                                          else {
                                            iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                               (pcVar35,"-verify");
                                            if (iVar19 == 0) {
                                              bVar6 = true;
                                            }
                                            else {
                                              iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                 (pcVar35,"-nodes");
                                              if (iVar19 == 0) {
                                                pcStack_59c = (char *)0x1;
                                              }
                                              else {
                                                iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                   (pcVar35,"-noout");
                                                if (iVar19 == 0) {
                                                  bVar7 = true;
                                                }
                                                else {
                                                  iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-verbose");
                                                  if (iVar19 == 0) {
                                                    pcStack_5d8 = (char *)0x1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-utf8");
                                                    if (iVar19 != 0) {
                                                      iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-nameopt");
                                                      if (iVar19 == 0) {
                                                        if (iVar17 != 1) {
                                                          puVar28 = &uStack_590;
                                                          pcVar40 = (code *)PTR_set_name_ex_006a80ac
                                                          ;
                                                          goto LAB_004273f0;
                                                        }
                                                      }
                                                      else {
                                                        iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,"-reqopt");
                                                        if (iVar19 != 0) {
                                                          iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar35,"-subject");
                                                          if (iVar19 == 0) {
                                                            bVar10 = true;
                                                          }
                                                          else {
                                                            iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                               (pcVar35,"-text");
                                                            if (iVar19 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar19 = (*(code *)PTR_strcmp_006aac20
                                                                       )(pcVar35,"-x509");
                                                              if (iVar19 == 0) {
                                                                bVar5 = true;
                                                              }
                                                              else {
                                                                iVar19 = (*(code *)
                                                  PTR_strcmp_006aac20)(pcVar35,"-asn1-kludge");
                                                  if (iVar19 == 0) {
                                                    bVar4 = true;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-no-asn1-kludge");
                                                    if (iVar19 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-subj");
                                                      if (iVar19 == 0) {
                                                        iVar17 = iVar17 + -1;
                                                        if (iVar17 == 0) goto LAB_0042486c;
                                                        pcStack_5e0 = ppcVar31[1];
                                                        ppcVar34 = ppcVar31 + 1;
                                                      }
                                                      else {
                                                        iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar35,
                                                  "-multivalue-rdn");
                                                  if (iVar19 == 0) {
                                                    uStack_5bc = 1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-days");
                                                    if (iVar19 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042486c;
                                                      ppcVar34 = ppcVar31 + 1;
                                                      iVar19 = (*(code *)PTR_strtol_006aaa68)
                                                                         (ppcVar31[1],0,10);
                                                      iStack_5a8 = 0x1e;
                                                      if (iVar19 != 0) {
                                                        iStack_5a8 = iVar19;
                                                      }
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar35,"-set_serial");
                                                      if (iVar19 == 0) {
                                                        if (iVar17 == 1) goto LAB_0042486c;
                                                        iStack_614 = (*(code *)
                                                  PTR_s2i_ASN1_INTEGER_006a80b4)(0,ppcVar31[1]);
                                                  iVar19 = iStack_614;
                                                  goto joined_r0x004277bc;
                                                  }
                                                  iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar35,"-extensions");
                                                  if (iVar19 == 0) {
                                                    iVar17 = iVar17 + -1;
                                                    if (iVar17 == 0) goto LAB_0042486c;
                                                    pcStack_5ec = ppcVar31[1];
                                                    ppcVar34 = ppcVar31 + 1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar35,"-reqexts");
                                                    if (iVar19 == 0) {
                                                      iVar17 = iVar17 + -1;
                                                      if (iVar17 == 0) goto LAB_0042486c;
                                                      pcStack_5e8 = ppcVar31[1];
                                                      ppcVar34 = ppcVar31 + 1;
                                                    }
                                                    else {
                                                      iStack_5ac = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)(pcVar35 + 1);
                                                  iVar18 = iStack_5ac;
                                                  if (iStack_5ac == 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar13,
                                                               "unknown option %s\n",*ppcVar31);
                                                    goto LAB_0042486c;
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
                                                  goto LAB_004244ac;
                                                  }
                                                  if (iVar17 != 1) {
                                                    puVar28 = &uStack_58c;
                                                    pcVar40 = (code *)PTR_set_cert_ex_006a80b0;
                                                    goto LAB_004273f0;
                                                  }
                                                  }
                                                  goto LAB_0042486c;
                                                  }
                                                  iStack_5f4 = 0x1000;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_004244ac;
                                    }
                                    if (iVar17 != 1) {
                                      puVar28 = puStack_618;
                                      pcVar40 = (code *)PTR_sk_push_006a80a8;
                                      if (puStack_618 == (undefined4 *)0x0) {
                                        puVar28 = (undefined4 *)
                                                  (*(code *)PTR_sk_new_null_006a80a4)();
                                        puStack_618 = puVar28;
                                        pcVar40 = (code *)PTR_sk_push_006a80a8;
                                        goto joined_r0x00427474;
                                      }
                                      goto LAB_004273f0;
                                    }
                                  }
                                  goto LAB_0042486c;
                                }
                                iVar17 = iVar17 + -1;
                                if (iVar17 == 0) goto LAB_0042486c;
                                pcStack_5a4 = ppcVar31[1];
                                pcStack_5f8 = (char *)0x1;
                                ppcVar34 = ppcVar31 + 1;
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
LAB_004244ac:
        iStack_5c4 = iVar18;
        iVar17 = iVar17 + -1;
        ppcVar31 = ppcVar34 + 1;
        if (iVar17 == 0) break;
        goto LAB_004244b8;
      }
      if (iVar17 == 1) goto LAB_0042486c;
      ppcVar34 = ppcVar31 + 1;
      iVar17 = iVar17 + -2;
      ppcVar31 = ppcVar31 + 2;
      pcVar39 = (char *)(*(code *)PTR_str2fmt_006a7f4c)(*ppcVar34);
    } while (iVar17 != 0);
  }
  puVar14 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar17 = (*(code *)PTR_app_passwd_006a7f54)
                     (*(undefined4 *)puVar13,pcStack_620,pcStack_61c,&iStack_578,&iStack_574);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"Error getting passwords\n");
  }
  else {
    if (pcStack_5fc == (char *)0x0) {
      req_conf = *(int *)PTR_config_006a7f68;
      if (req_conf == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar14,"Unable to load config info from %s\n",
                   *(undefined4 *)PTR_default_config_file_006a7fdc);
        if (pcStack_5f8 != (char *)0x0) {
          iVar18 = 0;
          iVar17 = 0;
          goto LAB_004245d0;
        }
LAB_004245a4:
        if (req_conf != 0) goto LAB_004245b8;
LAB_00424e24:
        iVar17 = (*(code *)PTR_add_oid_section_006a7f60)(*(undefined4 *)puVar13,req_conf);
        if (iVar17 != 0) {
          if (iStack_5ac == 0) {
            iVar17 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"default_md");
            if (iVar17 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(iVar17);
              if (iVar17 != 0) {
                iStack_5c4 = iVar17;
              }
            }
          }
          if ((pcStack_5ec == (char *)0x0) &&
             (pcStack_5ec = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                              (req_conf,&DAT_00632464,"x509_extensions"),
             pcStack_5ec == (char *)0x0)) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_00424eb4:
            piVar32 = (int *)0x630000;
            if ((iStack_578 == 0) &&
               (iStack_578 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                       (req_conf,&DAT_00632464,"input_password"), iStack_578 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            if ((iStack_574 == 0) &&
               (iStack_574 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                       (req_conf,&DAT_00632464,"output_password"), iStack_574 == 0))
            {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                        (req_conf,&DAT_00632464,"string_mask");
            if (pcVar35 == (char *)0x0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a7fc0)(pcVar35);
              if (iVar17 == 0) {
                uVar30 = *(undefined4 *)puVar13;
                pcVar27 = "Invalid global string mask setting %s\n";
                goto LAB_00424804;
              }
            }
            if (iStack_5f4 == 0x1000) {
LAB_00424f6c:
              iStack_5f4 = 0x1000;
            }
            else {
              pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (req_conf,&DAT_00632464,&DAT_00633b60);
              if (pcVar35 == (char *)0x0) {
                (*(code *)PTR_ERR_clear_error_006a7fe0)();
              }
              else if ((((*pcVar35 == 'y') && (pcVar35[1] == 'e')) && (pcVar35[2] == 's')) &&
                      (pcVar35[3] == '\0')) goto LAB_00424f6c;
            }
            if ((pcStack_5e8 == (char *)0x0) &&
               (pcStack_5e8 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                (req_conf,&DAT_00632464,"req_extensions"),
               pcStack_5e8 == (char *)0x0)) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
            }
            else {
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_56c,0,0,0,0,1);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_56c,req_conf);
              iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                 (req_conf,auStack_56c,pcStack_5e8,0);
              if (iVar17 == 0) {
                uVar30 = *(undefined4 *)puVar13;
                pcVar27 = "Error Loading request extension section %s\n";
                pcVar35 = pcStack_5e8;
                goto LAB_00424804;
              }
            }
            uVar30 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar30);
            uVar30 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar30);
            if ((iVar17 != 0) && (iVar18 != 0)) {
              uVar30 = (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar13,pcStack_638,0);
              if (pcStack_608 == (char *)0x0) goto LAB_004250cc;
              iStack_584 = (*(code *)PTR_load_key_006a7fc8)
                                     (*(undefined4 *)PTR_bio_err_006a7f3c,pcStack_608,uStack_5a0,0,
                                      iStack_578,uVar30,"Private Key");
              if (iStack_584 != 0) {
                iVar19 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,&DAT_00632464,"RANDFILE")
                ;
                if (iVar19 == 0) goto LAB_00425c50;
                goto LAB_004250b4;
              }
            }
            goto LAB_004245d0;
          }
          (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_56c,0,0,0,0,1);
          (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_56c,req_conf);
          iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(req_conf,auStack_56c,pcStack_5ec,0);
          if (iVar17 != 0) goto LAB_00424eb4;
          uVar30 = *(undefined4 *)puVar13;
          pcVar27 = "Error Loading extension section %s\n";
          pcVar35 = pcStack_5ec;
LAB_00424804:
          (*(code *)PTR_BIO_printf_006a7f38)(uVar30,pcVar27,pcVar35);
          goto LAB_00424810;
        }
      }
      else {
        if (pcStack_5d8 != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"Using configuration from %s\n",
                     *(undefined4 *)PTR_default_config_file_006a7fdc);
          goto LAB_004245a4;
        }
LAB_004245b8:
        iVar17 = (*(code *)PTR_load_config_006a7f64)(*(undefined4 *)puVar13);
        if (iVar17 != 0) {
          iVar17 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,0,"oid_file");
          if (iVar17 == 0) {
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
          }
          else {
            iVar17 = (*(code *)PTR_BIO_new_file_006a7fac)(iVar17,"r");
            if (iVar17 != 0) {
              (*(code *)PTR_OBJ_create_objects_006a7fb0)(iVar17);
              (*(code *)PTR_BIO_free_006a7f70)(iVar17);
            }
          }
          goto LAB_00424e24;
        }
      }
      iVar18 = 0;
      iVar17 = 0;
      goto LAB_004245d0;
    }
    auStack_56c[0] = 0xffffffff;
    if (pcStack_5d8 != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar14,"Using configuration from %s\n",pcStack_5fc);
    }
    req_conf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar17 = (*(code *)PTR_NCONF_load_006a7f5c)(req_conf,pcStack_5fc,auStack_56c);
    if (iVar17 != 0) goto LAB_004245a4;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar13,"error on line %ld of %s\n",auStack_56c[0],pcStack_5fc);
  }
LAB_00424810:
  iVar18 = 0;
  iVar17 = 0;
LAB_004245d0:
  iVar19 = 0;
LAB_004245d8:
  piVar38 = (int *)0x0;
  piVar32 = (int *)0x0;
LAB_004245dc:
  uVar36 = 1;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
  do {
    if ((req_conf != 0) && (req_conf != *(int *)PTR_config_006a7f68)) {
      (*(code *)PTR_NCONF_free_006a7f6c)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(iVar17);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar18);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iStack_584);
    if (iVar19 != 0) {
      (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar19);
    }
    if (puStack_624 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(puStack_624);
    }
    if (puStack_618 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(puStack_618);
    }
    if (iStack_630 != 0) {
      (*(code *)PTR_ENGINE_free_006a7f84)(iStack_630);
    }
    if (iStack_588 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_X509_REQ_free_006a7f8c)(piVar38);
    (*(code *)PTR_X509_free_006a7f90)(piVar32);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iStack_614);
    if ((pcStack_620 != (char *)0x0) && (iStack_578 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if ((pcStack_61c != (char *)0x0) && (iStack_574 != 0)) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_OBJ_cleanup_006a7f98)();
    if (iStack_ec == *(int *)puVar15) {
      return uVar36;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00425c50:
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_004250b4:
    (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar19,*(undefined4 *)puVar13,0);
LAB_004250cc:
    if (pcStack_5f8 != (char *)0x0) {
      if (iStack_584 == 0) {
        iVar20 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"RANDFILE");
        if (iVar20 == 0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        (*(code *)PTR_app_RAND_load_file_006a7fcc)(iVar20,*(undefined4 *)puVar13,0);
        if (pcStack_594 != (char *)0x0) {
          (*(code *)PTR_app_RAND_load_files_006a8038)(pcStack_594);
        }
        if (pcStack_5a4 == (char *)0x0) {
          iVar19 = 0;
        }
        else {
          iVar19 = set_keygen_ctx(*(undefined4 *)puVar13,pcStack_5a4,&iStack_580,&iStack_57c,
                                  &iStack_588,iStack_630);
          if (iVar19 == 0) goto LAB_004245d8;
        }
        if ((iStack_57c < 1) &&
           (iVar21 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                               (req_conf,piVar32 + 0x919,"default_bits",&iStack_57c), iVar21 == 0))
        {
          iStack_57c = 0x200;
        }
        else if ((iStack_57c < 0x180) && ((iStack_580 == 6 || (iStack_580 == 0x74)))) {
          piVar38 = (int *)0x0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"private key length is too short,\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"it needs to be at least %d bits, not %ld\n",0x180,
                     iStack_57c);
          goto LAB_004245dc;
        }
        if ((iVar19 == 0) &&
           (iVar19 = set_keygen_ctx(*(undefined4 *)puVar13,0,&iStack_580,&iStack_57c,&iStack_588,
                                    iStack_630), iVar19 == 0)) goto LAB_004245d8;
        iVar21 = 0;
        if (puStack_624 != (undefined4 *)0x0) {
          for (; iVar22 = (*(code *)PTR_sk_num_006a7f2c)(puStack_624), iVar21 < iVar22;
              iVar21 = iVar21 + 1) {
            uVar30 = (*(code *)PTR_sk_value_006a7f24)(puStack_624,iVar21);
            iVar22 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(iVar19,uVar30);
            if (iVar22 < 1) {
              piVar38 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"parameter error \"%s\"\n",uVar30);
              piVar32 = (int *)0x0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
              goto LAB_004245dc;
            }
          }
        }
        puVar14 = PTR_bio_err_006a7f3c;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"Generating a %ld bit %s private key\n",iStack_57c,
                   iStack_588);
        (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a8040)(iVar19,genpkey_cb);
        (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a8044)(iVar19,*(undefined4 *)puVar13);
        iVar21 = (*(code *)PTR_EVP_PKEY_keygen_006a8048)(iVar19,&iStack_584);
        if (iVar21 < 1) {
          piVar32 = (int *)0x0;
          piVar38 = (int *)0x0;
          (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar14,"Error Generating Key\n");
          goto LAB_004245dc;
        }
        (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar19);
        (*(code *)PTR_app_RAND_write_file_006a804c)(iVar20,*(undefined4 *)puVar14);
        if ((pcStack_5dc == (char *)0x0) &&
           (pcStack_5dc = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                            (req_conf,piVar32 + 0x919,"default_keyfile"),
           pcStack_5dc == (char *)0x0)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar14,"writing new private key to stdout\n");
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"writing new private key to \'%s\'\n",pcStack_5dc);
          iVar19 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,5,pcStack_5dc);
          pcVar35 = pcStack_5dc;
          if (iVar19 < 1) goto LAB_00426268;
        }
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"encrypt_rsa_key");
        if (pcVar35 == (char *)0x0) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                      (req_conf,piVar32 + 0x919,"encrypt_key");
          if (pcVar35 != (char *)0x0) goto LAB_00426170;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
LAB_00426170:
          if (((*pcVar35 == 'n') && (pcVar35[1] == 'o')) && (pcVar35[2] == '\0')) {
            iStack_5c8 = 0;
          }
        }
        iVar19 = 4;
        if (pcStack_59c != (char *)0x0) {
          iStack_5c8 = 0;
        }
        while (iVar20 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a8050)
                                  (iVar18,iStack_584,iStack_5c8,0,0,0,iStack_574), iVar20 == 0) {
          uVar36 = (*(code *)PTR_ERR_peek_error_006a8054)();
          if (((uVar36 & 0xfff) != 0x6d) || (iVar19 = iVar19 + -1, iVar19 == 0)) goto LAB_004245d0;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
        if (iStack_584 == 0) {
LAB_00425644:
          iVar19 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"you need to specify a private key\n");
          goto LAB_004245dc;
        }
      }
      piVar38 = (int *)(*(code *)PTR_X509_REQ_new_006a7fd0)();
      iVar19 = iStack_584;
      if (piVar38 != (int *)0x0) {
        iStack_5c8 = iStack_584;
        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                    (req_conf,piVar32 + 0x919,"prompt");
        if (pcVar35 == (char *)0x0) {
          bVar2 = false;
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        else {
          bVar2 = *pcVar35 == 'n';
          if ((*pcVar35 == 'n') && (bVar2 = pcVar35[1] == 'o', pcVar35[1] == 'o')) {
            bVar2 = pcVar35[2] == '\0';
          }
        }
        iVar20 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                           (req_conf,piVar32 + 0x919,"distinguished_name");
        pcVar35 = pcVar39;
        if (iVar20 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"unable to find \'%s\' in config\n","distinguished_name"
                    );
        }
        else {
          iVar21 = (*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar20);
          if (iVar21 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar20);
          }
          else {
            iVar22 = (*(code *)PTR_NCONF_get_string_006a7fa8)(req_conf,piVar32 + 0x919,"attributes")
            ;
            if (iVar22 == 0) {
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              pcStack_5fc = (char *)0x0;
            }
            else {
              pcStack_5fc = (char *)(*(code *)PTR_NCONF_get_section_006a7fd4)(req_conf,iVar22);
              if (pcStack_5fc == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"unable to get \'%s\' section\n",iVar22);
                goto LAB_00425224;
              }
            }
            iVar23 = (*(code *)PTR_X509_REQ_set_version_006a7fd8)(piVar38,0);
            if (iVar23 != 0) {
              if (bVar2) {
                uVar30 = *(undefined4 *)(*piVar38 + 0x10);
                for (iVar20 = 0; iVar22 = (*(code *)PTR_sk_num_006a7f2c)(iVar21), iVar20 < iVar22;
                    iVar20 = iVar20 + 1) {
                  iVar22 = (*(code *)PTR_sk_value_006a7f24)(iVar21,iVar20);
                  pbVar25 = *(byte **)(iVar22 + 4);
                  bVar29 = *pbVar25;
                  pbVar33 = pbVar25;
                  while (bVar29 != 0) {
                    if ((bVar29 == 0x3a) || ((bVar29 & 0xfd) == 0x2c)) {
                      bVar29 = pbVar33[1];
                      if (bVar29 != 0) {
                        pbVar25 = pbVar33 + 1;
                      }
                      break;
                    }
                    pbVar33 = pbVar33 + 1;
                    bVar29 = *pbVar33;
                  }
                  iVar22 = (*(code *)PTR_X509_NAME_add_entry_by_txt_006a8070)
                                     (uVar30,pbVar25,iStack_5f4,*(undefined4 *)(iVar22 + 8),
                                      0xffffffff,0xffffffff,-(uint)(bVar29 == 0x2b));
                  if (iVar22 == 0) goto LAB_00425224;
                }
                iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(uVar30);
                if (iVar20 != 0) {
                  if (!bVar5) {
                    for (iVar20 = 0; iVar21 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_5fc),
                        iVar20 < iVar21; iVar20 = iVar20 + 1) {
                      iVar21 = (*(code *)PTR_sk_value_006a7f24)(pcStack_5fc,iVar20);
                      iVar21 = (*(code *)PTR_X509_REQ_add1_attr_by_txt_006a8078)
                                         (piVar38,*(undefined4 *)(iVar21 + 4),iStack_5f4,
                                          *(undefined4 *)(iVar21 + 8),0xffffffff);
                      if (iVar21 == 0) goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
LAB_00426a70:
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"error, no objects specified in config file\n");
                pcVar35 = pcVar39;
              }
              else if (pcStack_5e0 == (char *)0x0) {
                pcStack_5f8 = *(char **)(*piVar38 + 0x10);
                if (batch == 0) {
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "You are about to be asked to enter information that will be incorporated\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,"into your certificate request.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                            );
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "There are quite a few fields but you can leave some blank\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "For some fields there will be a default value,\n");
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar13,
                             "If you enter \'.\', the field will be left blank.\n");
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"-----\n");
                }
                iVar23 = (*(code *)PTR_sk_num_006a7f2c)(iVar21);
                if (iVar23 != 0) {
                  pcStack_5e0 = (char *)0xffffffff;
                  pcStack_5a4 = "_max";
                  pcStack_59c = "%s [%s]:";
                  pcStack_5d8 = "\n";
LAB_00426470:
                  pcStack_5e0 = pcStack_5e0 + 1;
                  iVar23 = (*(code *)PTR_sk_num_006a7f2c)(iVar21);
                  pcStack_594 = pcVar39;
                  if ((int)pcStack_5e0 < iVar23) {
                    iVar23 = (*(code *)PTR_sk_value_006a7f24)(iVar21,pcStack_5e0);
                    pbVar33 = *(byte **)(iVar23 + 4);
                    iVar24 = check_end(pbVar33,&DAT_00633f14);
                    if ((((iVar24 != 0) && (iVar24 = check_end(pbVar33,&DAT_00633f1c), iVar24 != 0))
                        && (iVar24 = check_end(pbVar33,"_default"), iVar24 != 0)) &&
                       (iVar24 = check_end(pbVar33,"_value"), iVar24 != 0)) {
                      bVar29 = *pbVar33;
                      if (bVar29 == 0) {
LAB_00426580:
                        uVar30 = 0;
                      }
                      else if ((bVar29 == 0x3a) || (pbVar25 = pbVar33, (bVar29 & 0xfd) == 0x2c)) {
                        pbVar25 = pbVar33;
                        bVar1 = pbVar33[1];
                        if (pbVar33[1] != 0) goto LAB_0042656c;
                        uVar30 = 0;
                      }
                      else {
                        do {
                          pbVar3 = pbVar25;
                          pbVar25 = pbVar3 + 1;
                          bVar1 = *pbVar25;
                          if (bVar1 == 0) goto LAB_00426574;
                        } while ((bVar1 != 0x3a) && ((bVar1 & 0xfd) != 0x2c));
                        bVar1 = pbVar3[2];
                        if (bVar1 != 0) {
LAB_0042656c:
                          bVar29 = bVar1;
                          pbVar33 = pbVar25 + 1;
                        }
LAB_00426574:
                        if (bVar29 != 0x2b) goto LAB_00426580;
                        pbVar33 = pbVar33 + 1;
                        uVar30 = 0xffffffff;
                      }
                      iVar24 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pbVar33);
                      if (iVar24 != 0) {
                        iVar26 = (*(code *)PTR_BIO_snprintf_006a8060)
                                           (auStack_550,100,"%s_default",*(undefined4 *)(iVar23 + 4)
                                           );
                        if (99 < iVar26) {
                          uVar30 = *(undefined4 *)(iVar23 + 4);
                          goto LAB_00426944;
                        }
                        pcVar27 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar20,auStack_550);
                        if (pcVar27 == (char *)0x0) {
                          pcVar27 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_550,100,"%s_value",*(undefined4 *)(iVar23 + 4));
                        pcVar35 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar20,auStack_550);
                        if (pcVar35 == (char *)0x0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_550,100,"%s_min",*(undefined4 *)(iVar23 + 4));
                        iVar26 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar20,auStack_550,&pcStack_570);
                        if (iVar26 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          pcStack_570 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)
                                  (auStack_550,100,"%s_max",*(undefined4 *)(iVar23 + 4));
                        iVar26 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar20,auStack_550,auStack_56c);
                        if (iVar26 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          auStack_56c[0] = 0xffffffff;
                        }
                        uVar41 = auStack_56c[0];
                        pcVar16 = pcStack_570;
                        uVar37 = *(undefined4 *)(iVar23 + 8);
                        uStack_5bc = 0x630000;
                        pcStack_5c0 = pcStack_570;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar37,pcVar27);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (pcVar35 == (char *)0x0) {
                            acStack_4ed[1] = '\0';
                            if (batch == 0) {
                              iVar23 = (*(code *)PTR_fgets_006aabe8)
                                                 (acStack_4ed + 1,0x400,
                                                  *(undefined4 *)PTR_stdin_006aab20);
                              if (iVar23 != 0) goto LAB_004267ac;
                              goto LAB_00425224;
                            }
                            acStack_4ed[2] = '\0';
                            acStack_4ed[1] = '\n';
LAB_00426a1c:
                            if (*pcVar27 == '\0') goto LAB_00426470;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_4ed + 1,pcVar27,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_4ed + 1,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_4ed + 1,pcVar35,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(acStack_4ed + 1,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)PTR_bio_err_006a7f3c,"%s\n",pcVar35);
LAB_004267ac:
                            if (acStack_4ed[1] == '\0') goto LAB_00425224;
                            if (acStack_4ed[1] == '\n') goto LAB_00426a1c;
                            if ((acStack_4ed[1] == '.') && (acStack_4ed[2] == '\n'))
                            goto LAB_00426470;
                          }
                          iVar23 = (*(code *)PTR_strlen_006aab30)(acStack_4ed + 1);
                          if (acStack_4ed[iVar23] != '\n') goto LAB_00426a94;
                          acStack_4ed[iVar23] = '\0';
                          iVar23 = req_check_len(iVar23 + -1,pcVar16,uVar41);
                        } while (iVar23 == 0);
                        iVar23 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a806c)
                                           (pcStack_5f8,iVar24,iStack_5f4,acStack_4ed + 1,0xffffffff
                                            ,0xffffffff,uVar30);
                        if (iVar23 == 0) goto LAB_00425224;
                      }
                    }
                    goto LAB_00426470;
                  }
                  iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(pcStack_5f8);
                  if (iVar20 == 0) goto LAB_00426a70;
                  if ((!bVar5) && (pcStack_5fc != (char *)0x0)) {
                    iVar20 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_5fc);
                    if ((0 < iVar20) && (batch == 0)) {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,
                                 "\nPlease enter the following \'extra\' attributes\n");
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"to be sent with your certificate request\n"
                                );
                    }
                    iStack_60c = 0;
                    pcStack_5c0 = (char *)0x630000;
                    pcStack_5f8 = "\n";
                    pcStack_5a4 = "%s\n";
LAB_00426ba4:
                    uStack_5bc = 0x630000;
                    iVar20 = (*(code *)PTR_sk_num_006a7f2c)(pcStack_5fc);
                    if (iStack_60c < iVar20) {
                      iVar20 = (*(code *)PTR_sk_value_006a7f24)(pcStack_5fc,iStack_60c);
                      uVar30 = *(undefined4 *)(iVar20 + 4);
                      pcVar35 = (char *)(*(code *)PTR_OBJ_txt2nid_006a805c)(uVar30);
                      if (pcVar35 == (char *)0x0) goto LAB_00426bfc;
                      iVar21 = (*(code *)PTR_BIO_snprintf_006a8060)
                                         (auStack_550,100,"%s_default",uVar30);
                      if (iVar21 < 100) {
                        pcVar27 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                                    (req_conf,iVar22,auStack_550);
                        if (pcVar27 == (char *)0x0) {
                          pcVar27 = "";
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_550,100,"%s_value",uVar30);
                        iVar21 = (*(code *)PTR_NCONF_get_string_006a7fa8)
                                           (req_conf,iVar22,auStack_550);
                        if (iVar21 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_550,100,"%s_min",uVar30);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar22,auStack_550,&pcStack_570);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          pcStack_570 = (char *)0xffffffff;
                        }
                        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_550,100,"%s_max",uVar30);
                        iVar23 = (*(code *)PTR_NCONF_get_number_e_006a803c)
                                           (req_conf,iVar22,auStack_550,auStack_56c);
                        if (iVar23 == 0) {
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          auStack_56c[0] = 0xffffffff;
                        }
                        uVar30 = auStack_56c[0];
                        pcVar16 = pcStack_570;
                        puVar14 = PTR_bio_err_006a7f3c;
                        uVar41 = *(undefined4 *)(iVar20 + 8);
                        pcStack_5e0 = pcStack_570;
                        pcStack_5d8 = PTR_bio_err_006a7f3c;
                        do {
                          if (batch == 0) {
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar13,"%s [%s]:",uVar41,pcVar27);
                          }
                          (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar13,0xb,0,0);
                          if (iVar21 == 0) {
                            buf_16713[0] = '\0';
                            if (batch == 0) {
                              iVar20 = (*(code *)PTR_fgets_006aabe8)
                                                 (buf_16713,0x400,*(undefined4 *)PTR_stdin_006aab20)
                              ;
                              if (iVar20 != 0) goto LAB_00426e38;
                              goto LAB_00426fac;
                            }
                            buf_16713[0] = '\n';
                            buf_16713[1] = '\0';
LAB_00426f4c:
                            if (*pcVar27 == '\0') goto LAB_00426bfc;
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,pcVar27,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                          }
                          else {
                            (*(code *)PTR_BUF_strlcpy_006a8064)(buf_16713,iVar21,0x400);
                            (*(code *)PTR_BUF_strlcat_006a8068)(buf_16713,"\n",0x400);
                            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar14,"%s\n",iVar21)
                            ;
LAB_00426e38:
                            if (buf_16713[0] == '\0') {
LAB_00426fac:
                              uStack_5bc = 0x630000;
                              goto LAB_00425224;
                            }
                            if (buf_16713[0] == '\n') goto LAB_00426f4c;
                            if ((buf_16713[0] == '.') && (buf_16713[1] == '\n')) goto LAB_00426bfc;
                          }
                          uStack_5bc = 0x630000;
                          iVar20 = (*(code *)PTR_strlen_006aab30)(buf_16713);
                          if ((&DAT_006aad1f)[iVar20] != '\n') goto LAB_00426a94;
                          (&DAT_006aad1f)[iVar20] = '\0';
                          iVar20 = req_check_len(iVar20 + -1,pcVar16,uVar30);
                        } while (iVar20 == 0);
                        iVar20 = (*(code *)PTR_X509_REQ_add1_attr_by_NID_006a807c)
                                           (piVar38,pcVar35,iStack_5f4,buf_16713,0xffffffff);
                        if (iVar20 != 0) goto LAB_00426bfc;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Error adding attribute\n");
                        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
                      }
                      else {
                        uVar30 = *(undefined4 *)(iVar20 + 4);
LAB_00426944:
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar13,"Name \'%s\' too long\n",uVar30);
                      }
                      goto LAB_00425224;
                    }
                  }
                  goto LAB_00425d70;
                }
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"No template, please set one up.\n");
              }
              else {
                iVar20 = build_subject(piVar38,pcStack_5e0,iStack_5f4);
                if (iVar20 != 0) {
LAB_00425d70:
                  iVar19 = (*(code *)PTR_X509_REQ_set_pubkey_006a8030)(piVar38,iVar19);
                  pcVar35 = pcVar39;
                  if (iVar19 != 0) {
                    if ((bVar4) &&
                       (iVar19 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)),
                       iVar19 == 0)) {
                      (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
                      *(undefined4 *)(*piVar38 + 0x18) = 0;
                    }
                    if (bVar5) {
                      pcStack_5e0 = (char *)0x0;
                      goto LAB_004255dc;
                    }
                    (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_56c,0,0,piVar38,0,0);
                    (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_56c,req_conf);
                    if ((pcStack_5e8 == (char *)0x0) ||
                       (iVar19 = (*(code *)PTR_X509V3_EXT_REQ_add_nconf_006a8034)
                                           (req_conf,auStack_56c,pcStack_5e8,piVar38), iVar19 != 0))
                    {
                      iVar19 = do_X509_REQ_sign(*(undefined4 *)puVar13,piVar38,iStack_584,iStack_5c4
                                                ,puStack_618);
                      if (iVar19 != 0) goto LAB_00425698;
                      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar13,"Error Loading extension section %s\n",
                                 pcStack_5e8);
                    }
                    goto LAB_00425e70;
                  }
                }
              }
            }
          }
        }
        goto LAB_00425224;
      }
LAB_00425e70:
      iVar19 = 0;
      piVar32 = (int *)0x0;
      goto LAB_004245dc;
    }
    if (pcStack_5c0 == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar17,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
    }
    else {
      iVar19 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar17,0x6c,3,pcStack_5c0);
      pcVar35 = pcStack_5c0;
      if (iVar19 < 1) {
LAB_00426268:
        iVar19 = 0;
        (*(code *)PTR_perror_006aab88)(pcVar35);
        piVar38 = (int *)0x0;
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
    }
    if (piVar38 == (int *)0x1) {
      piVar38 = (int *)(*(code *)PTR_d2i_X509_REQ_bio_006a8080)(iVar17,0);
    }
    else {
      if (piVar38 != (int *)0x3) {
        iVar19 = 0;
        piVar38 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar13,"bad input format specified for X509 request\n");
        piVar32 = (int *)0x0;
        goto LAB_004245dc;
      }
      piVar38 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a7fe4)(iVar17,0,0,0);
    }
    if (piVar38 == (int *)0x0) {
      iVar19 = 0;
      piVar32 = (int *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to load X509 request\n");
      goto LAB_004245dc;
    }
    if (bVar5) {
      if (iStack_584 == 0) goto LAB_00425644;
LAB_004255dc:
      piVar32 = (int *)(*(code *)PTR_X509_new_006a7fe8)();
      if ((piVar32 != (int *)0x0) &&
         ((pcStack_5ec == (char *)0x0 ||
          (iVar19 = (*(code *)PTR_X509_set_version_006a7fec)(piVar32,2), iVar19 != 0)))) {
        if (iStack_614 == 0) {
          uVar30 = (*(code *)PTR_X509_get_serialNumber_006a809c)(piVar32);
          iVar19 = (*(code *)PTR_rand_serial_006a80a0)(0,uVar30);
          if (iVar19 != 0) {
            iVar19 = *piVar38;
            goto LAB_0042717c;
          }
        }
        else {
          iVar19 = (*(code *)PTR_X509_set_serialNumber_006a8084)(piVar32,iStack_614);
          if (iVar19 != 0) {
            iVar19 = *piVar38;
LAB_0042717c:
            iVar19 = (*(code *)PTR_X509_set_issuer_name_006a8088)
                               (piVar32,*(undefined4 *)(iVar19 + 0x10));
            if ((((iVar19 != 0) &&
                 (iVar19 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                     (**(undefined4 **)(*piVar32 + 0x10),0), iVar19 != 0)) &&
                (iVar19 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                                    (*(undefined4 *)(*(int *)(*piVar32 + 0x10) + 4),iStack_5a8,0,0),
                iVar19 != 0)) &&
               (((iVar19 = (*(code *)PTR_X509_set_subject_name_006a8094)
                                     (piVar32,*(undefined4 *)(*piVar38 + 0x10)), iVar19 != 0 &&
                 (iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38), iVar19 != 0)) &&
                (iVar20 = (*(code *)PTR_X509_set_pubkey_006a8098)(piVar32,iVar19), iVar20 != 0)))) {
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar19);
              (*(code *)PTR_X509V3_set_ctx_006a7fb4)(auStack_56c,piVar32,piVar32,0,0,0);
              (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_56c,req_conf);
              if ((pcStack_5ec == (char *)0x0) ||
                 (iVar19 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                     (req_conf,auStack_56c,pcStack_5ec,piVar32), iVar19 != 0)) {
                puVar14 = PTR_bio_err_006a7f3c;
                iVar19 = do_X509_sign(*(undefined4 *)puVar13,piVar32,iStack_584,iStack_5c4,
                                      puStack_618);
                if (iVar19 != 0) {
                  if (pcStack_5e0 == (char *)0x0) goto LAB_004256f4;
                  iVar19 = 0;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar14,"Cannot modifiy certificate subject\n");
                  goto LAB_004245dc;
                }
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar14);
              }
              else {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar13,"Error Loading extension section %s\n",pcStack_5ec
                          );
              }
            }
          }
        }
      }
LAB_00425614:
      iVar19 = 0;
      goto LAB_004245dc;
    }
    if (pcStack_5e0 != (char *)0x0) {
      if (pcStack_5d8 == (char *)0x0) {
        iVar19 = build_subject(piVar38,pcStack_5e0,iStack_5f4);
        if (iVar19 == 0) {
LAB_00426fcc:
          iVar19 = 0;
          piVar32 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar13,"ERROR: cannot modify subject\n");
          goto LAB_004245dc;
        }
        *(undefined4 *)(*piVar38 + 8) = 1;
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Modifying Request\'s Subject\n");
        (*(code *)PTR_print_name_006a8004)
                  (*(undefined4 *)puVar13,"old subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_590
                  );
        iVar19 = build_subject(piVar38,pcStack_5e0,iStack_5f4,uStack_5bc);
        puVar14 = PTR_print_name_006a8004;
        if (iVar19 == 0) goto LAB_00426fcc;
        iVar19 = *piVar38;
        uVar30 = *(undefined4 *)PTR_bio_err_006a7f3c;
        *(undefined4 *)(iVar19 + 8) = 1;
        (*(code *)puVar14)(uVar30,"new subject=",*(undefined4 *)(iVar19 + 0x10),uStack_590);
      }
    }
LAB_00425698:
    piVar32 = (int *)0x0;
    if (bVar6) {
      if (iStack_584 == 0) {
        iStack_584 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (iStack_584 == 0) goto LAB_00425e70;
        iVar19 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38,iStack_584);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iStack_584);
        iStack_584 = 0;
      }
      else {
        iVar19 = (*(code *)PTR_X509_REQ_verify_006a7ff0)(piVar38);
      }
      if (iVar19 < 0) goto LAB_00425e70;
      if (iVar19 == 0) {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify failure\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
      }
      else {
        piVar32 = (int *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"verify OK\n");
      }
    }
LAB_004256f4:
    if ((((!bVar7) || (bVar8)) || (bVar9)) || ((bVar10 || (bVar11)))) {
      if (pcStack_5d4 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
      }
      else {
        if ((pcStack_5dc == (char *)0x0) ||
           (iVar19 = (*(code *)PTR_strcmp_006aac20)(pcStack_5d4,pcStack_5dc), iVar19 != 0)) {
          uVar30 = 5;
        }
        else {
          uVar30 = 9;
        }
        iVar19 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,uVar30,pcStack_5d4);
        if (iVar19 == 0) {
          iVar19 = 0;
          (*(code *)PTR_perror_006aab88)(pcStack_5d4);
          goto LAB_004245dc;
        }
      }
      if (bVar11) {
        iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        if (iVar19 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"Error getting public key\n");
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar13);
          goto LAB_004245dc;
        }
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a8028)(iVar18,iVar19);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar19);
      }
      if (bVar8) {
        if (bVar5) {
          (*(code *)PTR_X509_print_ex_006a7ffc)(iVar18,piVar32,uStack_590,uStack_58c);
          if (bVar10) goto LAB_004257c4;
          if (!bVar9) goto LAB_00425894;
LAB_004257fc:
          iVar19 = (*(code *)PTR_X509_get_pubkey_006a8008)(piVar32);
        }
        else {
          (*(code *)PTR_X509_REQ_print_ex_006a7ff8)(iVar18,piVar38,uStack_590,uStack_58c);
          if (bVar10) {
LAB_00425a44:
            (*(code *)PTR_print_name_006a8004)
                      (iVar18,"subject=",*(undefined4 *)(*piVar38 + 0x10),uStack_590);
          }
          if (!bVar9) goto LAB_00425894;
LAB_00425a74:
          iVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(piVar38);
        }
        puVar14 = PTR_stdout_006aaad4;
        if (iVar19 == 0) {
          (*(code *)PTR_fwrite_006aab7c)
                    ("Modulus=unavailable\n",1,0x14,*(undefined4 *)PTR_stdout_006aaad4);
          goto LAB_004245dc;
        }
        (*(code *)PTR_fwrite_006aab7c)("Modulus=",1,8,*(undefined4 *)PTR_stdout_006aaad4);
        iVar20 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar19);
        if (iVar20 == 6) {
          (*(code *)PTR_BN_print_006a8024)(iVar18,*(undefined4 *)(*(int *)(iVar19 + 0x14) + 0x10));
        }
        else {
          (*(code *)PTR_fwrite_006aab7c)("Wrong Algorithm type",1,0x14,*(undefined4 *)puVar14);
        }
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar19);
        (*(code *)PTR_fputc_006aaab0)(10,*(undefined4 *)puVar14);
      }
      else if (bVar10) {
        if (!bVar5) goto LAB_00425a44;
LAB_004257c4:
        uVar30 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar32);
        (*(code *)PTR_print_name_006a8004)(iVar18,"subject=",uVar30,uStack_590);
        if (bVar9) goto LAB_004257fc;
      }
      else if (bVar9) {
        if (bVar5) goto LAB_004257fc;
        goto LAB_00425a74;
      }
LAB_00425894:
      if (!bVar7) {
        if (bVar5) {
          if (piVar32 != (int *)0x0) {
            if (pcVar39 == (char *)0x1) {
              iVar19 = (*(code *)PTR_i2d_X509_bio_006a801c)(iVar18,piVar32);
            }
            else {
              if (pcVar39 != (char *)0x3) goto LAB_0042591c;
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar18,piVar32);
            }
            if (iVar19 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"unable to write X509 certificate\n");
              goto LAB_00425614;
            }
          }
        }
        else {
          if (pcVar39 == (char *)0x1) {
            iVar19 = (*(code *)PTR_i2d_X509_REQ_bio_006a8010)(iVar18,piVar38);
          }
          else {
            if (pcVar39 != (char *)0x3) {
LAB_0042591c:
              iVar19 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar13,"bad output format specified for outfile\n");
              goto LAB_004245dc;
            }
            if (bVar12) {
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_REQ_NEW_006a8018)(iVar18,piVar38);
            }
            else {
              iVar19 = (*(code *)PTR_PEM_write_bio_X509_REQ_006a8014)(iVar18,piVar38);
            }
          }
          if (iVar19 == 0) goto LAB_004258ec;
        }
      }
    }
    iVar19 = 0;
    uVar36 = 0;
  } while( true );
LAB_00426a94:
  uStack_5bc = 0x630000;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"weird input :-(\n");
LAB_00425224:
  if ((bVar4) &&
     (iVar19 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar38 + 0x18)), iVar19 == 0)) {
    (*(code *)PTR_sk_free_006a7f80)(*(undefined4 *)(*piVar38 + 0x18));
    *(undefined4 *)(*piVar38 + 0x18) = 0;
  }
  iVar19 = 0;
  piVar32 = (int *)0x0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"problems making Certificate Request\n")
  ;
  pcVar39 = pcVar35;
  goto LAB_004245dc;
LAB_00426bfc:
  iStack_60c = iStack_60c + 1;
  goto LAB_00426ba4;
LAB_004258ec:
  iVar19 = 0;
  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar13,"unable to write X509 request\n");
  goto LAB_004245dc;
}

