/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugFuncions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:14:04 by bde-souz          #+#    #+#             */
/*   Updated: 2025/03/12 14:45:54 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ircserv.hpp"

void Ircserv::debugShowChannelsInfo()
{
	std::vector<channelsStruct>::const_iterator channel = _channels.begin();

	if (channel != _channels.end())
	{
		for (std::vector<channelsStruct>::const_iterator channel = _channels.begin(); channel != _channels.end(); ++channel)
		{
			std::cout << cyan << "-- Start of Channel -- " << "\n" << reset;

			std::cout << "Channel: " << channel->_channelName << std::endl;
			std::cout << "Channel Topic: " << channel->_channelTopic << std::endl;
			std::cout << "Channel is Private: " << channel->_isPrivate << std::endl;
			std::cout << "Clients Fd who can join: ";
			for (std::vector<int>::const_iterator fd = channel->_clientsFdInvite.begin(); \
				fd != channel->_clientsFdInvite.end(); ++fd)
			{
				std::cout << *fd << " - ";
			}
			std::cout << "\nChannel Limit: " << channel->_maxUsers << "\n";
			std::cout << "\n";
			std::cout << yellow << "-- Start Clients --" << "\n" << reset;
			for (std::vector<Client>::const_iterator clients = channel->_clients.begin(); \
				clients != channel->_clients.end(); ++clients)
			{
				std::cout << "Client FD: " << clients->_fd << "\n";
				std::cout << "Client Nick: " << clients->_nickName << "\n";
				std::cout << yellow << "-- Next --" << "\n" << reset;
			}

			std::cout << cyan << "-- End of Channel -- " << "\n";
		}
	}
	else
	{
		std::cout << red << "No Channels to show" << "\n" << reset;
	}
}

void Ircserv::debugShowLastClient(void)
{
	std::map<int, Client>::const_iterator it = _clientsMap.end();
	it--;
	std::cout << "fd: " << it->first << "\n";
	std::cout << "Nick Name: " << it->second._nickName << "\n";
	std::cout << "User Name: " << it->second._userName << "\n";
	std::cout << "Real Name: " << it->second._realName << "\n";
}

void Ircserv::debugShowAllClients(void)
{
	std::cout << cyan << "SHOWING ALL CLIENTS: " << "\n" << reset;
	for (std::map<int, Client>::const_iterator it = _clientsMap.begin(); it != _clientsMap.end(); ++it)
	{
		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "START OF CLIENT" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		std::cout << "fd: " << it->first << "\n";
		std::cout << "Nick Name: " << it->second._nickName << "\n";
		std::cout << "User Name: " << it->second._userName << "\n";
		std::cout << "Real Name: " << it->second._realName << "\n";
		std::cout << "isFirstTime: " << it->second.isFirstTime << "\n";
		std::cout << "HasPass: " << it->second.hasPass << "\n";
		std::cout << "hasNick: " << it->second.hasNick << "\n";
		std::cout << "HasUser: " << it->second.hasUser << "\n";

		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "END OF CLIENT" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	}
	std::cout << cyan << "END OF CLIENTS DEBUG!" << "\n" << reset;
}

void Ircserv::debugShowSpecificClient(Client client)
{
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "START OF CLIENT" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	std::cout << "fd: " << client._fd << "\n";
	std::cout << "Nick Name: " << client._nickName << "\n";
	std::cout << "User Name: " << client._userName << "\n";
	std::cout << "Real Name: " << client._realName << "\n";
	std::cout << "IsFirstTIme: " << client.isFirstTime << "\n";
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "END OF CLIENT" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;

}
