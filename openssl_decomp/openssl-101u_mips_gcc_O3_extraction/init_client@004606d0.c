
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ** init_client(uint *param_1,uint param_2,undefined *param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  int **ppiVar3;
  int **ppiVar4;
  uint **ppuVar5;
  uint *puVar6;
  undefined *puVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  char *pcVar11;
  uint *puVar12;
  code *pcVar13;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  int iStack_104;
  undefined1 *puStack_fc;
  int *piStack_f8;
  int iStack_f4;
  int **ppiStack_f0;
  undefined *puStack_ec;
  uint *puStack_e8;
  code *pcStack_e4;
  undefined4 uStack_d0;
  undefined *puStack_c8;
  uint *puStack_bc;
  uint *puStack_b8;
  int **ppiStack_b4;
  undefined4 uStack_b0;
  char *pcStack_ac;
  undefined4 *puStack_a8;
  char *pcStack_a4;
  uint uStack_a0;
  undefined2 uStack_9c;
  undefined2 uStack_9a;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int *piStack_8c;
  int **ppiStack_88;
  undefined *puStack_84;
  uint uStack_80;
  int iStack_7c;
  undefined *puStack_78;
  uint *puStack_74;
  uint *local_50;
  uint local_3c;
  int *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  local_50 = &local_30;
  ppiStack_88 = &local_38;
  puVar12 = &local_34;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiStack_f0 = ppiStack_88;
  iVar1 = (*(code *)PTR___isoc99_sscanf_006a9a04)(param_2,"%u.%u.%u.%u");
  if (iVar1 == 4) {
    if ((((local_38 < (int *)0x100) && (local_34 < 0x100)) && (local_30 < 0x100)) &&
       (ppiStack_f0 = (int **)(uint)(local_2c < 0x100), ppiStack_f0 != (int **)0x0)) {
      local_28._0_2_ = (ushort)local_34 & 0xff | (ushort)((uint)((int)local_38 << 0x18) >> 0x10);
      local_28 = local_2c & 0xff | (uint)CONCAT21(local_28._0_2_,(char)local_30) << 8;
      local_38 = (int *)((uint)param_3 & 0xffff | 0x20000);
      if (param_4 != 2) goto LAB_004607c8;
LAB_004608ac:
      local_2c = 0;
      local_30 = 0;
      ppiStack_f0 = (int **)&DAT_00000006;
      pcVar10 = &SUB_00000002;
      local_34 = local_28;
      param_2 = (*(code *)PTR_socket_006a9984)(2);
      if (param_2 == 0xffffffff) goto LAB_00460994;
      puVar12 = &local_3c;
      local_3c = 0;
      ppiStack_f0 = (int **)&DAT_00000008;
      pcVar10 = (char *)0xffff;
      local_50 = (uint *)&SUB_00000004;
      local_3c = (*(code *)PTR_setsockopt_006a9b2c)(param_2);
      if (-1 < (int)local_3c) goto LAB_004607ec;
      (*(code *)PTR_close_006a994c)(param_2);
      (*(code *)PTR_perror_006a9a80)("keepalive");
      ppiVar3 = (int **)0x0;
    }
    else {
      pcVar10 = "invalid IP address\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      ppiVar3 = (int **)0x0;
    }
  }
  else {
    iVar1 = GetHostByName(param_2);
    if (iVar1 == 0) {
      pcVar10 = "gethostbyname failure\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      ppiVar3 = (int **)0x0;
    }
    else if (*(short *)(iVar1 + 10) == 2) {
      puVar2 = (undefined *)**(undefined4 **)(iVar1 + 0x10);
      local_28._1_3_ = (uint3)(byte)puVar2[2] << 8;
      local_28._1_3_ = local_28._1_3_ | (uint3)(byte)puVar2[1] << 0x10;
      local_28 = CONCAT13(*puVar2,local_28._1_3_);
      local_28 = local_28 | (byte)puVar2[3];
      local_38 = (int *)((uint)param_3 & 0xffff | 0x20000);
      if (param_4 == 2) goto LAB_004608ac;
LAB_004607c8:
      local_2c = 0;
      local_30 = 0;
      ppiStack_f0 = (int **)&DAT_00000011;
      pcVar10 = (char *)0x1;
      local_34 = local_28;
      param_2 = (*(code *)PTR_socket_006a9984)(2);
      if (param_2 == 0xffffffff) {
LAB_00460994:
        (*(code *)PTR_perror_006a9a80)("socket");
        ppiVar3 = (int **)0x0;
      }
      else {
LAB_004607ec:
        ppiStack_f0 = (int **)&SUB_00000010;
        pcVar10 = (char *)ppiStack_88;
        iVar1 = (*(code *)PTR_connect_006a9950)(param_2);
        if (iVar1 == -1) {
          (*(code *)PTR_close_006a994c)(param_2);
          (*(code *)PTR_perror_006a9a80)("connect");
          ppiVar3 = (int **)0x0;
        }
        else {
          ppiVar3 = (int **)0x1;
          *param_1 = param_2;
        }
      }
    }
    else {
      pcVar10 = "gethostbyname addr is not AF_INET\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      ppiVar3 = (int **)0x0;
    }
  }
  if (local_24 == *(int *)puStack_84) {
    return ppiVar3;
  }
  iVar1 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uStack_9c = 2;
  ppiStack_b4 = (int **)PTR___stack_chk_guard_006a9ae8;
  puStack_fc = (undefined1 *)&uStack_9c;
  puStack_c8 = &_gp;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_9a = (undefined2)iVar1;
  piStack_8c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pcVar11 = &DAT_00000011;
  puStack_bc = puVar12;
  uStack_80 = param_2;
  iStack_7c = param_4;
  puStack_78 = param_3;
  puStack_74 = param_1;
  if (pcVar10 == &SUB_00000002) {
    pcVar11 = &DAT_00000006;
    ppiVar3 = (int **)pcVar10;
    piStack_f8 = (int *)(*(code *)PTR_socket_006a9984)(2);
  }
  else {
    ppiVar3 = (int **)0x1;
    piStack_f8 = (int *)(*(code *)PTR_socket_006a9984)(2);
  }
  iStack_f4 = -1;
  if (piStack_f8 == (int *)0xffffffff) {
LAB_00460be0:
    ppiVar4 = (int **)0x0;
  }
  else {
    param_1 = &uStack_a0;
    uStack_d0 = 4;
    uStack_a0 = 1;
    puVar12 = param_1;
    (**(code **)(puStack_c8 + -0x52b4))(piStack_f8,0xffff,4);
    pcVar11 = &SUB_00000010;
    iVar1 = (**(code **)(puStack_c8 + -0x53d0))(piStack_f8,puStack_fc);
    if (iVar1 == -1) {
      (**(code **)(puStack_c8 + -0x5360))(&DAT_00640fd0);
LAB_00460bbc:
      pcVar13 = *(code **)(puStack_c8 + -0x5484);
LAB_00460bc0:
      ppiVar3 = (int **)0x0;
      (*pcVar13)(piStack_f8);
      (**(code **)(puStack_c8 + -0x5494))(piStack_f8);
      goto LAB_00460be0;
    }
    if (pcVar10 == &SUB_00000002) {
      iVar1 = (**(code **)(puStack_c8 + -0x5430))(piStack_f8,0x80);
      if (iVar1 == -1) {
        pcVar13 = *(code **)(puStack_c8 + -0x5484);
        goto LAB_00460bc0;
      }
    }
    puStack_a8 = *(undefined4 **)(puStack_c8 + -0x7fa4);
    if (ppiStack_f0 != (int **)0x0) {
      *ppiStack_f0 = piStack_f8;
    }
    param_3 = &_gp_1;
    iStack_f4 = 0;
    puStack_fc = from_18073;
    uStack_b0 = 0x6aa904;
    pcStack_ac = "-check_ss_sig";
    pcStack_a4 = "bad gethostbyaddr\n";
    do {
      while (pcVar11 = (char *)local_50, pcVar10 != &SUB_00000002) {
        ppiVar4 = (int **)(*(code *)puStack_bc)(iStack_f4,piStack_f8);
        if (iStack_f4 != 0) {
          (**(code **)(puStack_c8 + -0x7f58))(iStack_f4);
        }
        pcVar13 = *(code **)(puStack_c8 + -0x5484);
        if ((int)ppiVar4 < 0) goto LAB_00460b60;
      }
      ppiStack_f0 = (int **)&SUB_00000010;
      iStack_f4 = -1;
      while( true ) {
        from_18073._0_4_ = 0;
        from_18073._4_4_ = 0;
        from_18073._8_4_ = 0;
        from_18073._12_4_ = 0;
        uStack_a0 = 0x10;
        puVar6 = (uint *)(**(code **)(puStack_c8 + -0x5368))(piStack_f8,from_18073,param_1);
        if (puVar6 != (uint *)0xffffffff) break;
        ppuVar5 = (uint **)(**(code **)(puStack_c8 + -0x53f8))();
        puVar12 = *ppuVar5;
        if (puVar12 != (uint *)&SUB_00000004) {
          pcVar11 = "errno=%d ";
          (**(code **)(puStack_c8 + -0x5460))(**(undefined4 **)(puStack_c8 + -0x52e8),1);
          (**(code **)(puStack_c8 + -0x5360))("accept");
          goto LAB_00460bbc;
        }
      }
      puStack_b8 = puVar6;
      ppiStack_f0 = (int **)(**(code **)(puStack_c8 + -0x532c))(uStack_b0,4,2);
      if (ppiStack_f0 != (int **)0x0) {
        iVar1 = (**(code **)(puStack_c8 + -0x53bc))(*ppiStack_f0);
        pcVar11 = (char *)0x1c5;
        iStack_f4 = (**(code **)(puStack_c8 + -0x7dd8))(iVar1 + 1,pcStack_ac + 0xff8);
        if (iStack_f4 == 0) {
          puStack_bc = puStack_b8;
          (**(code **)(puStack_c8 + -0x5360))("OPENSSL_malloc");
        }
        else {
          ppiStack_f0 = (int **)*ppiStack_f0;
          iVar1 = (**(code **)(puStack_c8 + -0x53bc))(ppiStack_f0);
          pcVar11 = (char *)(iVar1 + 1);
          (**(code **)(puStack_c8 + -0x7e7c))(iStack_f4,ppiStack_f0);
          iVar1 = GetHostByName(iStack_f4);
          if (iVar1 == 0) {
            pcVar13 = *(code **)(puStack_c8 + -0x7fa8);
            pcVar10 = "gethostbyname failure\n";
          }
          else {
            if (*(int *)(iVar1 + 8) == 2) {
              pcVar11 = (char *)local_50;
              ppiVar4 = (int **)(*(code *)puStack_bc)(iStack_f4,puStack_b8);
              (**(code **)(puStack_c8 + -0x7f58))(iStack_f4);
              goto LAB_00460d60;
            }
            pcVar13 = *(code **)(puStack_c8 + -0x7fa8);
            pcVar10 = "gethostbyname addr is not AF_INET\n";
          }
          puStack_bc = puStack_b8;
          (*pcVar13)(**(undefined4 **)(puStack_c8 + -0x7fa4),pcVar10);
        }
        (**(code **)(puStack_c8 + -0x5494))(puStack_bc);
        goto LAB_00460bbc;
      }
      iStack_f4 = 0;
      (**(code **)(puStack_c8 + -0x7fa8))(*puStack_a8,pcStack_a4);
      ppiVar4 = (int **)(*(code *)puStack_bc)(0,puStack_b8);
LAB_00460d60:
      (**(code **)(puStack_c8 + -0x5484))(puStack_b8,2);
      (**(code **)(puStack_c8 + -0x5494))(puStack_b8);
    } while (-1 < (int)ppiVar4);
    pcVar13 = *(code **)(puStack_c8 + -0x5484);
LAB_00460b60:
    ppiVar3 = (int **)&SUB_00000002;
    (*pcVar13)(piStack_f8);
    (**(code **)(puStack_c8 + -0x5494))(piStack_f8);
    ppiStack_f0 = ppiVar4;
  }
  if (piStack_8c == *ppiStack_b4) {
    return ppiVar4;
  }
  pcStack_e4 = extract_host_port;
  piVar9 = piStack_8c;
  (**(code **)(puStack_c8 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_104 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_ec = param_3;
  puStack_e8 = param_1;
  puVar7 = (undefined *)(*(code *)PTR_strchr_006a9a28)();
  if (puVar7 == (undefined *)0x0) {
    ppiVar3 = (int **)0x0;
    pcVar10 = "no port defined\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
    goto LAB_00460fd0;
  }
  *puVar7 = 0;
  if ((uint *)pcVar11 != (uint *)0x0) {
    iVar1 = (*(code *)PTR___isoc99_sscanf_006a9a04)
                      (piVar9,"%u.%u.%u.%u",&uStack_114,&uStack_110,&uStack_10c,&uStack_108);
    if (iVar1 == 4) {
      if (((0xff < uStack_114) || (0xff < uStack_110)) ||
         ((0xff < uStack_10c || (0xff < uStack_108)))) {
        ppiVar3 = (int **)0x0;
        pcVar10 = "invalid IP address\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      *pcVar11 = (char)uStack_114;
      *(char *)((int)pcVar11 + 1) = (char)uStack_110;
      *(char *)((int)pcVar11 + 2) = (char)uStack_10c;
      *(char *)((int)pcVar11 + 3) = (char)uStack_108;
    }
    else {
      iVar1 = GetHostByName(piVar9);
      if (iVar1 == 0) {
        ppiVar3 = (int **)0x0;
        pcVar10 = "gethostbyname failure\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      if (*(short *)(iVar1 + 10) != 2) {
        ppiVar3 = (int **)0x0;
        pcVar10 = "gethostbyname addr is not AF_INET\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      *pcVar11 = ***(char ***)(iVar1 + 0x10);
      *(char *)((int)pcVar11 + 1) = *(char *)(**(int **)(iVar1 + 0x10) + 1);
      *(char *)((int)pcVar11 + 2) = *(char *)(**(int **)(iVar1 + 0x10) + 2);
      *(char *)((int)pcVar11 + 3) = *(char *)(**(int **)(iVar1 + 0x10) + 3);
    }
  }
  if (ppiVar3 != (int **)0x0) {
    *ppiVar3 = piVar9;
  }
  puVar7 = puVar7 + 1;
  pcVar10 = (char *)0x0;
  ppiVar3 = (int **)(*(code *)PTR_strtol_006a9958)(puVar7,0,10);
  if (ppiVar3 == (int **)0x0) {
    pcVar10 = &DAT_00641018;
    iVar1 = (*(code *)PTR_getservbyname_006a99f0)(puVar7);
    if (iVar1 == 0) {
      pcVar10 = "getservbyname failure for %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"getservbyname failure for %s\n",puVar7);
      goto LAB_00460fd0;
    }
    *(short *)puVar12 = (short)*(undefined4 *)(iVar1 + 8);
  }
  else {
    *(short *)puVar12 = (short)ppiVar3;
  }
  ppiVar3 = (int **)0x1;
LAB_00460fd0:
  if (iStack_104 == *(int *)puVar2) {
    return ppiVar3;
  }
  iVar1 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppiVar3 = (int **)(*(code *)PTR_strtol_006a9958)();
  if (ppiVar3 == (int **)0x0) {
    iVar8 = (*(code *)PTR_getservbyname_006a99f0)(iVar1,&DAT_00641018);
    if (iVar8 != 0) {
      *(short *)pcVar10 = (short)*(undefined4 *)(iVar8 + 8);
      return (int **)0x1;
    }
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"getservbyname failure for %s\n",iVar1);
  }
  else {
    *(short *)pcVar10 = (short)ppiVar3;
    ppiVar3 = (int **)0x1;
  }
  return ppiVar3;
}

