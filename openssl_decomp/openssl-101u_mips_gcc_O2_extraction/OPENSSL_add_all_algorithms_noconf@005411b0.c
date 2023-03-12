
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OPENSSL_add_all_algorithms_noconf(void)

{
  (*(code *)PTR_OPENSSL_cpuid_setup_006a8820)();
  OpenSSL_add_all_ciphers();
  OpenSSL_add_all_digests();
  return;
}

