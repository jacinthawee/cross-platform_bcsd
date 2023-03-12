
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ** init_client(uint *param_1,uint param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  int **ppiVar3;
  int **ppiVar4;
  uint **ppuVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  uint *puVar11;
  code *pcVar12;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  int iStack_104;
  undefined1 *puStack_fc;
  int iStack_f8;
  int iStack_f4;
  int **ppiStack_f0;
  undefined1 *puStack_ec;
  uint *puStack_e8;
  code *pcStack_e4;
  undefined4 uStack_d0;
  undefined *puStack_c8;
  uint *puStack_bc;
  int iStack_b8;
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
  undefined1 *puStack_78;
  uint *puStack_74;
  uint *local_50;
  uint local_3c;
  int *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  
  puStack_84 = PTR___stack_chk_guard_006aabf0;
  local_50 = &local_30;
  ppiStack_88 = &local_38;
  puVar11 = &local_34;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppiStack_f0 = ppiStack_88;
  iVar1 = (*(code *)PTR___isoc99_sscanf_006aab10)(param_2,"%u.%u.%u.%u");
  if (iVar1 == 4) {
    if ((((local_38 < (int *)0x100) && (local_34 < 0x100)) && (local_30 < 0x100)) &&
       (ppiStack_f0 = (int **)(uint)(local_2c < 0x100), ppiStack_f0 != (int **)0x0)) {
      local_28._0_2_ = (ushort)local_34 & 0xff | (ushort)((uint)((int)local_38 << 0x18) >> 0x10);
      local_28 = local_2c & 0xff | (uint)CONCAT21(local_28._0_2_,(char)local_30) << 8;
      local_38 = (int *)((uint)param_3 & 0xffff | 0x20000);
      if (param_4 != 2) goto LAB_0045fcb8;
LAB_0045fd9c:
      local_2c = 0;
      local_30 = 0;
      ppiStack_f0 = (int **)&DAT_00000006;
      pcVar9 = &SUB_00000002;
      local_34 = local_28;
      param_2 = (*(code *)PTR_socket_006aaa90)(2);
      if (param_2 == 0xffffffff) goto LAB_0045fe74;
      puVar11 = &local_3c;
      local_3c = 0;
      ppiStack_f0 = (int **)&DAT_00000008;
      pcVar9 = (char *)0xffff;
      local_50 = (uint *)&SUB_00000004;
      local_3c = (*(code *)PTR_setsockopt_006aac34)(param_2);
      if (-1 < (int)local_3c) goto LAB_0045fcdc;
      (*(code *)PTR_perror_006aab88)("keepalive");
      ppiVar3 = (int **)0x0;
    }
    else {
      pcVar9 = "invalid IP address\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      ppiVar3 = (int **)0x0;
    }
  }
  else {
    iVar1 = GetHostByName(param_2);
    if (iVar1 == 0) {
      pcVar9 = "gethostbyname failure\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      ppiVar3 = (int **)0x0;
    }
    else if (*(short *)(iVar1 + 10) == 2) {
      puVar2 = (undefined *)**(undefined4 **)(iVar1 + 0x10);
      local_28._1_3_ = (uint3)(byte)puVar2[2] << 8;
      local_28._1_3_ = local_28._1_3_ | (uint3)(byte)puVar2[1] << 0x10;
      local_28 = CONCAT13(*puVar2,local_28._1_3_);
      local_28 = local_28 | (byte)puVar2[3];
      local_38 = (int *)((uint)param_3 & 0xffff | 0x20000);
      if (param_4 == 2) goto LAB_0045fd9c;
LAB_0045fcb8:
      local_2c = 0;
      local_30 = 0;
      ppiStack_f0 = (int **)&DAT_00000011;
      pcVar9 = (char *)0x1;
      local_34 = local_28;
      param_2 = (*(code *)PTR_socket_006aaa90)(2);
      if (param_2 == 0xffffffff) {
LAB_0045fe74:
        (*(code *)PTR_perror_006aab88)("socket");
        ppiVar3 = (int **)0x0;
      }
      else {
LAB_0045fcdc:
        ppiStack_f0 = (int **)&SUB_00000010;
        pcVar9 = (char *)ppiStack_88;
        iVar1 = (*(code *)PTR_connect_006aaa60)(param_2);
        if (iVar1 == -1) {
          (*(code *)PTR_close_006aaa5c)(param_2);
          (*(code *)PTR_perror_006aab88)("connect");
          ppiVar3 = (int **)0x0;
        }
        else {
          ppiVar3 = (int **)0x1;
          *param_1 = param_2;
        }
      }
    }
    else {
      pcVar9 = "gethostbyname addr is not AF_INET\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      ppiVar3 = (int **)0x0;
    }
  }
  if (local_24 == *(int *)puStack_84) {
    return ppiVar3;
  }
  iVar1 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uStack_9c = 2;
  ppiStack_b4 = (int **)PTR___stack_chk_guard_006aabf0;
  puStack_fc = (undefined1 *)&uStack_9c;
  puStack_c8 = &_gp;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_9a = (undefined2)iVar1;
  piStack_8c = *(int **)PTR___stack_chk_guard_006aabf0;
  pcVar10 = &DAT_00000011;
  puStack_bc = puVar11;
  uStack_80 = param_2;
  iStack_7c = param_4;
  puStack_78 = param_3;
  puStack_74 = param_1;
  if (pcVar9 == &SUB_00000002) {
    pcVar10 = &DAT_00000006;
    ppiVar3 = (int **)pcVar9;
    iStack_f8 = (*(code *)PTR_socket_006aaa90)(2);
  }
  else {
    ppiVar3 = (int **)0x1;
    iStack_f8 = (*(code *)PTR_socket_006aaa90)(2);
  }
  iStack_f4 = -1;
  if (iStack_f8 == -1) {
LAB_004600c0:
    ppiVar4 = (int **)0x0;
  }
  else {
    param_1 = &uStack_a0;
    uStack_d0 = 4;
    uStack_a0 = 1;
    puVar11 = param_1;
    (**(code **)(puStack_c8 + -0x52ac))(iStack_f8,0xffff,4);
    pcVar10 = &SUB_00000010;
    iVar1 = (**(code **)(puStack_c8 + -0x53c4))(iStack_f8,puStack_fc);
    if (iVar1 == -1) {
      (**(code **)(puStack_c8 + -0x5358))(&DAT_00641540);
LAB_0046009c:
      pcVar12 = *(code **)(puStack_c8 + -0x5474);
LAB_004600a0:
      ppiVar3 = (int **)0x0;
      (*pcVar12)(iStack_f8);
      (**(code **)(puStack_c8 + -0x5484))(iStack_f8);
      goto LAB_004600c0;
    }
    if (pcVar9 == &SUB_00000002) {
      iVar1 = (**(code **)(puStack_c8 + -0x5424))(iStack_f8,0x80);
      if (iVar1 == -1) {
        pcVar12 = *(code **)(puStack_c8 + -0x5474);
        goto LAB_004600a0;
      }
    }
    puStack_a8 = *(undefined4 **)(puStack_c8 + -0x7fa4);
    if (ppiStack_f0 != (int **)0x0) {
      *ppiStack_f0 = (int *)iStack_f8;
    }
    param_3 = &_ITM_registerTMCloneTable;
    iStack_f4 = 0;
    puStack_fc = from_18063;
    uStack_b0 = 0x6aba14;
    pcStack_ac = "s\n";
    pcStack_a4 = "bad gethostbyaddr\n";
    do {
      while (pcVar10 = (char *)local_50, pcVar9 != &SUB_00000002) {
        ppiVar4 = (int **)(*(code *)puStack_bc)(iStack_f4,iStack_f8);
        if (iStack_f4 != 0) {
          (**(code **)(puStack_c8 + -0x7f58))(iStack_f4);
        }
        pcVar12 = *(code **)(puStack_c8 + -0x5474);
        if ((int)ppiVar4 < 0) goto LAB_00460040;
      }
      ppiStack_f0 = (int **)&SUB_00000010;
      iStack_f4 = -1;
      while( true ) {
        from_18063._0_4_ = 0;
        from_18063._4_4_ = 0;
        from_18063._8_4_ = 0;
        from_18063._12_4_ = 0;
        uStack_a0 = 0x10;
        iVar1 = (**(code **)(puStack_c8 + -0x5360))(iStack_f8,from_18063,param_1);
        if (iVar1 != -1) break;
        ppuVar5 = (uint **)(**(code **)(puStack_c8 + -0x53ec))();
        puVar11 = *ppuVar5;
        if (puVar11 != (uint *)&SUB_00000004) {
          pcVar10 = "errno=%d ";
          (**(code **)(puStack_c8 + -0x5454))(**(undefined4 **)(puStack_c8 + -0x52e0),1);
          (**(code **)(puStack_c8 + -0x5358))("accept");
          goto LAB_0046009c;
        }
      }
      iStack_b8 = iVar1;
      ppiStack_f0 = (int **)(**(code **)(puStack_c8 + -0x5324))(uStack_b0,4,2);
      if (ppiStack_f0 == (int **)0x0) {
        iStack_f4 = 0;
        (**(code **)(puStack_c8 + -0x7fa8))(*puStack_a8,pcStack_a4);
        ppiVar4 = (int **)(*(code *)puStack_bc)(0,iStack_b8);
      }
      else {
        iVar1 = (**(code **)(puStack_c8 + -0x53b0))(*ppiStack_f0);
        pcVar10 = (char *)0x1c2;
        iStack_f4 = (**(code **)(puStack_c8 + -0x7dd8))(iVar1 + 1,pcStack_ac + 0x1568);
        if (iStack_f4 == 0) {
          (**(code **)(puStack_c8 + -0x5358))("OPENSSL_malloc");
          goto LAB_0046009c;
        }
        ppiStack_f0 = (int **)*ppiStack_f0;
        iVar1 = (**(code **)(puStack_c8 + -0x53b0))(ppiStack_f0);
        pcVar10 = (char *)(iVar1 + 1);
        (**(code **)(puStack_c8 + -0x7e7c))(iStack_f4,ppiStack_f0);
        iVar1 = GetHostByName(iStack_f4);
        if (iVar1 == 0) {
          (**(code **)(puStack_c8 + -0x7fa8))
                    (**(undefined4 **)(puStack_c8 + -0x7fa4),"gethostbyname failure\n");
          goto LAB_0046009c;
        }
        if (*(int *)(iVar1 + 8) != 2) {
          (**(code **)(puStack_c8 + -0x7fa8))
                    (**(undefined4 **)(puStack_c8 + -0x7fa4),"gethostbyname addr is not AF_INET\n");
          goto LAB_0046009c;
        }
        pcVar10 = (char *)local_50;
        ppiVar4 = (int **)(*(code *)puStack_bc)(iStack_f4,iStack_b8);
        (**(code **)(puStack_c8 + -0x7f58))(iStack_f4);
      }
      (**(code **)(puStack_c8 + -0x5474))(iStack_b8,2);
      (**(code **)(puStack_c8 + -0x5484))(iStack_b8);
    } while (-1 < (int)ppiVar4);
    pcVar12 = *(code **)(puStack_c8 + -0x5474);
LAB_00460040:
    ppiVar3 = (int **)&SUB_00000002;
    (*pcVar12)(iStack_f8);
    (**(code **)(puStack_c8 + -0x5484))(iStack_f8);
    ppiStack_f0 = ppiVar4;
  }
  if (piStack_8c == *ppiStack_b4) {
    return ppiVar4;
  }
  pcStack_e4 = extract_host_port;
  piVar8 = piStack_8c;
  (**(code **)(puStack_c8 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_104 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_ec = param_3;
  puStack_e8 = param_1;
  puVar6 = (undefined *)(*(code *)PTR_strchr_006aab34)();
  if (puVar6 == (undefined *)0x0) {
    ppiVar3 = (int **)0x0;
    pcVar9 = "no port defined\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    goto LAB_004604a0;
  }
  *puVar6 = 0;
  if ((uint *)pcVar10 != (uint *)0x0) {
    iVar1 = (*(code *)PTR___isoc99_sscanf_006aab10)
                      (piVar8,"%u.%u.%u.%u",&uStack_114,&uStack_110,&uStack_10c,&uStack_108);
    if (iVar1 == 4) {
      if (((0xff < uStack_114) || (0xff < uStack_110)) ||
         ((0xff < uStack_10c || (0xff < uStack_108)))) {
        ppiVar3 = (int **)0x0;
        pcVar9 = "invalid IP address\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *pcVar10 = (char)uStack_114;
      *(char *)((int)pcVar10 + 1) = (char)uStack_110;
      *(char *)((int)pcVar10 + 2) = (char)uStack_10c;
      *(char *)((int)pcVar10 + 3) = (char)uStack_108;
    }
    else {
      iVar1 = GetHostByName(piVar8);
      if (iVar1 == 0) {
        ppiVar3 = (int **)0x0;
        pcVar9 = "gethostbyname failure\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      if (*(short *)(iVar1 + 10) != 2) {
        ppiVar3 = (int **)0x0;
        pcVar9 = "gethostbyname addr is not AF_INET\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_004604a0;
      }
      *pcVar10 = ***(char ***)(iVar1 + 0x10);
      *(char *)((int)pcVar10 + 1) = *(char *)(**(int **)(iVar1 + 0x10) + 1);
      *(char *)((int)pcVar10 + 2) = *(char *)(**(int **)(iVar1 + 0x10) + 2);
      *(char *)((int)pcVar10 + 3) = *(char *)(**(int **)(iVar1 + 0x10) + 3);
    }
  }
  if (ppiVar3 != (int **)0x0) {
    *ppiVar3 = piVar8;
  }
  puVar6 = puVar6 + 1;
  pcVar9 = (char *)0x0;
  ppiVar3 = (int **)(*(code *)PTR_strtol_006aaa68)(puVar6,0,10);
  if (ppiVar3 == (int **)0x0) {
    pcVar9 = &DAT_00641588;
    iVar1 = (*(code *)PTR_getservbyname_006aaafc)(puVar6);
    if (iVar1 == 0) {
      pcVar9 = "getservbyname failure for %s\n";
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",puVar6);
      goto LAB_004604a0;
    }
    *(short *)puVar11 = (short)*(undefined4 *)(iVar1 + 8);
  }
  else {
    *(short *)puVar11 = (short)ppiVar3;
  }
  ppiVar3 = (int **)0x1;
LAB_004604a0:
  if (iStack_104 == *(int *)puVar2) {
    return ppiVar3;
  }
  iVar1 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppiVar3 = (int **)(*(code *)PTR_strtol_006aaa68)();
  if (ppiVar3 == (int **)0x0) {
    iVar7 = (*(code *)PTR_getservbyname_006aaafc)(iVar1,&DAT_00641588);
    if (iVar7 != 0) {
      *(short *)pcVar9 = (short)*(undefined4 *)(iVar7 + 8);
      return (int **)0x1;
    }
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"getservbyname failure for %s\n",iVar1);
  }
  else {
    *(short *)pcVar9 = (short)ppiVar3;
    ppiVar3 = (int **)0x1;
  }
  return ppiVar3;
}

