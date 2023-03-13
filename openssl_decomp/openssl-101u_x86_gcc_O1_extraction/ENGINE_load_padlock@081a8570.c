
/* WARNING: Removing unreachable block (ram,0x081a85ee) */
/* WARNING: Removing unreachable block (ram,0x081a85de) */
/* WARNING: Removing unreachable block (ram,0x081a85bf) */

void ENGINE_load_padlock(void)

{
  uint *puVar1;
  ENGINE *e;
  uint uVar2;
  char *pcVar3;
  ENGINE *e_00;
  int iVar4;
  undefined4 *puVar5;
  int in_GS_OFFSET;
  bool bVar6;
  byte in_IF;
  byte bVar7;
  bool bVar8;
  byte in_VIP;
  byte in_ID;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined local_14;
  int local_10;
  
  bVar7 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    uVar2 = ((uint)(bVar7 & 1) * 0x400 | (uint)(in_IF & 1) * 0x200 | (uint)(in_ID & 1) * 0x200000 |
            (uint)(in_VIP & 1) * 0x100000) ^ 0x200000;
    bVar8 = (uVar2 & 0x400) != 0;
    bVar6 = (uVar2 & 0x200000) == ((uint)((uVar2 & 0x200000) != 0) * 0x200000 & 0x200000);
    if (bVar6) {
      local_14 = 0;
      iVar4 = cpuid_basic_info(0);
      local_20 = *(undefined4 *)(iVar4 + 4);
      local_1c = *(undefined4 *)(iVar4 + 8);
      local_18 = *(undefined4 *)(iVar4 + 0xc);
      iVar4 = 0xd;
      puVar5 = &local_20;
      pcVar3 = "CentaurHauls";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar6 = *(char *)puVar5 == *pcVar3;
        puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar8 * -2 + 1);
        pcVar3 = pcVar3 + (uint)bVar8 * -2 + 1;
      } while (bVar6);
      if ((bVar6) && (puVar1 = (uint *)cpuid(0xc0000000), 0xc0000000 < *puVar1)) {
        iVar4 = cpuid(0xc0000001);
        padlock_use_ace = (uint)((*(uint *)(iVar4 + 8) & 0xc0) == 0xc0);
      }
    }
    pcVar3 = "no-ACE";
    if (padlock_use_ace != 0) {
      pcVar3 = "ACE";
    }
    padlock_use_rng = (ENGINE *)0x0;
    BIO_snprintf(padlock_name,100,"VIA PadLock (%s, %s)","no-RNG",pcVar3);
    iVar4 = ENGINE_set_id(e,"padlock");
    if ((((iVar4 == 0) || (iVar4 = ENGINE_set_name(e,padlock_name), iVar4 == 0)) ||
        (iVar4 = ENGINE_set_init_function(e,padlock_init), iVar4 == 0)) ||
       (((padlock_use_ace != 0 && (iVar4 = ENGINE_set_ciphers(e,padlock_ciphers), iVar4 == 0)) ||
        ((e_00 = padlock_use_rng, padlock_use_rng != (ENGINE *)0x0 &&
         (e_00 = (ENGINE *)ENGINE_set_RAND(e,(RAND_METHOD *)padlock_rand), e_00 == (ENGINE *)0x0))))
       )) {
      ENGINE_free(e);
    }
    else {
      ENGINE_add(e_00);
      ENGINE_free(e);
      ERR_clear_error();
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

