
undefined4 tls12_get_hash(undefined param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  default:
    return 0;
  case 2:
                    /* WARNING: Could not recover jumptable at 0x00497fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha1_006a86c4)();
    return uVar1;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x00497fcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha224_006a9304)();
    return uVar1;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x00497fd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha256_006a916c)();
    return uVar1;
  case 5:
                    /* WARNING: Could not recover jumptable at 0x00497fe4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha384_006a9308)();
    return uVar1;
  case 6:
                    /* WARNING: Could not recover jumptable at 0x00497fb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha512_006a9300)();
    return uVar1;
  }
}

