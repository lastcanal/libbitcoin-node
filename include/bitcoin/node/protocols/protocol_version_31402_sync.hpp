/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NODE_PROTOCOL_VERSION_31402_SYNC_HPP
#define LIBBITCOIN_NODE_PROTOCOL_VERSION_31402_SYNC_HPP

#include <cstdint>
#include <memory>
#include <bitcoin/network.hpp>
#include <bitcoin/node/define.hpp>

namespace libbitcoin {
namespace node {

class BCN_API protocol_version_31402_sync
  : public network::protocol_version_31402
{
public:
    typedef std::shared_ptr<protocol_version_31402_sync> ptr;

    /// Construct a quiet version protocol instance.
    protocol_version_31402_sync(network::p2p& network,
        network::channel::ptr channel, uint32_t minimum_version,
        uint64_t minimum_services);

protected:
    /// Overridden to disable services.
    void send_version(const message::version& self) override;
};

} // namespace node
} // namespace libbitcoin

#endif