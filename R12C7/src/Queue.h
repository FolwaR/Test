/*
 * Queue.h
 *
 *  Created on: 20 lip 2017
 *      Author: £ukasz
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <string>

namespace QUEUE
{


	class queue
	{
		private:
		const int max_elements;

		static int no_of_nodes;
		struct node
		{
			std::string name;
			node *next_node;
		};

		node *root;
		node *last;
		const int qsize = 10;

		public:
		queue(int);
		queue();
		~queue();

		bool is_empty() const;
		bool is_full() const;
		bool enqueue(const node &node);
		bool dequeue(node &node);
		static int how_many();

	};
}
#endif  /*end QUEUE namespace */
