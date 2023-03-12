
/* WARNING: Could not reconcile some variable overlaps */

int BIO_accept(int sock,char **ip_port)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  size_t n;
  uint uVar9;
  undefined4 local_468;
  uint local_464;
  uint local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined auStack_448 [32];
  undefined auStack_428 [1028];
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_468 = 0x1c;
  local_464 = 0;
  local_460 = 0;
  local_45c = 0;
  local_458 = 0;
  local_454 = 0;
  local_450 = 0;
  local_44c = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_accept_006a9a78)(sock,&local_464,&local_468);
  if (iVar4 == -1) {
    iVar4 = BIO_sock_should_retry(-1);
    if (iVar4 == 0) {
      piVar7 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      ERR_put_error(2,8,*piVar7,"b_sock.c",0x357);
      ERR_put_error(0x20,0x65,100,"b_sock.c",0x358);
      iVar4 = -1;
    }
    else {
      iVar4 = -2;
    }
  }
  else if (ip_port != (char **)0x0) {
    if ((p_getnameinfo_6687 == (code *)0x0) &&
       (p_getnameinfo_6687 = (code *)(*(code *)PTR_DSO_global_lookup_006a88fc)("getnameinfo"),
       p_getnameinfo_6687 == (code *)0x0)) {
      p_getnameinfo_6687 = (code *)0xffffffff;
    }
    else if (p_getnameinfo_6687 != (code *)0xffffffff) {
      iVar5 = (*p_getnameinfo_6687)(&local_464,local_468,auStack_428,0x401,auStack_448,0x20,3);
      if (iVar5 == 0) {
        iVar5 = (*(code *)PTR_strlen_006a9a24)(auStack_428);
        iVar6 = (*(code *)PTR_strlen_006a9a24)(auStack_448);
        puVar1 = PTR_CRYPTO_realloc_006a7b58;
        pcVar8 = *ip_port;
        n = iVar5 + iVar6 + 2;
        if (pcVar8 == (char *)0x0) {
          pcVar8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(n,"b_sock.c",0x381);
        }
        else {
          *pcVar8 = '\0';
          pcVar8 = (char *)(*(code *)puVar1)(pcVar8,n,"b_sock.c",0x37f);
        }
        if (pcVar8 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",900);
        }
        else {
          *ip_port = pcVar8;
          BIO_snprintf(pcVar8,n,"%s:%s",auStack_428,auStack_448);
        }
        goto LAB_00527fb0;
      }
    }
    uVar3 = local_460;
    if (local_464._0_2_ == 2) {
      pcVar8 = *ip_port;
      uVar9 = local_464 & 0xffff;
      if (pcVar8 == (char *)0x0) {
        pcVar8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"b_sock.c",0x391);
        if (pcVar8 == (char *)0x0) {
          ERR_put_error(0x20,0x65,0x41,"b_sock.c",0x392);
          goto LAB_00527fb0;
        }
        *ip_port = pcVar8;
      }
      BIO_snprintf(pcVar8,0x18,"%d.%d.%d.%d:%d",uVar3 >> 0x18,(uVar3 << 8) >> 0x18,
                   (uVar3 << 0x10) >> 0x18,uVar3 & 0xff,uVar9);
    }
  }
LAB_00527fb0:
  if (local_24 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return 1;
  }
  return iVar4;
}

