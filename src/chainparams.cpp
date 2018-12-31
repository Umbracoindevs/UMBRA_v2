
// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018-2019 The Umbra 2 developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x983187781fecc3181af6fc5211abbd2feb62e09fadf971970353cf98e6b2fc10"))
    (1, uint256("0x00000fa538e56e9bd6b0a4c06019b82d16bb1400f6e7edcdbc67e6c88514dfb6"))
    (2, uint256("0x00000785b3ee2eec1fd5f5862ab0c12b73c0c804e80c438271d4c0080005c68d"))
    (3, uint256("0x00000306b123fc64cb76630286043cd316fa17e03d055cfa0ed6df7d5b57a90e"))
    (4, uint256("0x0000090723b6ec9bdcd445a905b505cee99d18f6739d1491c8cee9deaade9bb1"))
    (5, uint256("0x00000684a89d81490521936df24658ce25ecf26ff6c34053d1f5fb5f1b9d3c0c"))
    (6, uint256("0x000008b887f7bdd417a2243c3590c8a33949f4eb5c9ddc0bec911e2c9c52d252"))
    (7, uint256("0x0000071a27e992df12af84c11a1403052d1921f14d87db6735bd4c6ac99b06f2"))
    (8, uint256("0x00000d705aa419c4562a551b30518d8eb09c11973f56354aecab755515bda153"))
    (9, uint256("0x000007f7b475e3a58483815753917e1d5e5e51b143f02652ab846bf1dcc14afb"))
    (10, uint256("0x000008f68b2dd90f1974c128039802319b0224e057f7aa27cf91e7bc0977493f"))
    (11, uint256("0x00000625199f686bfdb9b75bd64a4d60f059ed9bd69edecd1d8f001bbe76dba7"))
    (12, uint256("0x00000b58960b18aa47b8bda5641e5758cb12260c488ddb72e885b4850cd639ba"))
    (13, uint256("0x00000d194268b10138578c8eebe84b700ed5e0b3b75a14434081c73fe47bb60a"))
    (14, uint256("0x000009b19560ed19488e98665aeb2329cd0f318b07d29437ee6513b07761d78a"))
    (15, uint256("0x000007eddd61e08f5c0c2ab19b493c832d071d1881ed10ba8c8c4c9f5ffa4ba2"))
    (16, uint256("0x000003ceb1556bf246421fb18c04be371f389013c6a51ff08cd1faf5d2a468f0"))
    (17, uint256("0x0000055d1c7358d5c00cf568c50a516420c783dd1e223036d4089c5c398de11b"))
    (18, uint256("0x0000044982de4b31c88ab1f5917fe600fb2f86a6af8d2476332af0ee8078ea73"))
    (19, uint256("0x00000236037a71a70f43d9d3284a62b2297ed864768ef849f7eee6146c218b31"))
    (20, uint256("0x0000040bf71af77340466eb441f24746172f660eb2943b5957cf21d8dc778c1e"))
    (21, uint256("0x00000daacc730ab8ada8ec863795a2d99fe43acfac8ea6d6c909f4b2b64e8f02"))
    (22, uint256("0x000006e7d1c2559529c5052b7dcd167a461a043210e46ac18021ab8993d545cd"))
    (23, uint256("0x000009bef300979b85e22895a4b17eeedffa23230578f9a1f2eafc3d9ae87591"))
    (24, uint256("0x00000ccf86804a27d94d2fe819575521310cfdf965511d7eeaf71f62d0c4bf0e"))
    (25, uint256("0x000002842d0f81d18a00a131f2b757f95408a36c2d989e96c96b011372144728"))
    (26, uint256("0x00000099692c0804828760c5d3357c979f38309a45627cdf6917f61dc569b9a7"))
    (27, uint256("0x000001ddcfd31e9a767cbdbcd5e905316bc70e315ceae712a6f021e1dcad1099"))
    (28, uint256("0x00000236a5aaa9117e1ce2e57e8f93c2e3477da67a2d790d37248dcc583c6860"))
    (29, uint256("0x00000355fb660684cb73e57da9093d61eb416a53e4369d5ae47ddeea4391ba17"))
    (30, uint256("0x000003db5733392f57d6da6e5c5552e44b6d43e22d57dd9b1616193b1ea725db"))
    (31, uint256("0x000001733224f54b91b74734689857c29c37eda58739625880ef6080af921720"))
    (32, uint256("0x0000015f85c38328113a7bd6cfabe0c852f7dca27db0b7c2c408491b619e4933"))
    (33, uint256("0x00000150687bf2da9551cd8c7478595f8f07a2b97ee884c947a8b490fa395f3e"))
    (34, uint256("0x0000033597b810ab66092a78653543e78da94106986c1c284987800b52008acf"))
    (35, uint256("0x000003adf2a36d9f72a954ec2deba720ede29b16b0dd18716ea77cf7321dd4fe"))
    (36, uint256("0x0000050ca19dceb5958f705a78ce1e19af923918ce91be2460fd0c4ab0d28655"))
    (37, uint256("0x000003c445daec9b8ad35ceff5f4845ba1252d41cdda2bb2a281b714f4fc125f"))
    (38, uint256("0x0000059297d7d2e846b2d890650e0f98edcd5bff6e2fec517c0ab47962c47f3f"))
    (39, uint256("0x0000063d57f23ffa7f02f0059fc4afcb3de5b49aa24a450cb5532a0afd1813d6"))
    (301, uint256("0x00000027dcdfdf4f27fafb5aa7da398cae981b8afe6d9b9a4fbd8d257a411e55"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1546214086, // * UNIX timestamp of last checkpoint block
    301,      // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1546202840,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1545453420,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x3f;
        pchMessageStart[1] = 0x39;
        pchMessageStart[2] = 0xe9;
        pchMessageStart[3] = 0x08;
        vAlertPubKey = ParseHex("044102bad584e559c38ad8be50484b570d77a58251ff078eb2c75e57a9d60966c1e4b1c63df646db583612111fc413a4d8ca327f37525e27b12bde03f56d1d50e2");
        nDefaultPort = 18878;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Umbra starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 99999999;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 120;
        nTargetSpacing = 120;
        nMaturity = 30;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 25000000 * COIN;

        nLastPOWBlock = 400;
        nModifierUpdateBlock = 999999999;
        nZerocoinStartHeight = 5120000;
        nAccumulatorStartHeight = 1;
        nZerocoinStartTime = 1545453420;
        nBlockEnforceSerialRange = 1;
        nBlockRecalculateAccumulators = ~1;
        nBlockFirstFraudulent = ~1;
        nBlockLastGoodCheckpoint = ~400;
        const char* pszTimestamp = "Elon Musk I want to be clear — I do not respect the SEC Rockets Oranges and David Hasselhoff";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 250 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("044102bad584e559c38ad8be50484b570d77a58251ff078eb2c75e57a9d60966c1e4b1c63df646db583612111fc413a4d8ca327f37525e27b12bde03f56d1d50e2") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1545453420;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 118011;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x983187781fecc3181af6fc5211abbd2feb62e09fadf971970353cf98e6b2fc10"));
        assert(genesis.hashMerkleRoot == uint256("0xe5b9c9a658a89f8a7af6b01443045f7423345fb3ab17dc3436335a98a3fec70b"));

        vSeeds.push_back(CDNSSeedData("207.148.21.185", "207.148.21.185"));
        vSeeds.push_back(CDNSSeedData("45.77.167.240", "45.77.167.240"));
        vSeeds.push_back(CDNSSeedData("149.28.207.68", "149.28.207.68 "));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 68); // U
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 50); // N
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 25); // B
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x2e)(0x21)(0x71).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x08)(0x25)(0x39)(0x2F).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0xbc).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = false;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "042feb9a8e026467a8316c1f140440af99e4b5fdbb6949eea83e8eae76ab82bc91d63ffb857938aad23d2cc949dbc6bc1ab1661f7501f2ddeddacd307774e6dd50" ;
        strObfuscationPoolDummyAddress = "UX11LPuyMfnEHBW71v7LRraw95SFZLfjQJ";
        nStartMasternodePayments = 1545453420;

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * ZCENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x35;
        pchMessageStart[1] = 0xc8;
        pchMessageStart[2] = 0x8d;
        pchMessageStart[3] = 0xc5;
        vAlertPubKey = ParseHex("0405b9b540363a2d702bc33095753cf026f27b69600ab7ce0c1fe16da645fd4c662e4dc8dd608b78b6c3130722dd29c3f4e26099b53f36d4a5a902f401bf344ecf");
        nDefaultPort = 88877;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Umbra: 1 day
        nTargetSpacing = 1 * 60;  // Umbra: 1 minute
        nLastPOWBlock = 50;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197;
        nMaxMoneyOut = 50000000 * COIN;
        nZerocoinStartHeight = 1;
        nZerocoinStartTime = 1545453419;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 0; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 0; //Last valid accumulator checkpoint

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1546202840;
        genesis.nNonce = 29;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0cf8ee76af1e7ce3340e88b5ce3fc6d72a8ffa1ed4a274c6731291a3daebae0f"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("127.0.0.1", "127.0.0.1"));
	vSeeds.push_back(CDNSSeedData("127.0.0.1", "127.0.0.1"));


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet umbra addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet umbra script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet umbra BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet umbra BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet umbra BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = false;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "0405b9b540363a2d702bc33095753cf026f27b69600ab7ce0c1fe16da645fd4c662e4dc8dd608b78b6c3130722dd29c3f4e26099b53f36d4a5a902f401bf344ecf";
        strObfuscationPoolDummyAddress = "xp87cG8UEQgzs1Bk67Yk884C7pnQfAeo7q";
        nStartMasternodePayments = 1545453421; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x34;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0x92;
        pchMessageStart[3] = 0xb7;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Umbra: 1 day
        nTargetSpacing = 1 * 60;        // Umbra: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1545453421;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 732084;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18879;
        //assert(hashGenesisBlock == uint256("0x000008415bdca132b70cf161ecc548e5d0150fd6634a381ee2e99bb8bb77dbb3"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18878;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
